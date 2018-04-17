#pragma once
#include "stdafx.h"
#include "cstdio"
#include "iostream"
#include "string"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "vector" 
using namespace std;

class Save
{
public:
	string str;
	int number;
	static bool comparison(Save a, Save b);
};

class DealWithString
{
public:
	vector <Save> count(string s);
	int classifyVariable(char ch);
	int checkRepeat(string &s, string &result);
	void initiation(string &s);
	void resultDisplay(vector <Save> &save, int numOfWord);
};