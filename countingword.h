#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sort.h"
#include "saveletter.h"

/*
字符数组可能爆炸
没注释
函数需要分块
边界情况考虑不够：文档没有输入，多个空格，文档结束前有空格，文档技术前没有空格，单词数过长，
*/

FILE *fd,*fd2;
char temp_word[20];
char recent_letter[1];
char outputword[100];
int size = 0;
struct word* now;
struct word* head;

void initial()
{
	head = (struct word*)malloc(sizeof(struct word)); 
	head->times = 0;
	head->next = NULL;
	memset(temp_word,0,20);

	return;
}


void inputs_and_operate()
{
	for(;;)
	{
		int t = fread(recent_letter,1,1,fd);
		if (t==0)  
		{
			if (temp_word[0]!=0)
			{
				now = head;
				saveletter(now,temp_word);
				memset(temp_word,0,20);
				size = 0;
			}
			break;
		}
		if (recent_letter[0]!= ' ')
		{
			if (size<20)
			{
				temp_word[size] = recent_letter[0];
				size++;
			}
		}
		else
		{
			if (temp_word[0] == 0)
			{
				continue;
			}
			else
			{
				now = head;
				saveletter(now,temp_word);			
				memset(temp_word,0,20);
				size = 0;
			}
		}
	}
	fclose(fd);
}

void outputs()
{
	fd2=fopen("output.txt","wb");

	quick_sort(head->next,NULL);
	now = head;
	for(;;)
	{
		if (now->times!=0)
		{
			fprintf(fd2,"%s %d\r\n",now->words,now->times);
		}
		if (now->next != NULL)
		{
			now = now->next;
		}
		else 
			break;
	}
	
	fclose(fd2);
}

void wordcounting(char filename[100])
{
	fd = fopen(filename,"rb");

	initial();
	inputs_and_operate();
	outputs();
	return;
}