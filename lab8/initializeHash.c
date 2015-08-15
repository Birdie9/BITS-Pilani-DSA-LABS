#include "DriverHashOps.h"


void initializeHash(DriverHash dh)
{
		int i;
		for (i=0; i< MAX_HASH; i++)
				dh[i].head=NULL;

		return;
}
