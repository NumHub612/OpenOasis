# -*- encoding: utf-8 -*-
"""
Abstract model for a space that is used for the state and action spaces. 

Each action space defines the set of actions an agent can perform, and 
each state space defines the set of all possible states in the `env`. 
Space can be either continuous or discrete.
"""
from abc import abstractmethod, ABCMeta


class Space(metaclass=ABCMeta):
    """Basic class for all spaces."""

    @abstractmethod
    def sample(self, seed):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def contains(self, x):
        """ """
        raise NotImplementedError()
