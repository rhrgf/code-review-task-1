#coding=utf-8
"""
本程序实现读取文本内容并且统计词频功能
"""
import collections
import os
from docopt import docopt

#读取文件
def read_file(file_name):    
    words=[]
    if os.path.exists(file_name):
        with open(file_name) as f:
            for line in f:
                words+=line.strip().split(' ')
    else:
        print ("file " + file_name + " not exists.")
    return words

#词频计数
def count_words(words):
    words_count = collections.Counter(words)
    words_count = sorted(words_count.items(),key=lambda x:x[1],reverse=True)
    return words_count

#结果输出
def print_result(output,words_count):
    with open(output,'w') as f:
        for (key,value) in words_count:
            f.write(key+" "+str(value)+"\n")
            print(key+" "+str(value)+"\n")


if __name__ == '__main__':
    _USAGE = '''
    Usage:
      demo01 <input> <output> [options]
      demo01 --help
    Options:      
    
    '''
    options = docopt(_USAGE)
    input_file = options['<input>']
    output_file = options['<output>']
    words = read_file(input_file)
    words_count=count_words(words)
    print_result(output_file,words_count)
