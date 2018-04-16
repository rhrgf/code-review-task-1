#include "tools.h"

using namespace std;

map<string, size_t> GetWordMapFromFile(string &filename){
    ifstream input(filename);
    string word;
    map<string, size_t> word_count;

    while(input >> word)
    {
        ++word_count[word];
    }

    return word_count;
}

void OutputWordMapReverse(map<string, size_t> &word_count){
    multimap<size_t, string> flip_word_count = flip_map(word_count);
    multimap<size_t, string>::reverse_iterator reverse_itor = flip_word_count.rbegin();
    while(reverse_itor != flip_word_count.rend())
    {
        cout << reverse_itor->second << " " << reverse_itor->first << endl;
	    ++reverse_itor;
    }
}