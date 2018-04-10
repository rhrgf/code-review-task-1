def words_counter(content):
    string = ""
    dic = {}
    for i in range(len(content)):
        if content[i] == " ":
            if string.isalpha():
                if string in dic:
                    dic[string] = dic[string] + 1
                else:
                    dic[string] = 1
            string = ""
        else:
            string = string + content[i]
            if i == len(content) - 1:
                if string.isalpha():
                    if string in dic:
                        dic[string] = dic[string] + 1
                    else:
                        dic[string] = 1
                string = ""
    return dic


f = open("word.txt", "r")
content = f.read()
content = content.replace('\n', " ")
dic = words_counter(content)
list = sorted(dic.items(), key=lambda item: item[1], reverse=True)
print(list)
for i in range(len(list)):
    print("%s  %d" % (list[i][0], list[i][1]))
