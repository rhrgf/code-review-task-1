def main():
    f = open("words.txt","r")
    content = f.readlines()
    words_dict = {}
    for line in content:
        words = line.replace('\n','').split(' ')
        # print(words)
        for word in words:
            if word not in words_dict:
                words_dict[word] = 1
            else:
                words_dict[word] += 1

    for word, times in sorted(words_dict.items(), lambda x, y: cmp(x[1], y[1]), reverse=True):
        print(word + ' ' + str(times))


if __name__ == '__main__':
    main()
