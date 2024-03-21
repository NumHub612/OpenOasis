# -*- encoding: utf-8 -*-
"""
Common datasets
"""
import os
import gzip
import pickle
import numpy as np

from Spark.utils.downloader import download_url


class Dataset:
    """Basic dataset class."""

    def __init__(self, data_dir, **kwargs):
        self._train_set = None
        self._valid_set = None
        self._test_set = None

        self._save_paths = [
            os.path.join(data_dir, url.split("/")[-1]) for url in self._urls
        ]

        self._download()
        self._parse(**kwargs)  # lgtm [py/init-calls-subclass]

    def _download(self):
        for url, checksum, save_path in zip(
            self._urls, self._checksums, self._save_paths
        ):
            download_url(url, save_path, checksum)

    def _parse(self, **kwargs):
        raise NotImplementedError

    @property
    def train_set(self):
        return self._train_set

    @property
    def valid_set(self):
        return self._valid_set

    @property
    def test_set(self):
        return self._test_set

    @staticmethod
    def one_hot(targets, n_classes):
        return np.eye(n_classes, dtype=np.float32)[np.array(targets).reshape(-1)]


class MNIST(Dataset):
    """MNIST dataset."""

    def __init__(self, data_dir, one_hot=True):
        self._urls = (
            "https://raw.githubusercontent.com/mnielsen/neural-networks-and-deep-learning/master/data/mnist.pkl.gz",
        )
        self._checksums = ("98100ca27dc0e07ddd9f822cf9d244db",)
        self._n_classes = 10
        super().__init__(data_dir, one_hot=one_hot)

    def _parse(self, **kwargs):
        save_path = self._save_paths[0]
        with gzip.open(save_path, "rb") as f:
            train, valid, test = pickle.load(f, encoding="latin1")

        if kwargs["one_hot"]:
            train = (train[0], self.one_hot(train[1], self._n_classes))
            valid = (valid[0], self.one_hot(valid[1], self._n_classes))
            test = (test[0], self.one_hot(test[1], self._n_classes))

        self._train_set, self._valid_set, self._test_set = train, valid, test
