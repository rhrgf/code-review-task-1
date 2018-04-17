#ifndef _DEF_H
#define _DEF_H

typedef struct
{
	char *identifier = NULL;
	int counter = 0;
}IDSTRUCT, *PIDSTRUCT;

typedef struct node
{
	PIDSTRUCT id = NULL;
	node *next = NULL;
}IDNODE, *PIDNODE;

#endif // !_DEF_H

