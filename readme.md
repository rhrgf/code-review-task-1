/* something */


f = open("words.txt",'r')
char = f.read(1);

out1 = '';
out2 = [];
out3 = [];
l = 0;
s = 0;
while char != '':
    if (char != ' '):
        out1 += char;
        char = f.read(1);
    else:
        out2.append(out1);
        out1 = '';
        char = f.read(1);
out2.append(out1);
m = len(out2);
while (l != m):
    if (out2[l] in out3):
        out3.append(out2[l]);
        l += 1;
    else:
        s = out2.count(out2[l]);
        s = str(s);
        print (out2[l] + ' ' + s);
        out3.append(out2[l]);
        l +=1;
