# -*- encoding: utf-8 -*-
"""
Mean Squared Error loss function.
"""
import numpy as np
from .ABCLoss import Loss


class MSE(Loss):
    """Mean Squared Error loss function."""

    def loss(self, predictions, targets):
        return 0.5 * np.sum((predictions - targets) ** 2) / targets.shape[0]

    def grad(self, predictions, targets):
        return (predictions - targets) / targets.shape[0]
