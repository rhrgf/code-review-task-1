#include "stdio.h"
#include "stdlib.h"
#include "string.h"

FILE *fd;
struct word
{
	char info[20];
	int times;
	struct word* next;
};

struct word* head;

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
			swapinfo(p->info,q->info);
		}
		q=q->next;
	}
	swaptimes(&p->times,&pBegin->times);
	swapinfo(p->info,pBegin->info);
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

int main()
{
	char temp[20];
	char r[1];
	int size = 0;
	struct word* now;

	head = (struct word*)malloc(sizeof(struct word)); 
	head->times = 0;
	head->next = NULL;
	memset(temp,0,20);

	fd = fopen("input.txt","rb");
	for(;;)
	{
		int t = fread(r,1,1,fd);
		if (t==0)  
		{
			if (temp[0]!=0)
			{
				now = head;
				for(;;)
				{
					if (strncmp(now->info,temp,20)==0)
					{
						now->times++;
						memset(temp,0,20);
						size = 0;
						break;
					}
					else
					{
						if (now->next!=NULL)
						{
							now = now->next;
						}
						else
						{
							struct word* newword = (struct word*)malloc(sizeof(struct word)); 
							sprintf(newword->info,"%s",temp);
							newword->times = 1;
							newword->next = NULL;
							now->next = newword;
							memset(temp,0,20);
							size = 0;
							break;
						}
					}
				}
			}
			break;
		}
		if (r[0]!= ' ')
		{
			temp[size] = r[0];
			size++;
		}
		else
		{
			if (temp[0] == 0)
			{
				continue;
			}
			else
			{
				now = head;
				for(;;)
				{
					if (strncmp(now->info,temp,20)==0)
					{
						now->times++;
						memset(temp,0,20);
						size = 0;
						break;
					}
					else
					{
						if (now->next!=NULL)
						{
							now = now->next;
						}
						else
						{
							struct word* newword = (struct word*)malloc(sizeof(struct word)); 
							sprintf(newword->info,"%s",temp);
							newword->times = 1;
							newword->next = NULL;
							now->next = newword;
							memset(temp,0,20);
							size = 0;
							break;
						}
					}
				}
			}
		}
	}
	fclose(fd);

	quick_sort(head->next,NULL);

	now = head;
	for(;;)
	{
		if (now->times!=0)
		{
			printf("%s %d\n",now->info,now->times);
		}
		if (now->next != NULL)
		{
			now = now->next;
		}
		else 
			break;
	}
	
	getchar();
	return 0 ;
}

