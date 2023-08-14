# -*- encoding: utf-8 -*-
"""
A layer in a neural net is responsible for receiving the input of the previous layer, 
performing the operations of the layer, and 
output the results to the next layer.

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta


class Layer(ABCMeta):
    """Base class for layers."""

    def __init__(self):
        self.params = {p: None for p in self.param_names}
        self.nt_params = {p: None for p in self.nt_param_names}
        self.initializers = {}

        self.grads = {}
        self.shapes = {}

        self._is_training = True
        self._is_init = False

        self.ctx = {}

    def __repr__(self):
        shape = None if not self.shapes else self.shapes
        return f"layer: {self.name}\tshape: {shape}"

    def _init_params(self):
        for name in self.param_names:
            self.params[name] = self.initializers[name](self.shapes[name])
        self.is_init = True

    @abstractmethod
    def forward(self, inputs):
        """Network layer forward propagation.
        :param inputs: The input data of the previous layer.
        :return: The results of the layer.
        """
        raise NotImplementedError

    @abstractmethod
    def backward(self, grad):
        """Network layer backward propagation.
        :param grad: The gradient of the previous layer.
        :return: The gradient of the layer.
        """
        raise NotImplementedError

    @property
    def is_init(self):
        return self._is_init

    @is_init.setter
    def is_init(self, is_init):
        self._is_init = is_init
        for name in self.param_names:
            self.shapes[name] = self.params[name].shape

    @property
    def is_training(self):
        return self._is_training

    @is_training.setter
    def is_training(self, is_train):
        self._is_training = is_train

    @property
    def name(self):
        return self.__class__.__name__

    @property
    def param_names(self):
        return ()

    @property
    def nt_param_names(self):
        return ()
