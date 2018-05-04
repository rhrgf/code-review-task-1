def count(file):
    char = f.read(1)
    st = ''
    dict = {}
    while char != '':
        while (char == ' ' or char == '\n'):
            char = f.read(1)
        while (char != ' ' and char != '\n' and char != ''):
            st = st + char
            char = f.read(1)
        if (st != ''):
            if(st in dict):
                dict[st] = dict[st] + 1
            else:
                dict[st] = 1
        st = ''
    return dict
if __name__ == '__main__':
    f = open("words.txt", 'r')
    dict = count(f)
    dict_sorted = sorted(dict.items(), key=lambda item: item[1], reverse=True);
    for item in dict_sorted:
        print(str(item[0]) + ' ' + str(item[1]))
