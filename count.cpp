#include"count.h"
#include<iostream>
#include<queue>
#include<string>
#include<fstream>

int ReadFile(const char* file, map<string, int>& WordCount)
{
	ifstream FileInput;
	FileInput.open(file);
	if(!FileInput)
	{
		return -1;
	}

    string word;
    while(FileInput >> word)
    {
    	++WordCount[word];
	}
	FileInput.close();
	return 0;
}

int PrintWord(map<string, int>& WordCount)
{
	priority_queue< pair<int, string> > SortQueue;
	for(map<string, int>::iterator it = WordCount.begin(); it != WordCount.end(); it++)
	{
		SortQueue.push(make_pair(it->second, it->first));
	}
	
    cout << "word\t\t" << "times" << endl;
	while(!SortQueue.empty())
	{
    	cout << SortQueue.top().second << "\t\t" << SortQueue.top().first << endl;
    	SortQueue.pop();
	}
	return 0;
}
