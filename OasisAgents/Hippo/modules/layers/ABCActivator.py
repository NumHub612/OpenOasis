# -*- encoding: utf-8 -*-
"""
A activation layer in a neural net is responsible for providing 
the nonlinear representation of the model.

__author__ = 'Qin zhaoyu'
"""
from ABCLayer import Layer
from abc import abstractmethod


class Activation(Layer):
    """Basic activation layer in a neural net."""

    def __init__(self):
        super().__init__()
        self.inputs = None

    def forward(self, inputs):
        self.ctx["X"] = inputs
        return self.func(inputs)

    def backward(self, grad):
        return self.derivative(self.ctx["X"]) * grad

    @abstractmethod
    def func(self, x):
        """Activation function.

        :param x: input
        :return: output
        """
        raise NotImplementedError

    @abstractmethod
    def derivative(self, x):
        """Derivative of activation function.

        :param x: input
        :return: output
        """
        raise NotImplementedError
