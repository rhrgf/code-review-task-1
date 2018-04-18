#include <stdio.h>
#include <string.h>
typedef struct
{
    char word[20];
    int frequency;
}wd;

void main()
{
    wd words[50],stemp;
    int i,j,k,flag;
    char ch,temp[20];
    i=0;
    k=0;
    FILE *fp;
    fp=fopen("words.txt","r");
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
    for (i=0;i<k;i++)
    {
        printf("%s %d\n",words[i].word,words[i].frequency);
    }
}
