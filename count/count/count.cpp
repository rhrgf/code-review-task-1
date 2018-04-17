// count.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdio"
#include "iostream"
#include "string"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "DealWithString.h"

using namespace std;

string readFileIntoString()
{
	ifstream ifile;
	//先读入到buf
	ifile.open("d:\\words.txt");
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
	{
		buf.put(ch);
	}
	ifile.close();
	return buf.str();
}



int main()
{
	string s;
	s = readFileIntoString();
	DealWithString dws;
	dws.count(s);
	return 0;
}
