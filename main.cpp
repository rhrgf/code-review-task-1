#include"count.h"

int main()
{
	map<string, int> WordMap;
	
	if(ReadFile("test.txt", WordMap) == -1)
	{
		cout << "can not open the file!" << endl;
		return -1;
	}
	
	PrintWord(WordMap);
    return 0;
}
