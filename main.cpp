#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct node 
{
    char ch;
    int n;
    node* next[26];
    
    node(char ch):ch(ch),n(0)
    {
        for(int i=0; i<26; ++i)
            next[i] = nullptr;
    }
};
struct word 
{
    char* str;
    int n;
};

void count(char* buffer, int wordStart, int wordEnd);
void dfs(node* cur, int deep);
void init();
bool compfun(word a, word b);
node* newNode(char ch);

node* head;
vector<word> words;
int numberOfWords;

int main(int argn, char** args)
{
    if(argn == 1)
    {
        cout << "no input file!" << endl;
        return -1;    
    }
    
    FILE* fp  = fopen(args[1],"r");
    if(fp == nullptr)
    {
        cout << "can not open file:" << args[1] << endl;
        return -1;
    }
    
    unsigned int  fileSize;
    char* buffer;

    fseek(fp, 0 , SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = new char[fileSize+1];
    buffer[fileSize] = 0x0;
    fread(buffer, sizeof(char), fileSize, fp);
    fclose(fp);
    
    init();
    bool flag = false;
    int wordStart;
    for(int i=0; i<fileSize;++i)
    {
        if(!flag)
        {
            if(buffer[i] == ' ')
                continue;
            else 
            {
                flag = true;
                wordStart = i;
            }
        }
        else
        {

            if(buffer[i] != ' ')
                continue;
            else 
           {
               flag = false;
               count(buffer, wordStart, i);
            }
        }
    }
    dfs(head, 0);
    sort(words.begin(), words.end(), compfun);
    for(auto wr:words)
    {
        cout << wr.str << "\t" << wr.n  << endl;
        delete wr.str;
    }

}

void init()
{
    head = new node(' ');
    numberOfWords = 0;
}

void count(char* buffer, int wordStart, int wordEnd)
{
    node* cur = head;
    
    for(int i=wordStart; i<wordEnd; ++i)
    {
        int no = buffer[i]-'a';
        if(!(*cur).next[no])
            (*cur).next[no] = newNode(buffer[i]);
        cur  = (*cur).next[no];
    }
    ++(*cur).n;
    if((*cur).n == 1)
        ++numberOfWords;
}

node* newNode(char ch)
{
    return new node(ch);
}

void dfs(node* cur, int deep)
{
    static char buf[1024] = {0};
    static int no = 0;

    buf[deep] = (*cur).ch;
    if((*cur).n != 0)
    {
        char* tmp = new char[deep+1];
        memcpy(tmp, buf+1, deep+1);
        words.push_back(word{tmp,(*cur).n});
    }
    for(int i=0; i<26; ++i)
    {
        if((*cur).next[i] == nullptr)
            continue;
        dfs((*cur).next[i], deep+1);
    }
    buf[deep] = 0x0;
    delete cur;
}

bool compfun(word a, word b)
{
    return a.n > b.n;
}
