#include "PoliceTreeOps.h"


void destroyPoliceTree (PoliceTree root)
{
		PoliceTree p=root;
		while(p-> left !=NULL)
		{
				p=p-> left;
		}
		while(p!=NULL)
		{
				PoliceTree del=p;
				p=p->succ;
				free(del);
		}
		return;
}
