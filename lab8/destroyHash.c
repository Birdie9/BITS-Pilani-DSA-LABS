#include "DriverHashOps.h"


void destroyHash(DriverHash dh)
{
	int i;
	for(i=0; i< MAX_HASH; i++)
	{
			Link p=dh[i].head;
			while ( p!=NULL )
			{
					Link q=p;
					p=p-> next;
					free (q);
			}
	}
	return;
}
