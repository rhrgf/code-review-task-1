f = open("words.txt",'r')
char = f.read(1)
st = ''
dict = {}
while char != '':
    while(char == ' ' or char == '\n'):
        char = f.read(1)
    while(char != ' ' and char != '\n' and char != ''):
        st = st + char
        char = f.read(1)
    if(st != ''):
        try:
            dict[st] = dict[st] + 1
        except:
            dict[st] = 1
    st = ''
dict_sorted = sorted(dict.items(),key=lambda item:item[1],reverse=True);
for item in dict_sorted:
    print(str(item[0])+' '+str(item[1]))
