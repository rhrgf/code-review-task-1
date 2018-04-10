def countwords(filename):
    wordlist={};
    with open(filename,'r') as fp:
        for line in fp.readlines():
            words=line.split();#字符串分割
            for word in words:#循环计数
                if word not in wordlist:
                    wordlist[word]=1;
                else:
                    wordlist[word]+=1;
        wordlist=sorted(wordlist.items(), key=lambda x: x[1], reverse=True);#倒序排序
    for x in wordlist:#输出
        print(x);

if __name__ == '__main__':
    filename = input("please input the filename:");
    countwords(filename);