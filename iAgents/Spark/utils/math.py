# -*- encoding: utf-8 -*-
"""
Useful math utilities.

__author__ = 'borgwang'
__url__ = https://github.com/borgwang/tinynn
"""
import numpy as np


def softmax(x, t=1.0, axis=-1):
    x_ = x / t
    x_max = np.max(x_, axis=axis, keepdims=True)
    exps = np.exp(x_ - x_max)
    return exps / np.sum(exps, axis=axis, keepdims=True)


def log_softmax(x, t=1.0, axis=-1):
    x_ = x / t
    x_max = np.max(x_, axis=axis, keepdims=True)
    exps = np.exp(x_ - x_max)
    exp_sum = np.sum(exps, axis=axis, keepdims=True)
    return x_ - x_max - np.log(exp_sum)


def sigmoid(x):
    return 1.0 / (1.0 + np.exp(-x))


def empty(shape, dtype=np.float32):
    return np.empty(shape, dtype=dtype)
