# -*- encoding: utf-8 -*-
"""
A loss in a neural net outputs the loss value and the gradient about the last layer
after given the model predicted value and the true value.
"""
from abc import abstractmethod, ABCMeta


class Loss(metaclass=ABCMeta):
    """Base class for loss and grads calculation."""

    @abstractmethod
    def loss(self, *args, **kwargs):
        raise NotImplementedError

    @abstractmethod
    def grad(self, *args, **kwargs):
        raise NotImplementedError
