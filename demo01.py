#coding=utf-8

import collections
import os

with open('text.txt') as f:
    words=f.read().split(' ')

words_count =  collections.Counter(words)
print words_count

