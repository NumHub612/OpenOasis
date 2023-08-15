# -*- encoding: utf-8 -*-
"""
ReLU activation function.

__author__ = 'Qin zhaoyu'
"""
from ABCActivator import Activation
import numpy as np


class ReLU(Activation):
    """ReLU activation function."""

    def func(self, x):
        return np.maximum(x, 0.0)

    def derivative(self, x):
        return x > 0.0
