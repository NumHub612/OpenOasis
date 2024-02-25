# -*- encoding: utf-8 -*-
"""
LSTM layer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
import numpy as np
from .ABCLayer import Layer
from ...utils.LayerInitializer import Zeros, XavierUniform
from ...utils.math import sigmoid, empty


class LSTM(Layer):
    def __init__(self, num_hidden, w_init=XavierUniform(), b_init=Zeros()):
        super().__init__()
        self.n_h = num_hidden
        self.initializers = {"W_g": w_init, "W_c": w_init, "b_g": b_init, "b_c": b_init}

    def forward(self, inputs):
        batch_size, n_ts, input_dim = inputs.shape
        if not self.is_init:
            self.shapes = {
                "W_g": [3 * self.n_h, input_dim + self.n_h],
                "b_g": [3 * self.n_h],
                "W_c": [self.n_h, input_dim + self.n_h],
                "b_c": [self.n_h],
            }
            self._init_params()

        h = empty((batch_size, n_ts + 1, self.n_h))
        h[:, -1] = 0.0
        c = empty((batch_size, n_ts + 1, self.n_h))
        c[:, -1] = 0.0
        gates = empty((batch_size, n_ts, 3 * self.n_h))
        c_hat = empty((batch_size, n_ts + 1, self.n_h))

        for t in range(n_ts):
            z = np.hstack([h[:, t - 1], inputs[:, t]])

            gates[:, t] = sigmoid(z @ self.params["W_g"].T + self.params["b_g"])
            o_gate, i_gate, f_gate = np.split(gates[:, t], 3, axis=1)

            c_hat[:, t] = np.tanh(z @ self.params["W_c"].T + self.params["b_c"])

            c[:, t] = f_gate * c[:, t - 1] + i_gate * c_hat[:, t]
            h[:, t] = o_gate * np.tanh(c[:, t])

        self.ctx = {"h": h, "c": c, "X": inputs, "gates": gates, "c_hat": c_hat}
        return h[:, -2]

    def backward(self, grad):
        for p in self.param_names:
            self.grads[p] = np.zeros_like(self.params[p])

        _, n_ts, input_dim = self.ctx["X"].shape

        d_in = np.empty_like(self.ctx["X"], dtype=np.float32)
        d_c_prev = 0
        d_h_prev = grad
        for t in reversed(range(n_ts)):
            z = np.hstack([self.ctx["h"][:, t - 1], self.ctx["X"][:, t]])
            tanhc = np.tanh(self.ctx["c"][:, t])

            g_o, g_i, g_f = np.split(self.ctx["gates"][:, t], 3, axis=1)

            d_h = d_h_prev
            d_o = d_h * tanhc
            d_a_o = d_o * g_o * (1 - g_o)

            self.grads["W_g"][: self.n_h] += d_a_o.T @ z
            self.grads["b_g"][: self.n_h] += d_a_o.sum(axis=0)

            d_c = d_h * g_o * (1 - tanhc**2)
            d_c += d_c_prev

            d_c_hat = d_c * g_i
            d_a_c = d_c_hat * (1 - self.ctx["c_hat"][:, t] ** 2)
            self.grads["W_c"] += d_a_c.T @ z
            self.grads["b_c"] += d_a_c.sum(axis=0)

            d_i = d_c * self.ctx["c_hat"][:, t]
            d_a_i = d_i * g_i * (1 - g_i)
            self.grads["W_g"][self.n_h : 2 * self.n_h] += d_a_i.T @ z
            self.grads["b_g"][self.n_h : 2 * self.n_h] += d_a_i.sum(axis=0)

            d_f = d_c * self.ctx["c"][:, t - 1]
            d_a_f = d_f * g_f * (1 - g_f)
            self.grads["W_g"][-self.n_h :] += d_a_f.T @ z
            self.grads["b_g"][-self.n_h :] += d_a_f.sum(axis=0)

            d_z = (
                np.hstack([d_a_o, d_a_i, d_a_f]) @ self.params["W_g"]
                + d_a_c @ self.params["W_c"]
            )
            d_h = d_z[:, : self.n_h]
            d_in[:, t] = d_z[:, -input_dim:]

            d_h_prev = d_h
            d_c_prev = g_f * d_c
        return d_in

    @property
    def param_names(self):
        return "W_g", "b_g", "W_c", "b_c"
