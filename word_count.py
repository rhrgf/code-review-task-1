import re

def count(str_i):
    dict_out={}
    l = len(str_i)
    k = 0
    for i in range(l):
        flag=0
        temp = ord(str_i[i])
        if (temp<=122 and temp>=97 and i!=l-1):
            continue
        else:
            if k == i:
                k=i+1
                continue
            if i==l-1:
                i=i+1
            s_temp = str_i[k:i]
            for key in dict_out.keys():
                if key == s_temp:
                    dict_out[key] += 1
                    k = i+1
                    flag=1
                    break
            if flag==0:
                dict_out[s_temp] = 1
                k = i+1

    return dict_out

def main():
    f = open('words.txt','r')
    str_i=f.read()
    dict_count = count(str_i)
    dict_fin = sorted(dict_count.items(),key = lambda a:a[1],reverse=True)
    l = len(dict_fin)
    for i in range(l):
        print(dict_fin[i][0],' ',dict_fin[i][1])
main()
input('')
