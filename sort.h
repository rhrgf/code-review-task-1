#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "word.h"



void swaptimes(int *a,int *b)
{
	int t = *a;
	*a = *b ;
	*b = t;
}

void swapinfo(char a[20],char b[20])
{
	char t[20];
	memset(t,0,20);
	sprintf(t,"%s",a);
	sprintf(a,"%s",b);
	sprintf(b,"%s",t);
}

word *partion(word *pBegin,word *pEnd)
{
	if(pBegin == pEnd||pBegin->next==pEnd)
		return pBegin;
	int key = pBegin->times;
	word *p=pBegin,*q=pBegin;
	while(q!=pEnd)
	{
		if(q->times>key)
		{
			p->next;
			swaptimes(&p->times,&q->times);
			swapinfo(p->words,q->words);
		}
		q=q->next;
	}
	swaptimes(&p->times,&pBegin->times);
	swapinfo(p->words,pBegin->words);
	return p;
}

void quick_sort(word *pBegin,word *pEnd)
{
	if(pBegin==pEnd||pBegin->next==pEnd)
		return;
	word *mid=partion(pBegin,pEnd);
	quick_sort(pBegin,mid);
	quick_sort(mid->next,pEnd);
}