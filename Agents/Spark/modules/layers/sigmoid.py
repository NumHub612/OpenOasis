# -*- encoding: utf-8 -*-
"""
Sigmoid activator layer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
from .ABCActivator import Activation
from ...utils.math import sigmoid


class Sigmoid(Activation):
    def func(self, x):
        return sigmoid(x)

    def derivative(self, x):
        return self.func(x) * (1.0 - self.func(x))
