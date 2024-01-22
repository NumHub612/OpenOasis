# -*- encoding: utf-8 -*-
"""
Numpy random seeder.

__author__ = 'Qin zhaoyu'
"""
import numpy as np


def random_seed(seed):
    """Numpy random seeder."""
    seed = int(seed)
    if seed < 0 or seed > (2**32 - 1):
        raise ValueError("Seed must be between 0 and 2**32 - 1")
    np.random.seed(seed)
