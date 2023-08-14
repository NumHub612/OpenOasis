# -*- encoding: utf-8 -*-
"""
description

__author__ = 'Qin zhaoyu'
"""
from abc import abstractmethod, ABCMeta


class Space(ABCMeta):
    """Basic class for all spaces."""

    @abstractmethod
    def sample(self, seed):
        """ """
        raise NotImplementedError()

    @abstractmethod
    def contains(self, x):
        """ """
        raise NotImplementedError()
