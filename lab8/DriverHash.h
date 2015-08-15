#include "History.h"

#ifndef __DRIVERHASH_H
#define __DRIVERHASH_H
#define MAX_HASH 100

struct __node;

typedef struct __node Node;
typedef Node *Link;

struct __node 
{
		License lic;
		int num_violations;
		Link next;
};

typedef struct {
//		int index;
		Link head;
} HashEntry;

typedef HashEntry DriverHash[MAX_HASH];


#endif
