#include "main.h"

int main()
{
    std::ifstream input("words.txt");
    std::string word;
    std::map<std::string, size_t> word_count;

    while(input >> word)
    {
        ++word_count[word];
    }
    std::multimap<size_t, std::string> flip_word_count = flip_map(word_count);
    std::multimap<size_t, std::string>::reverse_iterator reverse_itor = flip_word_count.rbegin();
    while(reverse_itor != flip_word_count.rend())
    {
        std::cout << reverse_itor->second << " " << reverse_itor->first << std::endl;
	++reverse_itor;
    }
    return 0;
}
