#include "sort.h"
using namespace std;

void main(){
	ifstream in("D://test.txt");
	vector<PAIR> word_count_vec = sortWordFromStream(in);
	in.close();
	for (const auto &w : word_count_vec){
		cout << w.first <<" "<<w.second<< endl;
	}
}
