import unittest
from count_words import CountWords
from nltk import FreqDist

class TestCountWords(unittest.TestCase):

    def test_init_with_config(self):
        cw = CountWords(config_file = "config.json")
        self.assertEqual(cw.config_file, "config.json")
        self.assertEqual(cw.words_files, ["words.txt"])

    def test_init_without_config(self):
        cw = CountWords()
        self.assertEqual(cw.config_file, "")        
        self.assertEqual(cw.words_files, ["words.txt"])

    def test_load_config_with_config(self):
        cw = CountWords(config_file = "config.json")
        words_files = cw.load_config()
        self.assertEqual(words_files, ["./words.txt", "./words2.txt"])
        self.assertEqual(cw.words_files, ["./words.txt", "./words2.txt"])

    def test_load_config_without_config(self):
        cw = CountWords()
        words_files = cw.load_config()
        self.assertEqual(words_files, ["words.txt"])
        self.assertEqual(cw.words_files, ["words.txt"])

    def test_read_file_with_one_file(self):
        cw = CountWords()
        text = cw.read_file()
        self.assertEqual(text, ["the day is sunny the the\nthe sunny is is"])
        self.assertEqual(cw.text, ["the day is sunny the the\nthe sunny is is"])

    def test_read_file_with_multiple_file(self):
        cw = CountWords()
        cw.words_files = ["./words.txt", "./words2.txt"]
        text = cw.read_file()
        self.assertEqual(text, ["the day is sunny the the\nthe sunny is is", "hello world is is  a\ngood"])
        self.assertEqual(cw.text, ["the day is sunny the the\nthe sunny is is", "hello world is is  a\ngood"])

    def test_count_with_text(self):
        cw = CountWords()
        text = ["the day is sunny the the\nthe sunny is is"]
        fredist = cw.count_words(text)
        self.assertEqual(fredist, FreqDist({'the': 4, 'is': 3, 'sunny': 2, 'day': 1}))
        self.assertEqual(cw.fredist, FreqDist({'the': 4, 'is': 3, 'sunny': 2, 'day': 1}))

    def test_count_with_self_text(self):
        cw = CountWords()
        cw.text = ["the day is sunny the the\nthe sunny is is"]
        fredist = cw.count_words()
        self.assertEqual(fredist, FreqDist({'the': 4, 'is': 3, 'sunny': 2, 'day': 1}))
        self.assertEqual(cw.fredist, FreqDist({'the': 4, 'is': 3, 'sunny': 2, 'day': 1}))

    def test_count_with_multiple_text(self):
        cw = CountWords()
        cw.text = ["the day is sunny the the\nthe sunny is is", "hello world is is  a\ngood"]
        fredist = cw.count_words()
        self.assertEqual(fredist, FreqDist({'is': 5, 'the': 4, 'sunny': 2, 'day': 1, 'hello': 1, 'world': 1, 'a' : 1, 'good': 1}))
        self.assertEqual(cw.fredist, FreqDist({'is': 5, 'the': 4, 'sunny': 2, 'day': 1, 'hello': 1, 'world': 1, 'a' : 1, 'good': 1}))        

    def test_print_count(self):
        pass

if __name__ == '__main__':
    unittest.main()
