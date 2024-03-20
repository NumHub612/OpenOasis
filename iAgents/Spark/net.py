# -*- encoding: utf-8 -*-
"""
The `Net` component manages the forward and backpropagation of tensor between layers,
and provides interfaces for obtaining parameters, 
setting parameters, and obtaining gradients.

__author__ = 'Qin zhaoyu'
"""
import copy
from Spark.utils.StructuredParam import StructuredParam


class Net:
    """Feed-forward Neural Network class."""

    def __init__(self, layers):
        self.layers = layers
        self._is_training = True

    def __repr__(self):
        return "\n".join([str(layer) for layer in self.layers])

    def forward(self, inputs):
        """Forward propagation traverses  all layers sequentially,
        with the output of each layer calculated
        as the input to the next layer.
        """
        for layer in self.layers:
            inputs = layer.forward(inputs)
        return inputs

    def backward(self, grad):
        """Back propagation traverses all layers in reverse order,
        using the gradient of each layer as input to the next.
        """
        # back propagation
        for layer in reversed(self.layers):
            grad = layer.backward(grad)

        # structured gradients
        param_grads = [copy.deepcopy(layer.grads) for layer in self.layers]
        struct_grads = StructuredParam(param_grads)

        # save the gradients w.r.t the input
        struct_grads.wrt_input = grad
        return struct_grads

    @property
    def params(self):
        trainable = [layer.params for layer in self.layers]
        non_trainable = [layer.nt_params for layer in self.layers]
        return StructuredParam(trainable, non_trainable)

    @params.setter
    def params(self, params):
        self.params.values = params.values
        self.params.nt_values = params.nt_values

    @property
    def is_training(self):
        return self._is_training

    @is_training.setter
    def is_training(self, is_training):
        for layer in self.layers:
            layer.is_training = is_training
        self._is_training = is_training
