// count.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//�ȶ��뵽buf
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
