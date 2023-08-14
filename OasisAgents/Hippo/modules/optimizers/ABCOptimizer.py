# -*- encoding: utf-8 -*-
"""
description

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta


class Optimizer(ABCMeta):
    """Base class for optimizers."""

    def __init__(self, lr, weight_decay):
        """
        :param lr:
        :param weight_decay:
        """
        super().__init__()
        # learning rate and weight decay
        self.lr = lr
        self.weight_decay = weight_decay

    def step(self, grads, params):
        """
        :param grads:
        :param params:
        :return:
        """
        # compute the gradient step
        grads = self.compute_step(grads)
        # apply weight_decay if specified
        if self.weight_decay:
            grads -= self.lr * self.weight_decay * params
        # take a step
        params += grads

    @abstractmethod
    def compute_step(self, grads):
        """
        :param grads:
        :return:
        """
        raise NotImplementedError
