def main():
    
    while(1):
        try:
            with open(file_name) as file:
                data=file.read()
                words=data.split()
            break
        except:
            file_name=input("文件名有误请再次输入：")
            
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
