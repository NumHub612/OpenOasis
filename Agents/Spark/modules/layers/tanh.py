# -*- encoding: utf-8 -*-
"""
Tanh activator layer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
import numpy as np
from .ABCActivator import Activation


class Tanh(Activation):
    def func(self, x):
        return np.tanh(x)

    def derivative(self, x):
        return 1.0 - self.func(x) ** 2
