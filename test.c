
#include <stdio.h>
#include <string.h>
 
struct words   //���ʽṹ��
{
    char word[20];
    int count;
};
 
main()
{
    struct words word[200] = {0},stmp={0};
    int i=0,j=0,k=0,flag =0;
    char c,tmp[20]={0};
    FILE *fp = NULL;
    fp =fopen("readme.txt","r");
    //���ļ������ɵ���
    while (  (c= fgetc(fp)) !=EOF  )
    {       
            //��Щ���ŷָ�Ķ���Ϊ��һ�����ʽ���
        if (c!=',' && c!='.' && c!='?' && c!=' ' && c!='\n')
        {
            tmp[j++] =(c>='A'&&c<='Z')?c+32:c; //ȫת��Сд �Ϳ������Ӵ�Сдͳ����
        }else
        {
            tmp[j] ='\0';
            j=0;
            flag = 0;
            //�жϵ����Ƿ��Ѿ���¼ ���������ʹ���ʼ�1
            for (k=0;k<i;k++)
            {
                if ( strcmp(tmp,word[k].word)==0 )
                {
                    word[k].count++;
                    flag = 1;
                    break;
                }
            }
            //û������뵥�ʽṹ�����鱣��
            if (!flag)
            {
                strcpy(word[i].word,tmp);
                word[i].count++;
                i++;
            }
        }
    }
    fclose(fp);
    //ʹ��������
    for (j=0;j<i;j++)
    {
        for (k=0;k<i-j-1;k++)
        {
            if (word[k].count>word[k+1].count)
            {
                stmp = word[k];
                word[k] = word[k+1];
                word[k+1] = stmp;
            }
        }
    }
        //��������������Ѽ�¼����
    for (k=0;k<i;k++)
    {
        printf("%s4%d\n",word[k].word,word[k].count);
    }
}