#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}

int main() {
    std::ifstream input("words.txt");
    std::string word;
    std::map<std::string, size_t> word_count;

    while(input >> word) {
        ++word_count[word];
    }
    std::multimap<size_t, std::string> flip_word_count = flip_map(word_count);
    std::multimap<size_t, std::string>::reverse_iterator reverse_itor = flip_word_count.rbegin();
    while(reverse_itor != flip_word_count.rend()) {
        std::cout << reverse_itor->second << " " << reverse_itor->first << std::endl;
	++reverse_itor;
    }
    return 0;
}
