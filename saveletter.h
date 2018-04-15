#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void savenewletter(word* recent,char wordss[20])
{
	struct word* newword = (struct word*)malloc(sizeof(struct word)); 
	sprintf(newword->words,"%s",wordss);
	newword->times = 1;
	newword->next = NULL;
	recent->next = newword;
}

void saveletter(word* recent,char wordss[20])
{
	for(;;)			
	{
		if (strncmp(recent->words,wordss,20)==0)
		{
			recent->times++;
			break;
		}
		else
		{
			if (recent->next!=NULL)
			{
				recent = recent->next;
			}
			else
			{
				savenewletter(recent,wordss);
				break;
			}
	
		}
	}
}