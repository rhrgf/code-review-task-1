def readfile():
    file_name=input("请输入文件名：")
    while(1):
        try:
            with open(file_name) as file:
                words=''
                lines=file.readlines()
                for line in lines:
                    line=line.replace('\n',' ')
                    words=words+line
            word=words.split()
            break
        except:
            file_name=input("文件名有误请再次输入：")
    return word

def countword(words):
    word_name=[]
    word_freq=[]
    for word in words:
        if word not in word_name:
            word_name.append(word)
            word_freq.append(1)
        else:
            word_freq[word_name.index(word)]+=1
    return word_name,word_freq

def printword(word_name,word_freq):
    for key in range(len(word_freq)):
        freq=max(word_freq)
        word=word_name[word_freq.index(freq)]
        print('{}\t{}'.format(word,freq))
        word_name.remove(word)
        word_freq.remove(freq)

def main():
  word=readfile()
  word_name,word_freq=countword(word)
  printword(word_name,word_freq)

main()
