# -*- encoding: utf-8 -*-
"""
The abstract environment class that is used by all agents. 

Each `env` is a simulation of the agent's interaction with the outside world. It defines
the state space, action space, reward function, and transition probability. 
It provides feedback on every action of the agent.

To implement your own environment, you need to define the following methods:

- `step`
- `reset`
- `render`
- `close`

Refer to the [Gym documentation](https://gym.openai.com/docs/#environments).

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta
import numpy as np


class Env(metaclass=ABCMeta):
    """Basic class for all environments."""

    reward_range = (-np.inf, np.inf)
    action_space = None
    observation_space = None

    @abstractmethod
    def step(self, action):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def reset(self):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def close(self):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def render(self, mode, close):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def seed(self, seed):
        """设"""
        raise NotImplementedError()

    @abstractmethod
    def setup(self, *args, **kwargs):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def load(filepath):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def save(self, filepath, overwrite):
        """ """
        raise NotImplementedError()

    @property
    def states(self):
        """ """
        raise NotImplementedError()

    @property
    def layers(self):
        """ """
        raise NotImplementedError()

    @property
    def configs(self):
        """ """
        raise NotImplementedError()

    def __del__(self):
        self.close()

    def __str__(self):
        return "<{} instance>".format(type(self).__name__)
