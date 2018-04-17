#include "sort.h"
bool compare(PAIR& lhs, PAIR& rhs) {
	return lhs.second > rhs.second;
}

vector<PAIR> sortWordFromStream(istream &in){
	map<string, int> word_count;
	string word;
	while (in >> word)
		++word_count[word];
	vector<PAIR> word_count_vec(word_count.begin(), word_count.end());
	sort(word_count_vec.begin(), word_count_vec.end(), compare);
	return word_count_vec;
}