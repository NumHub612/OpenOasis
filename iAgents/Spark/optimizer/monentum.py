# -*- encoding: utf-8 -*-
"""
Momentum optimizer.
"""
from .ABCOptimizer import Optimizer


class Momentum(Optimizer):
    """Momentum optimizer.
    accumulation = momentum * accumulation + gradient
    variable -= learning_rate * accumulation
    """

    def __init__(self, lr, momentum=0.9, weight_decay=0.0):
        super().__init__(lr, weight_decay)
        self._momentum = momentum
        self._acc = 0

    def _compute_step(self, grads):
        self._acc = self._momentum * self._acc + grads
        step = -self.lr * self._acc
        return step
