# -*- encoding: utf-8 -*-
"""
Mean Absolute Error loss function.
"""
import numpy as np
from .ABCLoss import Loss


class MAE(Loss):
    """Mean Absolute Error loss function."""

    def loss(self, predictions, targets):
        return np.sum(np.abs(predictions - targets)) / targets.shape[0]

    def grad(self, predictions, targets):
        return np.sign(predictions - targets) / targets.shape[0]
