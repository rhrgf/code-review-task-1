#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "countingword.h"


void main()
{
	FILE *fd,*fd2;
	char filename[20];
	char realword[30];
	char testword[30];
	int i;

	for (i=1;i<3;i++)
	{
		memset(filename,0,20);
		sprintf(filename,"input%d.txt",i);
		wordcounting(filename);

		memset(filename,0,20);
		sprintf(filename,"output%d.txt",i);
		fd = fopen(filename,"rb");
		fd2 = fopen("output.txt","rb");

		int flag = 0;
		while (fgets(realword,30,fd)!=NULL)
		{
			fgets(testword,30,fd2);
			if (strncmp(realword,testword,30)!=0)
			{
				flag = 1;
				printf("the %dth data runs wrong!\n",i);
				break;
			}
			memset(testword,0,30);
			memset(realword,0,30);
		}

		if ((flag == 0)&&(fgets(testword,30,fd2)!=NULL))
		{
			flag = 1;
			printf("the %dth data runs wrong!\n",i);
		}

		if (flag == 0)
		{
			printf("the %dth data tests correct!\n",i);
		}

		fclose(fd);
		fclose(fd2);
	}

	getchar();
	return;
}
	