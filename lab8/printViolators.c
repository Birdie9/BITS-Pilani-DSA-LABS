#include "DriverHashOps.h"

void printViolators(DriverHash dh)
{
		FILE *fp;
		int i;

		fp=fopen("violators.txt", "w+");
		if(fp == NULL)
		{
				fprintf(stderr, "\nCannot open violator file for writing\n");
				exit(-1);
		}
		for(i=0; i< MAX_HASH; i++)
		{
				Link p;
				p=dh[i].head;
				while (p != NULL)
				{
						if(p->num_violations > 3)
						{
//								fprintf(fp, "DEBUG:%di%d,%d\n", i,p->lic, p->num_violations);
								fprintf(fp, "%d\n", p->lic);
						}
						p=p->next;
				}
		}

		fclose(fp);
		return;
}
