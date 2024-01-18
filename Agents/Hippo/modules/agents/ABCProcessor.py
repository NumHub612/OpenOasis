# -*- encoding: utf-8 -*-
"""
description

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta


class Processor(metaclass=ABCMeta):
    """Basic class for all processors."""

    def process_step(self, observation, reward, done, info):
        """ """
        observation = self.process_observation(observation)
        reward = self.process_reward(reward)
        info = self.process_info(info)
        return observation, reward, done, reward

    @abstractmethod
    def process_observation(self, observation):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def process_reward(self, reward):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def process_info(self, info):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def process_action(self, action):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def process_state_batch(self, batch):
        """ """
        raise NotImplementedError()

    @property
    def metrics(self):
        """ """
        return []

    @property
    def metrics_names(self):
        """ """
        return []
