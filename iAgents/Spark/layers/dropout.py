# -*- encoding: utf-8 -*-
"""
Dropout layer.
"""
import numpy as np
from .ABCLayer import Layer


class Dropout(Layer):
    def __init__(self, keep_prob=0.5):
        super().__init__()
        self._keep_prob = keep_prob
        self._multiplier = None

    def forward(self, inputs):
        if self.is_training:
            multiplier = np.random.binomial(1, self._keep_prob, inputs.shape)
            self._multiplier = multiplier / self._keep_prob
            outputs = inputs * self._multiplier
        else:
            outputs = inputs
        return outputs

    def backward(self, grad):
        assert self.is_training is True
        return grad * self._multiplier
