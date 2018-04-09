#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int cmp(pair<string, int> x1, pair<string, int> x2)
{
	return x1.second > x2.second;
}

void sortMap(map<string, int>& tosort, vector<pair<string, int>>& sorted)
{
	for (map<string, int>::iterator cur = tosort.begin(); cur != tosort.end(); cur++)
		sorted.push_back(make_pair(cur->first, cur->second));

	sort(sorted.begin(), sorted.end(), cmp);
}

int main(void)
{
	ifstream is(".\\words.txt");
	if (!is)
		return 0;

	map<string, int> words_record;
	string text;
	while (!is.eof())
	{
		is >> text;
		if (words_record.count(text))
			words_record[text]++;
		else
			words_record[text] = 1;
	}

	is.close();
	vector<pair<string, int>> result;

	sortMap(words_record, result);

	for (auto cur = result.begin(); cur < result.end(); cur++)
		cout << cur->first << " " << cur->second << endl;

	cin.get();
	return 0;
}