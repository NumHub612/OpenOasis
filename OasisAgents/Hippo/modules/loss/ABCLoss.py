# -*- encoding: utf-8 -*-
"""
description

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta


class Loss(ABCMeta):
    """Base class for loss and grads calculation."""

    @abstractmethod
    def loss(self, *args, **kwargs):
        raise NotImplementedError

    @abstractmethod
    def grad(self, *args, **kwargs):
        raise NotImplementedError