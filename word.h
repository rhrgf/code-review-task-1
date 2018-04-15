#include "stdio.h"

struct word
{
	char words[20];
	int times;
	struct word* next;
};