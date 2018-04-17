#*************************************
#[function name]:words_count
#[input parameter]:None
#[output parameter]:A Two-column array
#[function detail]:print out the words
#and their frequency
#*************************************
def words_count():
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
        words_list = words_dic.items()
        words_list.sort(key=lambda x:x[1],reverse = True)
    return words_list

#*************************************
#[function name]:print_out
#[input parameter]:A Two-column array
#[output parameter]:None
#[function detail]:print out the words
#and their frequency
#*************************************
def print_out(words_list):
    print "[words]" + ' '*6 + "[frequency]"
    for i in words_list:
        print str(i[0])+' '*(21-len(i[0]))+str(i[1]).rjust(2)

#*************************************
#[function name]:main
#*************************************
def main():

    words_list = words_count()
    print_out(words_list)

main()
