
#coding=utf-8
import os
import re
from collections import Counter
words=[]
for fname in os.listdir(os.getcwd()):    #返回指定目录下的所有文件和目录名
    if os.path.isfile(fname) and fname.endswith('.txt'):   #检验给出的路径是否是一个文件 and
        with open(fname,'r') as fp:
            file=fp.read()           #读取文本文件，以byte为单位
            fp.close()               #关闭文件
        words+=re.split(r'[\s]',file)   #按照空格将字符串分离
x=Counter()                       # 创建一个新的空counter
for word in words:
    x[word]+=1
x=dict(x)                                                #转化成字典
x=dict(sorted(x.items(),key=lambda d:d[1],reverse=True))  #sorted函数，对x排序，reverse=True反向排序
for key,value in x.items():
    print(key+":"+str(value))