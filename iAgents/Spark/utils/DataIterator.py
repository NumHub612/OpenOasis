# -*- encoding: utf-8 -*-
"""
Data Iterator class.
"""
from collections import namedtuple
import numpy as np

# Named tuple for batches
Batch = namedtuple("Batch", ["inputs", "targets"])


class BaseIterator:
    """Basic dataset iterator class."""

    def __call__(self, inputs, targets):
        raise NotImplementedError


class BatchIterator(BaseIterator):
    """Dataset iterator for generating batches.

    :param batch_size (int): The batch size.
    :param shuffle (bool): Whether to shuffle the data before each epoch.
    """

    def __init__(self, batch_size=32, shuffle=True):
        self.batch_size = batch_size
        self.shuffle = shuffle

    def __call__(self, inputs: np.ndarray, targets: np.ndarray):
        indices = np.arange(len(inputs))
        if self.shuffle:
            np.random.shuffle(indices)

        starts = np.arange(0, len(inputs), self.batch_size)
        for start in starts:
            end = start + self.batch_size
            batch_inputs = inputs[indices[start:end]]
            batch_targets = targets[indices[start:end]]
            yield Batch(inputs=batch_inputs, targets=batch_targets)
