#ifndef _COUNT_H_
#define _COUNT_H_

#include<map>

using namespace std;

int ReadFile(const char* file, map<string, int>& WordCount);

int PrintWord(map<string, int>& WordCount);

#endif
