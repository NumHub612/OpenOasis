# -*- encoding: utf-8 -*-
"""
A optimizer in a neural net is responsible for updating the parameters of the model 
using gradients.

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta


class Optimizer(ABCMeta):
    """Base class for optimizers."""

    def __init__(self, lr, weight_decay):
        super().__init__()
        # learning rate and weight decay
        self.lr = lr
        self.weight_decay = weight_decay

    def step(self, grads, params):
        """Calculate the gradient of the actual optimization and use it to
        update the parameters,
        according to the input parameters gradients.

        :param grads: The gradient of the input parameters.
        :param params: The parameters to be udpated.
        """
        # compute the gradient step
        grads = self._compute_step(grads)
        # apply weight_decay if specified
        if self.weight_decay:
            grads -= self.lr * self.weight_decay * params
        # take a step
        params += grads

    @abstractmethod
    def _compute_step(self, grads):
        """Calculate the step size of each parameter change when
        returning the actual optimization,
        based on the current gradient.

        :param grads: The current gradient
        :return: The step size of each parameter change.
        """
        raise NotImplementedError
