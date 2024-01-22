# -*- encoding: utf-8 -*-
"""
Sigmoid activator layer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
import numpy as np
from .ABCActivator import Activation
from ...utils.math import sigmoid


class Softplus(Activation):
    def func(self, x):
        return np.log(1.0 + np.exp(-np.abs(x))) + np.maximum(x, 0.0)

    def derivative(self, x):
        return sigmoid(x)
