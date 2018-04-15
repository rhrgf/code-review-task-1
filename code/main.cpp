#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
#define MAX_WORD_LENGTH 256
#define CHAR_BASE 97

typedef struct _RECORD{
    string word;
    unsigned int count;
    _RECORD(char * _word, unsigned int _count){
        word = _word;
        count = _count;
    }
}RECORD, *PRECORD;

typedef struct _NODE{
    unsigned int count;
    struct _NODE * pNext[26];
    _NODE(){
        count = 0;
        for(int i = 0; i < 26; i++){
            pNext[i] = NULL;
        }
    }
}NODE, *PNODE;

bool readInfoInTextBuffer();
void buildTree(char * buffer);
void tranverseTree(PNODE p);
void showInfomations(void);
bool cmp(const PRECORD &lR, const PRECORD &rR);

list<PRECORD> recordList; 
PNODE root;
string output;
string textBuffer;
unsigned int outputIndex;

int main(){
    root = new NODE();
    readInfoInTextBuffer();
    tranverseTree(root);
    recordList.sort(cmp);
    showInfomations();
    return 0;
}

bool readInfoInTextBuffer(){
    ifstream inputTxt("words.txt");
    if(!inputTxt.is_open()){
        cout << "Open file error!" << endl;
        return false;
    }
    while(!inputTxt.eof()){
        inputTxt >> textBuffer;
        buildTree((char *)textBuffer.c_str());
    }
}

void buildTree(char * buffer){
    PNODE p = root;
    while(*buffer != '\0'){
        if(p->pNext[(*buffer)-CHAR_BASE] == NULL){
            p->pNext[(*buffer)-CHAR_BASE] = new NODE();
            p = p->pNext[(*buffer)-CHAR_BASE];
            buffer += 1;
        }
        else{
            p = p->pNext[(*buffer)-CHAR_BASE]; 
            buffer += 1;
        }
    }
    p->count += 1;
    return;
}

void tranverseTree(PNODE p){
    if(p->count != 0){
        output[outputIndex] = '\0';
        PRECORD pRecord = new RECORD((char *)output.c_str(), p->count);
        recordList.push_back(pRecord);
    }
    for(int i = 0; i < 26; i++){
        if(p->pNext[i] != NULL){
            output[outputIndex] = i + CHAR_BASE;
            outputIndex++;
            tranverseTree(p->pNext[i]);
        }
    }
    delete p;
    outputIndex --;
    return;
}

void showInfomations(){
    for (auto & i : recordList){
        cout << i->word << " " << i->count << endl;
        delete i;
    }
    return;
}

bool cmp(const PRECORD &lR, const PRECORD &rR){
    return lR->count > rR->count;
}