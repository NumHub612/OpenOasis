# -*- encoding: utf-8 -*-
"""
Adam optimizer.
"""
from .ABCOptimizer import Optimizer


class Adam(Optimizer):
    """Adam optimizer."""

    def __init__(
        self, lr=0.001, beta1=0.9, beta2=0.999, epsilon=1e-8, weight_decay=0.0
    ):
        """
        :param lr: Learning rate.
        :param beta1: Exponential decay rate for the first moment estimates.
        :param beta2: Exponential decay rate for the second moment estimates.
        :param epsilon: Small value to avoid zero division.
        :param weight_decay: Weight decay factor.
        """
        super().__init__(lr, weight_decay)
        self._b1 = beta1
        self._b2 = beta2
        self._epsilon = epsilon

        self._t = 0
        self._m = 0
        self._v = 0

    def _compute_step(self, grads):
        self._t += 1

        self._m += (1.0 - self._b1) * (grads - self._m)
        self._v += (1.0 - self._b2) * (grads**2 - self._v)

        # bias correction
        _m = self._m / (1 - self._b1**self._t)
        _v = self._v / (1 - self._b2**self._t)

        step = -self.lr * _m / (_v**0.5 + self._epsilon)
        return step
