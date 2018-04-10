#coding=utf-8

import collections
import os

words=[]
with open('input.txt') as f:
    for line in f:
        words+=line.strip().split(' ')

words_count =  collections.Counter(words)
words_count = sorted(words_count.items(),key=lambda x:x[1],reverse=True)
with open('output.txt','w') as f:
    for (key,value) in words_count:
        f.write(key+" "+str(value)+"\n")
        print(key+" "+str(value)+"\n")
