import unittest
from countwords import *

class TestCountWords(unittest.TestCase):
    def test_readfile(self):#打开文件的函数要怎么测试啊？
        input='words.txt'
        real_result=['the day is sunny the the\n', 'the sunny is is']
        self.assertEqual(real_result, readfile(input))

    def test_countwords(self):
        input=['the day is sunny the the\n', 'the sunny is is']
        real_result=[('the', 4), ('is', 3), ('sunny', 2), ('day', 1)]
        false_result=[('the', 4), ('day', 1), ('is', 3), ('sunny', 2)]
        self.assertEqual(real_result,countwords(input))
        self.assertNotEqual(false_result,countwords(input))

if __name__=='__main__':
    unittest.main()