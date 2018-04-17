#pragma once
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <functional>
using namespace std;

void CountWordFrequencyFromFile(const char *Path, map<string, size_t> & word_count);

set<pair<string, size_t>, function<bool(pair<string, size_t>, pair<string, size_t>)>>
SortWordFrequency(const map<string, size_t> & word_count);
