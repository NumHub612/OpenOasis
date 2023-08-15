# -*- encoding: utf-8 -*-
import os, sys

sys.path.append(os.path.abspath(r"./OasisAgents"))


import unittest

from Hippo import Net, Model
from Hippo.modules import Dense, ReLU, MSE, Adam
from Hippo.utils import StructuredParam


class TestHippo(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print("\n---------- Test start \n")

    @classmethod
    def tearDownClass(cls):
        print("\n---------- Done \n")

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def testWorkFlow(self):
        pass


if __name__ == "__main__":
    with open(
        "./OasisAgents/tests/reports/hippo-report.txt", "w", encoding="utf8"
    ) as reporter:
        # 方式一：一次加载整个测试类
        # suit = unittest.makeSuite(TestHippo)

        # 方式二：逐次加载测试用例
        suit = unittest.TestSuite()
        suit.addTest(TestHippo("testWorkFlow"))

        # 执行测试
        runner = unittest.TextTestRunner(stream=reporter, verbosity=2)
        runner.run(suit)
