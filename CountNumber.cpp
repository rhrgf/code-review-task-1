#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream fs;
	fs.open("test.txt");
	if(!fs)
	{
		cout << "can not open the file!" << endl;
		return -1;
	}
	
    map<string, int> wordCount;
    string word;
    priority_queue< pair<int, string> > sortCount;

    while(true)
    {
    	fs >> word;
    	wordCount[word]++;
    	if(fs.eof())
    	{
    		break;
		}
	}
	fs.close();
	
	for(map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); it++)
	{
		sortCount.push(make_pair(it->second, it->first));
	}
	
    cout << "word\t\t" << "times" << endl;
	while(!sortCount.empty())
	{
    	cout << sortCount.top().second << "\t\t" << sortCount.top().first << endl;
    	sortCount.pop();
	}
    return 0;
}
