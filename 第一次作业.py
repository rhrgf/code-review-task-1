def main():
    file_name=input("请输入文件名：")
    file=open(file_name)
    data=file.read()
    words=data.split()
    word_name=[]
    word_freq=[]
    
    for word in words:
        if word not in word_name:
            word_name.append(word)
            word_freq.append(1)
        else:
            word_freq[word_name.index(word)]+=1

    for key in range(len(word_freq)):
        freq=max(word_freq)
        word=word_name[word_freq.index(freq)]
        print('{}\t{}'.format(word,freq))
        word_name.remove(word)
        word_freq.remove(freq)

main()
