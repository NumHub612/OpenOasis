# -*- encoding: utf-8 -*-
"""
BatchNormalization layer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
import numpy as np
from .ABCLayer import Layer
from ...utils.LayerInitializer import Zeros, Ones


class BatchNormalization(Layer):
    def __init__(
        self, momentum=0.99, gamma_init=Ones(), beta_init=Zeros(), epsilon=1e-5
    ):
        super().__init__()
        self.m = momentum
        self.epsilon = epsilon

        self.initializers = {"gamma": gamma_init, "beta": beta_init}
        self.reduce = None

    def forward(self, inputs):
        # self.reduce = (0,) if inputs.ndim == 2 else (0, 1, 2)
        self.reduce = (0,)
        if not self.is_init:
            for p in self.param_names:
                self.shapes[p] = inputs.shape[-1]
            self._init_params()

        if self.nt_params["r_mean"] is None:
            self.nt_params["r_mean"] = inputs.mean(self.reduce, keepdims=True)
            self.nt_params["r_var"] = inputs.var(self.reduce, keepdims=True)

        if self.is_training:
            mean = inputs.mean(self.reduce, keepdims=True)
            var = inputs.var(self.reduce, keepdims=True)
            self.nt_params["r_mean"] = (
                self.m * self.nt_params["r_mean"] + (1.0 - self.m) * mean
            )
            self.nt_params["r_var"] = (
                self.m * self.nt_params["r_var"] + (1.0 - self.m) * var
            )
        else:
            mean = self.nt_params["r_mean"]
            var = self.nt_params["r_var"]

        # standardize
        X_center = inputs - mean
        std = (var + self.epsilon) ** 0.5
        X_norm = X_center / std
        self.ctx = {"X_norm": X_norm, "std": std, "X_center": X_center}
        return self.params["gamma"] * X_norm + self.params["beta"]

    def backward(self, grad):
        # grads w.r.t. params
        self.grads["gamma"] = (self.ctx["X_norm"] * grad).sum(self.reduce)
        self.grads["beta"] = grad.sum(self.reduce)

        # N = grad.shape[0]
        N = np.prod([grad.shape[d] for d in self.reduce])
        std_inv = 1.0 / self.ctx["std"]
        # grads w.r.t. inputs
        # ref: http://cthorey.github.io./backpropagation/
        d_in = (
            (1.0 / N)
            * self.params["gamma"]
            * std_inv
            * (
                N * grad
                - np.sum(grad, axis=self.reduce, keepdims=True)
                - self.ctx["X_center"]
                * std_inv**2
                * (grad * self.ctx["X_center"]).sum(axis=self.reduce, keepdims=True)
            )
        )
        return d_in

    @property
    def param_names(self):
        return "gamma", "beta"

    @property
    def nt_param_names(self):
        return "r_mean", "r_var"
