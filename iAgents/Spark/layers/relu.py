# -*- encoding: utf-8 -*-
"""
ReLU activation function.
"""
import numpy as np
from .ABCActivator import Activation


class ReLU(Activation):
    """ReLU activation function."""

    def func(self, x):
        return np.maximum(x, 0.0)

    def derivative(self, x):
        return x > 0.0
