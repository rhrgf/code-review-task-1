#include<map>  
#include<string>  
#include<iostream>  
#include <fstream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> PAIR;

bool compare(PAIR& lhs, PAIR& rhs);
vector<PAIR> sortWordFromStream(istream &in);