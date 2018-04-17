
#include <stdio.h>
#include <string.h>
 
struct words   //单词结构体
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
    //读文件解析成单词
    while (  (c= fgetc(fp)) !=EOF  )
    {       
            //这些符号分割的都认为是一个单词结束
        if (c!=',' && c!='.' && c!='?' && c!=' ' && c!='\n')
        {
            tmp[j++] =(c>='A'&&c<='Z')?c+32:c; //全转成小写 就可以无视大小写统计了
        }else
        {
            tmp[j] ='\0';
            j=0;
            flag = 0;
            //判断单词是否已经记录 如果已有则使用率加1
            for (k=0;k<i;k++)
            {
                if ( strcmp(tmp,word[k].word)==0 )
                {
                    word[k].count++;
                    flag = 1;
                    break;
                }
            }
            //没有则存入单词结构体数组保存
            if (!flag)
            {
                strcpy(word[i].word,tmp);
                word[i].count++;
                i++;
            }
        }
    }
    fclose(fp);
    //使用率排序
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
        //输出排序后的所有已记录单词
    for (k=0;k<i;k++)
    {
        printf("%s4%d\n",word[k].word,word[k].count);
    }
}