def readfile(filename):
    fp=open(filename,'r')
    text=fp.readlines()
    fp.close()
    return text

def countwords(text):
    wordlist={}
    for line in text:
        words=line.split()#字符串分割
        for word in words:#循环计数
            if word not in wordlist:
                wordlist[word]=1
            else:
                wordlist[word]+=1
    wordlist=sorted(wordlist.items(), key=lambda x: x[1], reverse=True)#倒序排序
    return wordlist

if __name__ == '__main__':
    filename = input("please input the filename:")
    text=readfile(filename)
    wordlist=countwords(text)
    for x in wordlist:#输出
        print(x)