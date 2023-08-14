# -*- encoding: utf-8 -*-
"""
description

__author__ = 'Qin zhaoyu'
"""


class Net:
    """Feed-forward Neural Network class."""

    def __init__(self, layers):
        self.layers = layers
        self._is_training = True

    def __repr__(self):
        return "\n".join([str(layer) for layer in self.layers])
