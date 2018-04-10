#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX_WORD_LENGTH 256
#define CHAR_BASE 97

typedef struct _Node{
    int count;
    struct _Node * pNext[26];
    _Node(){
        count = 0;
        for(int i = 0; i < 26; i++){
            pNext[i] = NULL;
        }
    }
}Node, *pNode;

void buildTree(char * buffer);
void tranverse(void);

pNode root;
char output[MAX_WORD_LENGTH];
unsigned int outputIndex;

int main(){
    char buffer[MAX_WORD_LENGTH];
    root = new Node();

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
    return 0;
}

void buildTree(char * buffer){
    pNode p = root;
    while(*buffer != '\0'){
        if(p->pNext[(*buffer)-CHAR_BASE] == NULL){
            p->pNext[(*buffer)-CHAR_BASE] = new Node();
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

void tranverse(pNode p){
    if(p->count != 0){
        output[outputIndex] = '\0';
        cout << output << "  "<< p->count << endl;
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