# -*- encoding: utf-8 -*-
"""
RNN layer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
import numpy as np
from .ABCLayer import Layer
from ..utils.LayerInitializer import Zeros, XavierUniform
from ..utils.math import empty


class RNN(Layer):
    def __init__(self, num_hidden, w_init=XavierUniform(), b_init=Zeros()):
        super().__init__()
        self.n_h = num_hidden
        self.initializers = {"W": w_init, "b": b_init}

    def forward(self, inputs):
        batch_size, n_ts, input_dim = inputs.shape
        if not self.is_init:
            self.shapes = {"W": [self.n_h, self.n_h + input_dim], "b": [self.n_h]}
            self._init_params()

        a = empty((batch_size, n_ts, self.n_h))
        h = empty((batch_size, n_ts + 1, self.n_h))

        h[:, -1] = 0.0
        for t in range(n_ts):
            z = np.hstack([h[:, t - 1], inputs[:, t]])
            a[:, t] = z @ self.params["W"].T + self.params["b"]
            h[:, t] = np.tanh(a[:, t])
        self.ctx = {"h": h, "X": inputs}
        return h[:, -2]

    def backward(self, grad):
        n_ts = self.ctx["X"].shape[1]
        for p in self.param_names:
            self.grads[p] = np.zeros_like(self.params[p])

        d_in = np.empty_like(self.ctx["X"], dtype=np.float32)
        d_h = grad
        for t in reversed(range(n_ts)):
            d_a = d_h * (1 - self.ctx["h"][:, t] ** 2)
            d_in[:, t] = d_a @ self.params["W"][:, self.n_h :]
            self.grads["W"][:, self.n_h :] += d_a.T @ self.ctx["X"][:, t]
            self.grads["W"][:, : self.n_h] += d_a.T @ self.ctx["h"][:, t - 1]
            self.grads["b"] += d_a.sum(axis=0)
            d_h = d_a @ self.params["W"][:, : self.n_h]
        return d_in

    @property
    def param_names(self):
        return "W", "b"
