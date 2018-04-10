#include<map>  
#include<string>  
#include<iostream>  
#include <fstream> 
#include <vector>
#include <algorithm>
#include "sort.h"
using namespace std;
typedef pair<string, int> PAIR;



void main(){
	ifstream in("D://test.txt");
	vector<PAIR> word_count_vec = sortWordFromStream(in);
	for (const auto &w : word_count_vec){
		cout << w.first <<" "<<w.second<< endl;
	}
}