# -*- encoding: utf-8 -*-
"""
A dense layer operates `outputs = dot(intputs, weight) + bias`.
"""
import numpy as np
from .ABCLayer import Layer
from ..utils.LayerInitializer import Zeros, XavierUniform


class Dense(Layer):
    """A dense layer operates `outputs = dot(intputs, weight) + bias`.

    :param num_out: A positive integer, number of output neurons.
    :param w_init: Weight initializer.
    :param b_init: Bias initializer.
    """

    def __init__(self, num_out: int, w_init=XavierUniform(), b_init=Zeros()):
        super().__init__()

        self.initializers = {"w": w_init, "b": b_init}
        self.shapes = {"w": [None, num_out], "b": [num_out]}

    def forward(self, inputs: np.ndarray) -> np.ndarray:
        # Run operates `outputs = dot(intputs, weight) + bias`.
        if not self.is_init:
            self.shapes["w"][0] = inputs.shape[1]
            self._init_params()
        self.ctx = {"X": inputs}
        return inputs @ self.params["w"] + self.params["b"]

    def backward(self, grad: np.ndarray) -> np.ndarray:
        # Calculates the gradients of the parameters w, b,
        # and the input,
        # and returns the gradient of the input.
        self.grads["w"] = self.ctx["X"].T @ grad
        self.grads["b"] = np.sum(grad, axis=0)
        return grad @ self.params["w"].T

    @property
    def param_names(self):
        """Returns the names of the parameters."""
        return "w", "b"
