# -*- encoding: utf-8 -*-
"""
description

__author__ = 'Qin zhaoyu'
"""


class Model:
    """Model class manage the network, loss function and optimizer."""

    def __init__(self, net, loss, optimizer):
        self.net = net
        self.loss = loss
        self.optimizer = optimizer
