#include "tools.h"

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string filename{"words.txt"};

    word_count = GetWordMapFromFile(filename);
    OutputWordMapReverse(word_count);
    return 0;
}
