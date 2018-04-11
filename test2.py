def cj(filename):
    dict={}
    c=''
    with open(filename,'r') as f:
        for line in f.readlines():
            for char in line.strip():
                if char!=' ':
                    c =c + char;
                else:
                    if c!='' and c!=' ':
                        if c in dict:
                            dict[c] += 1;
                            c = ''
                        else:
                            dict[c]=1
                            c = ''
            if c !='':
                if c in dict:
                    dict[c] += 1;
                    c = ''
                else:
                    dict[c]=1
                    c = ''
            c=''
        dict = sorted(dict.items(), key=lambda x: x[1], reverse=True)
        for i in dict:
            print(i[0]+' '+str(i[1]))
