# -*- encoding: utf-8 -*-
import os
import sys
from pathlib import Path

current_folder = Path(__file__).absolute().parent
os.chdir(str(current_folder))
father_folder = str(current_folder.parent)
sys.path.append(father_folder)

import time
import unittest
import numpy as np

from Spark.model import Model
from Spark.net import Net
from Spark.layers import Dense, ReLU
from Spark.loss import SoftmaxCrossEntropy
from Spark.optimizer import Adam
from Spark.utils import random_seed, MNIST, BatchIterator, accuracy


class TestSpark(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print(f"\n---------- Test {cls.__name__} \n")

    @classmethod
    def tearDownClass(cls):
        print("\n---------- Done \n")

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def testWorkFlow(self):
        """test hippo for mnist dataset."""
        # set random seed.
        random_seed(42)

        # prepare dataset.
        curr_dir = os.path.dirname(os.path.abspath(__file__))
        data_dir = os.path.join(curr_dir, "results")
        model_dir = os.path.join(curr_dir, "results")

        mnist = MNIST(data_dir, one_hot=True)
        train_x, train_y = mnist.train_set
        test_x, test_y = mnist.test_set

        # define a multilayer perceptron net.
        net = Net(
            [
                Dense(200),
                ReLU(),
                Dense(100),
                ReLU(),
                Dense(70),
                ReLU(),
                Dense(30),
                ReLU(),
                Dense(10),
            ]
        )

        # compile a model.
        model = Model(net=net, loss=SoftmaxCrossEntropy(), optimizer=Adam(0.0001))

        # train.
        iterator = BatchIterator(batch_size=128)
        for epoch in range(10):
            t_start = time.time()
            # trainning in each episode.
            for batch in iterator(train_x, train_y):
                pred = model.forward(batch.inputs)
                loss, grads = model.backward(pred, batch.targets)
                model.update(grads)

            print(f"Epoch {epoch} time cost: {time.time() - t_start}")

            # evaluate every epoch
            self._evaluate(model, test_x, test_y)

        # save model.
        if not os.path.isdir(model_dir):
            os.makedirs(model_dir)
        model_name = f"mnist-mlp-epoch10.pkl"
        model_path = os.path.join(model_dir, model_name)
        model.save(model_path)
        print(f"Model saved in {model_path}")

    def _evaluate(self, model, test_x, test_y):
        """evaluate model result."""
        model.is_training = False
        test_pred = model.forward(test_x)
        test_pred_idx = np.argmax(test_pred, axis=1)
        test_y_idx = np.argmax(test_y, axis=1)
        acc, info = accuracy(test_pred_idx, test_y_idx)
        model.is_training = True
        print(f"accuracy: {acc:.4f} info: {info}")


if __name__ == "__main__":
    with open("./reports/spark-report.txt", "w", encoding="utf8") as reporter:
        # 方式一：一次加载整个测试类
        # suit = unittest.makeSuite(TestSpark)

        # 方式二：逐次加载测试用例
        suit = unittest.TestSuite()
        suit.addTest(TestSpark("testWorkFlow"))

        # 执行测试
        runner = unittest.TextTestRunner(stream=reporter, verbosity=2)
        runner.run(suit)
