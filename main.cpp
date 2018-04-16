#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define numberOfCharacter 26
#define BUFFERSIZE 1024
//node of trie 
typedef struct _NODE 
{
    char ch;
    int n;
    _NODE* next[numberOfCharacter];
    
    _NODE(char ch):ch(ch),n(0)
    {
        for(int i=0; i<numberOfCharacter; ++i)
            next[i] = nullptr;
    }
}NODE,* PNODE; 

// a struct to save signal word info
typedef struct _WORD 
{
    string str;
    int number;
}WORD, * PWORD;

void countSingalWord(string& word);
void readOutData(PNODE cur, int deep);
void init();
bool cmpfun(WORD a, WORD b);
PNODE newNode(char ch);

PNODE head;                 //head of trie
vector<WORD> words;         //save words info
int numberOfWords;          //number of words in file

int main(int argn, char** args)
{
    if(argn == 1)
    {
        cout << "no input file!" << endl;
        return -1;    
    }
    
    ifstream buffer;
    buffer.open(args[1], std::ifstream::in);

    if(buffer.fail())
    {
        cout << "can not open file:" << args[1] << endl;
        return -1;
    }
    
    init();
    
    string word;
    while(buffer >> word)
    {
        countSingalWord(word);
    }
    
    readOutData(head, 0);
    sort(words.begin(), words.end(), cmpfun);
    for(auto wr:words)
    {
        cout << wr.str << "\t" << wr.number  << endl;
    }

}

void init()
{
    head = new NODE(' ');
    numberOfWords = 0;
}

void countSingalWord(string& word)
{
    PNODE cur = head;

// if node exists, then create a new node    
    for(auto ch: word)
    {
        int no = ch-'a';
        if(!(*cur).next[no])
        {
            (*cur).next[no] = newNode(ch);
        }
        cur  = (*cur).next[no];
    }

    ++(*cur).n;
    if((*cur).n == 1)
    {
        ++numberOfWords;
    }
}

PNODE newNode(char ch)
{
    return new NODE(ch);
}

void readOutData(PNODE cur, int deep)
{
    static string buf(BUFFERSIZE, 0x0);
    static int no = 0;

    buf[deep] = (*cur).ch;
    if((*cur).n != 0)
    {
        words.push_back(WORD{buf,(*cur).n});
    }
    for(int i=0; i<numberOfCharacter; ++i)
    {
        if((*cur).next[i] == nullptr)
        {
            continue;
        }
        readOutData((*cur).next[i], deep+1);
    }
    buf[deep] = 0x0;
    //delete node
    delete cur;
}

bool cmpfun(WORD a, WORD b)
{
    return a.number > b.number;
}
