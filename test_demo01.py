import pytest
from demo01 import *

def test_count_words():
    text = "the day is sunny the the\nthe sunny is is\n"
    result = [('the', 4), ('is', 3), ('sunny', 2), ('day', 1)]
    assert count_words(text.split())==result


