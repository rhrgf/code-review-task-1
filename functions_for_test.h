#pragma once
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

//由于map不直接支持排序操作，所以把map中的元素插入到vector中，再对vector进行排序
template<class Compare>
void sortMap(map<string, int>& tosort, vector<pair<string, int>>& sorted, Compare cmp)
{
	for (auto cur = tosort.begin(); cur != tosort.end(); cur++)
		sorted.push_back(make_pair(cur->first, cur->second));

	sort(sorted.begin(), sorted.end(), cmp);
}