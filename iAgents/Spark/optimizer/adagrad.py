# -*- encoding: utf-8 -*-
"""
Adagrad optimizer.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
from .ABCOptimizer import Optimizer


class Adagrad(Optimizer):
    """AdaGrad optimizer
    accumulation = - (learning_rate / sqrt(G + epsilon)) * gradient
    where G is the element-wise sum of square gradient
    ref: http://www.jmlr.org/papers/volume12/duchi11a/duchi11a.pdf
    """

    def __init__(self, lr, epsilon=1e-8, weight_decay=0.0):
        super().__init__(lr, weight_decay)
        self._g = 0
        self._epsilon = epsilon

    def _compute_step(self, grads):
        self._g += grads**2
        adjust_lr = self.lr / (self._g + self._epsilon) ** 0.5
        step = -adjust_lr * grads
        return step
