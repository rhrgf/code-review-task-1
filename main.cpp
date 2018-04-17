#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"

int wordLength(FILE *fp)
{
	int length = 0;
	char readBuffer = fgetc(fp);

	while (readBuffer < 'a' || readBuffer > 'z')
	{
		readBuffer = fgetc(fp);
		if (readBuffer == EOF)
		{
			return length;
		}
	}

	while (readBuffer >= 'a' && readBuffer <= 'z')
	{
		length++;
		readBuffer = fgetc(fp);
	}

	if (readBuffer == EOF)
	{
		fseek(fp, (-1)*(length), SEEK_CUR);
	}
	else
	{
		fseek(fp, (-1)*(length + 1), SEEK_CUR);
	}

	return length;
}

int searchList(PIDNODE list, char *word)
{
	PIDNODE tempNode = list;

	while (tempNode->next)
	{
		tempNode = tempNode->next;
		if (!strcmp(tempNode->id->identifier, word))
		{
			tempNode->id->counter++;
			return 1;
		}
	}

	PIDSTRUCT newId = (PIDSTRUCT)malloc(sizeof(IDSTRUCT));//动态分配的空间在sortList()函数中以节点为单位释放
	newId->identifier = word;
	newId->counter = 1;

	PIDNODE newNode = (PIDNODE)malloc(sizeof(IDNODE));//动态分配的空间在sortList()函数中以节点为单位释放
	newNode->id = newId;
	newNode->next = NULL;
	tempNode->next = newNode;

	return 0;
}

void swapNeighbor(PIDNODE pPNode)
{
	PIDNODE tempNode = pPNode->next;
	pPNode->next = tempNode->next;
	tempNode->next = pPNode->next->next;
	pPNode->next->next = tempNode;
}

PIDNODE penultNode(PIDNODE list)
{
	PIDNODE tempNode = list;

	if (!list->next)
	{
		return NULL;
	}

	while (tempNode->next)
	{
		if (tempNode->next->next)
		{
			tempNode = tempNode->next;
		}
		else
		{
			break;
		}
	}

	return tempNode;
}

void sortList(PIDNODE list)
{
	PIDNODE tempNode = list;
	PIDNODE secLastNode = NULL;
	while (list->next)
	{
		while (!tempNode->next == 0)
		{
			if (!tempNode->next->next == 0)
			{
				if (tempNode->next->id->counter > tempNode->next->next->id->counter)
				{
					swapNeighbor(tempNode);
				}
			}
			else
			{
				break;
			}
			tempNode = tempNode->next;
		}
		secLastNode = penultNode(list);
		printf("%s %d\n", secLastNode->next->id->identifier, secLastNode->next->id->counter);
		free(secLastNode->next);
		secLastNode->next = NULL;
		tempNode = list;
	}
}

int main()
{
	FILE *fp = fopen("word.txt", "r");
	if (fp == NULL)
	{
		printf("Cannot open file word.txt.\n");
		return 0;
	}

	IDNODE startList;

	while (1)
	{
		int nextWordLen = wordLength(fp);
		if (nextWordLen == 0)
		{
			break;
		}
		char *nextWord = (char*)malloc(nextWordLen + 1);
		*(nextWord + nextWordLen) = 0;
		fread(nextWord, nextWordLen, 1, fp);
		searchList(&startList, nextWord);
	}

	sortList(&startList);

	fclose(fp);

	return 0;
}