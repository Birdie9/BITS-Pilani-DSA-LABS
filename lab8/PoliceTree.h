#include "History.h"
#ifndef __POLICETREE_H
#define __POLICETREE_H

struct __inBST;
typedef struct __inBST PoliceTreeNode;
typedef PoliceTreeNode *PoliceTree;

struct __inBST
{
		PoliceTree left;
		PoliceId id;
		int amount;
		int height;
		PoliceTree succ;
		PoliceTree right;
};


#endif
