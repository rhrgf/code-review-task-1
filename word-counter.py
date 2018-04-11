# coding = utf-8
file = open("word.txt")
content = file.read()
string = ""
dic = {}
for i in range(len(content)):
    if content[i] == " " or content[i] == "\n":
        if string.isalpha():
            try:
                dic[string] = dic[string] + 1
            except:
                dic[string] = 1
        string = ""
    else:
        string = string + content[i]
        if i == len(content) - 1:
            if string.isalpha():
                try:
                    dic[string] = dic[string] + 1
                except:
                    dic[string] = 1
            string = ""
list = sorted(dic.items(), key=lambda item: item[1], reverse=True)
for i in list:
    print("%s  %d" % (i[0], i[1]))