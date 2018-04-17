with open("words.txt",'r') as file_object:
    words_dic = {}
    for i in file_object.read().splitlines():
        for j in i[:].split(' '):
            if j == '':
                continue
            if words_dic.has_key(j):
                words_dic[j] += 1
            else:
                words_dic[j] = 1
    file_object.close()
words_list = words_dic.items()
words_list.sort(key=lambda x:x[1],reverse = True)
print "[words]" + ' '*6 + "[frequency]"
for i in words_list:
    print str(i[0])+' '*(21-len(i[0]))+str(i[1]).rjust(2)
