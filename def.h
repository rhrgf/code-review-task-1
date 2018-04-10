#ifndef _DEF_H
#define _DEF_H

typedef struct
{
	char *identifier = NULL;
	int counter = 0;
}idStruct, *pIdStruct;

typedef struct node
{
	pIdStruct id = NULL;
	node *next = NULL;
}idNode, *pIdNode;

#endif // !_DEF_H

