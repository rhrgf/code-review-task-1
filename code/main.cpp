#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
#define MAX_WORD_LENGTH 256
#define CHAR_BASE 97

typedef struct _Record{
    string word;
    unsigned int count;
    _Record(char * _word, unsigned int _count){
        word = _word;
        count = _count;
    }
}RECORD, *PRECORD;

typedef struct _Node{
    unsigned int count;
    struct _Node * pNext[26];
    _Node(){
        count = 0;
        for(int i = 0; i < 26; i++){
            pNext[i] = NULL;
        }
    }
}NODE, *PNODE;

void buildTree(char * buffer);
void tranverse(PNODE p);
void showInfomations(void);
bool cmp(const PRECORD &lR, const PRECORD &rR);

list<PRECORD> recordList; 
PNODE root;
char output[MAX_WORD_LENGTH];
unsigned int outputIndex;

int main(){
    char buffer[MAX_WORD_LENGTH];
    root = new NODE();

    ifstream inputTxt("words.txt");
    if(!inputTxt.is_open()){
        cout << "Open file error!" << endl;
        return -1;
    }
    while(!inputTxt.eof()){
        inputTxt >> buffer;
        buildTree(buffer);
    }
    tranverse(root);
    recordList.sort(cmp);
    showInfomations();
    return 0;
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

void tranverse(PNODE p){
    if(p->count != 0){
        output[outputIndex] = '\0';
        PRECORD pRecord = new RECORD(output, p->count);
        recordList.push_back(pRecord);
    }
    for(int i = 0; i < 26; i++){
        if(p->pNext[i] != NULL){
            output[outputIndex] = i + CHAR_BASE;
            outputIndex++;
            tranverse(p->pNext[i]);
        }
    }
    outputIndex --;
    return;
}

void showInfomations(){
    for (auto & i : recordList){
        cout << i->word << " " << i->count << endl;
    }
    return;
}

bool cmp(const PRECORD &lR, const PRECORD &rR){
    return lR->count > rR->count;
}