//�����޸ģ������˲���ע�ͣ��������ֿ飬�������쳣����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char word[20];
    int frequency;
}wd;

void Sort(int k,wd *words)    //���ṹ�����еĵ��ʰ���Ƶ������
{
    wd stemp={0};
    int i,j;
    for (i=0;i<k;i++)
    {
        for (j=0;j<k-i-1;j++)
        {
            if (words[j].frequency<words[j+1].frequency)
            {
                stemp = words[j];
                words[j] = words[j+1];
                words[j+1] = stemp;
            }
        }
    }
}
void Print(int k,wd *words)    //��ӡ���ʼ�Ƶ��
{
    int i;
    for (i=0;i<k;i++)
    {
        printf("%s %d\n",words[i].word,words[i].frequency);
    }
}
int ReadFile(FILE *fp,wd *words)     //���ļ��������ļ��еĵ��ʷ���������洢��ṹ������
{
    int i=0,j,k=0,flag;
    char ch,temp[20];
    if((fp=fopen("words.txt","r"))==NULL)
    {
        printf("Open failed");
        exit(EXIT_FAILURE);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch!=' '&&ch!='\n')
            temp[i++]=ch;
        else
        {
            temp[i]='\0';
            i=0;flag=0;
            for(j=0;j<k;j++)
            {
                if(strcmp(words[j].word,temp)==0)
                {
                    words[j].frequency++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                strcpy(words[k].word,temp);
                words[k++].frequency=1;
            }
        }
    }
    fclose(fp);
    return k;
}
void main()
{
    wd words[50];
    int num;
    FILE *fp;
    num=ReadFile(fp,words);
    Sort(num,words);
    Print(num,words);
}
