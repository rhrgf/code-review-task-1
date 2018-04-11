#!/usr/bin/python
# -*- coding: utf-8 -*-

path = 'D:/Python/exercise/words.txt'
with open(path, 'r') as text:
   words = text.read().split()
   print(words)
words_index = set(words)
counts_dict = {index:words.count(index) for index in words_index}
for word in sorted(counts_dict, key=lambda x: counts_dict[x],reverse = True);
    print('{} -- {}'.format(word,counts_dict[word]))