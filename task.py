

def read():
    contents = ''
    try:
    	    with open('word.txt','r') as file:
        lines = file.readlines()
        for line in lines:
            line = line.replace('\n',' ')
            contents = contents + line
    except:
    	print("读取失败")
    return contents

def count(contents):
    dic = {}
    contents = contents.split(' ')
    for content in contents:
        if dic.__contains__(content):
            dic[content] = dic[content] + 1
        else :
            dic[content] = 1
    dics=sorted(dic.items(),key=lambda d:d[1],reverse = True)
    for dic in dics:
        print(dic[0]+':'+str(dic[1]))


def main():
    contents=read()
    count(contents)
main()
