#include "PoliceTreeOps.h"


void printPoliceTree(PoliceTree root)
{
		PoliceTree p,q;

		p=root;
		if(p==NULL)
		{
			return;
		}
		printPoliceTree(p->left);
			
		fprintf(stderr, "%u: %d,%d ==> %u| <%u >%u\n",
		    p,  p->id, p->amount, p->succ, p->left, p->right);

		printPoliceTree(p->right);
		
		return;
}
