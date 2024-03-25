# -*- encoding: utf-8 -*-
"""
Reshape layer.
"""
from .ABCLayer import Layer


class Reshape(Layer):
    def __init__(self, *output_shape):
        super().__init__()
        self.output_shape = output_shape
        self.input_shape = None

    def forward(self, inputs):
        self.input_shape = inputs.shape
        return inputs.reshape(inputs.shape[0], *self.output_shape)

    def backward(self, grad):
        return grad.reshape(self.input_shape)


class Flatten(Reshape):
    def __init__(self):
        super().__init__(-1)
