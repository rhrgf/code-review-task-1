#coding=utf-8

import collections
import os

words=[]
with open('input.txt') as f:
    for line in f:
        words+=line.strip().split(' ')

words_count =  collections.Counter(words)
with open('output.txt','w') as f:
    for (key,value) in sorted(words_count.items(),key=lambda x:x[1],reverse=True):
        f.write(key+" "+str(value)+"\n")
        print(key+" "+str(value)+"\n")
