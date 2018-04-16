
def read(filename):#读取函数
    words = open(filename, 'r').readline()
    return words

def count (words):#计数函数
    list = {}
    words = words.split()#分割
    for word in words:
        if word  in list:
            list[word] += 1
        else:
            list[word] = 1
    list = sorted(list.items(), key=lambda a: a[1], reverse=True)#倒序排序
    return list
if __name__ == '__main__':
    filename = input("please give the name of the file:")
    words = read(filename)#调用函数读取文件中的内容
    list = count(words)#调用函数计数
    for x in list:#输出结果
        print(x)





