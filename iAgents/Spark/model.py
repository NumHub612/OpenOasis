# -*- encoding: utf-8 -*-
"""
The `Model` component is responsible for integrating all the components 
to form the entire pipeline.
"""
import pickle
import numpy as np


class Model:
    """Model class manage the network, loss function and optimizer.

    :param net: The network component.
    :param loss: The loss component.
    :param optimizer: The optimizer component.
    """

    def __init__(self, net, loss, optimizer):
        self.net = net
        self.loss = loss
        self.optimizer = optimizer

    def forward(self, inputs: np.ndarray) -> np.ndarray:
        """Drive forward propagation of net components.

        :param inputs: The input tensor to the network.
        :return: The output of the network.
        """
        return self.net.forward(inputs)

    def backward(self, predictions: np.ndarray, targets: np.ndarray) -> tuple:
        """Drive losses component to calculate the losses and gradient,
        and then drives the net component
        to back propagate the gradients.

        :param predictions: The predicted values by the network.
        :param targets: The target values to be predicted.
        :return: The loss and gradients of the network.
        """
        loss = self.loss.loss(predictions, targets)
        grad_from_loss = self.loss.grad(predictions, targets)
        struct_grad = self.net.backward(grad_from_loss)
        return loss, struct_grad

    def update(self, grads: np.ndarray):
        """Drive optimizer component to update the net parameters
        with the gradients.
        """
        params = self.net.params
        self.optimizer.step(grads, params)

    def save(self, path: str):
        """Save the model."""
        with open(path, "wb") as f:
            pickle.dump(self.net.params, f)

    def load(self, path: str):
        """Load the model."""
        with open(path, "rb") as f:
            params = pickle.load(f)

        self.net.params = params
        for layer in self.net.layers:
            layer.is_init = True

    @property
    def is_training(self):
        """Whether the model is in training mode."""
        return self.net.is_training

    @is_training.setter
    def is_training(self, is_training):
        self.net.is_training = is_training
