import unittest
from homework import *
class Test(unittest.TestCase):
    def test_read(self):
        input = 'words.txt'
        real_result = ['it been a long day without you my friend and i tell you all about it when I see you again we come a long way from where we began oh I tell you all about it when I see you again when I see you again']
        self.assertEqual(real_result,read(input))
    def test_conut(self):
        input = ['it been a long day without you my friend and i tell you all about it when I see you again we come a long way from where we began oh I tell you all about it when I see you again when I see you again']
        real_result = [('you', 6)
('I', 4)
('it', 3)
('when', 3)
('see', 3)
('again', 3)
('a', 2)
('long', 2)
('tell', 2)
('all', 2)
('about', 2)
('we', 2)
('been', 1)
('day', 1)
('without', 1)
('my', 1)
('friend', 1)
('and', 1)
('i', 1)
('come', 1)
('way', 1)
('from', 1)
('where', 1)
('began', 1)
('oh', 1)]
        self.assertEqual(real_result, count(input))
if __name__ == '__main__':
    unittest.main()