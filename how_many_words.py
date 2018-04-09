# coding=utf-8


def how_many_words(filename: str) -> dict:
    dic = {}
    with open(filename, 'r') as f:
        for line in f:
            for word in line.split():
                try:
                    dic[word] += 1
                except KeyError:
                    dic[word] = 1
    return dic


if __name__ == '__main__':
    filename = "words.txt"
    temp = [(times, word) for word, times in how_many_words(filename).items()]
    for times, word in sorted(temp, reverse=True):
        print("{0} {1}".format(word, times))
