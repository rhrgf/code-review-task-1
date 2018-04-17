#include <boost/test/minimal.hpp>
#include <sstream>
#include "tools.h"

using namespace boost;
using namespace std;

void CheckGetWordMapFromFile(){
    string filename{"words.txt"};
    map<string, size_t> real_result = {
        {"hello", 3},
        {"me", 2},
        {"test", 1}
    };
    BOOST_CHECK(GetWordMapFromFile(filename) == real_result);
}

void CheckOutputWordMapReverse(){
    streambuf *sbuf = cout.rdbuf();
    map<string, size_t> input = {
        {"hello", 3},
        {"me", 2},
        {"test", 1}
    };
    string cout_result = {"hello 3\nme 2\ntest 1\n"};
    stringstream output;
    cout.rdbuf(output.rdbuf());
    OutputWordMapReverse(input);
    BOOST_CHECK(output.str() == cout_result);
    cout.rdbuf(sbuf);
}

int test_main(int argc, char* argv []){
    CheckGetWordMapFromFile();
    CheckOutputWordMapReverse();
    return 0;
}