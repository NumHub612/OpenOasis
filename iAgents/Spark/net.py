# -*- encoding: utf-8 -*-
"""
The `Net` component manages the forward and backpropagation of tensor between layers,
and provides interfaces for obtaining parameters, 
setting parameters, and obtaining gradients.
"""
import copy
import numpy as np
from Spark.utils.StructuredParam import StructuredParam


class Net:
    """Feed-forward Neural Network class.

    :param layers: a list of `Layer` objects, in the order they should be connected.
    """

    def __init__(self, layers: list):
        self.layers = layers
        self._is_training = True

    def __repr__(self):
        return "\n".join([str(layer) for layer in self.layers])

    def forward(self, inputs: np.ndarray) -> np.ndarray:
        """Forward propagation traverses  all layers sequentially,
        with the output of each layer calculated
        as the input to the next layer.

        :param inputs: input tensor to the network.
        :return: result tensor of the network.
        """
        for layer in self.layers:
            inputs = layer.forward(inputs)
        return inputs

    def backward(self, grad: np.ndarray) -> StructuredParam:
        """Back propagation traverses all layers in reverse order,
        using the gradient of each layer as input to the next.

        :param grad: gradient tensor of the network.
        :return: structured gradients.
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
        """Returns a structured parameter object containing the trainable and non-trainable
        parameters of all layers in the network.
        """
        trainable = [layer.params for layer in self.layers]
        non_trainable = [layer.nt_params for layer in self.layers]
        return StructuredParam(trainable, non_trainable)

    @params.setter
    def params(self, params):
        self.params.values = params.values
        self.params.nt_values = params.nt_values

    @property
    def is_training(self):
        """Whether the network is in training mode or not."""
        return self._is_training

    @is_training.setter
    def is_training(self, is_training):
        for layer in self.layers:
            layer.is_training = is_training
        self._is_training = is_training
