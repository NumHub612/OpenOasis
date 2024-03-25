# -*- encoding: utf-8 -*-
"""
Abstract base class for all implemented agents.

Each agent interacts with the environment (as defined by the `Env` class) by 
first observing the states of the environment. Based on this observation 
the agent changes the environment by performing an action.

Each agent realizes a reinforcement learning algorithm. Since all agents conform to
the same interface, you can use them interchangeably.
To implement your own agent, you should implement the following methods:

- `forward`
- `backward`
- `compile`
- `load_weights`
- `save_weights`
- `layers`
"""
from abc import abstractmethod, ABCMeta


class Agent(metaclass=ABCMeta):
    """Basic class for all agents."""

    def __init__(self, processor=None):
        self.processor = processor
        self.training = False
        self.step = 0

    def get_config(self) -> dict:
        """ """
        return {}

    @abstractmethod
    def compile(self, optimizer, metrics, configs):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def fit(
        self,
        env,
        nb_steps,
        action_repetition,
        callbacks,
        verbose,
        visualize,
        nb_max_start_steps,
        start_step_policy,
        log_interval,
        nb_max_episode_steps,
    ):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def test(
        self,
        env,
        nb_episodes,
        action_repetition,
        callbacks,
        visualize,
        nb_max_episode_steps,
        nb_max_start_steps,
        start_step_policy,
        verbose,
    ):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def reset_states(self):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def forward(self, observation):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def backward(self, reward, terminal):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def load_weights(filepath):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def save_weights(self, filepath, overwrite):
        """ """
        raise NotImplementedError()

    @property
    def layers(self):
        """ """
        raise NotImplementedError()

    @property
    def metrics_names(self):
        """ """
        return []

    @property
    def _on_train_begin(self):
        """ """
        raise NotImplementedError()

    @property
    def _on_train_end(self):
        """ """
        raise NotImplementedError()

    @property
    def _on_test_begin(self):
        """ """
        raise NotImplementedError()

    @property
    def _on_test_end(self):
        """ """
        raise NotImplementedError()
