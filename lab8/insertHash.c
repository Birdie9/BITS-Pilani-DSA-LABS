#include "DriverHashOps.h"

static inline  Link createEntry(License lic)
{
		Link new=(Link) malloc(sizeof(Node));
		if(new == NULL)
		{
				fprintf(stderr, "\nOut of memory while inserting in hash table\n");
				exit(-1);
		}
		new->lic=lic;
		new->num_violations = 1;
		new->next=NULL;
		return new;
}


void insertHash(DriverHash dh, License lic)
{
	int index=hash(lic);
	Link p=dh[index].head;
	if (p == NULL ) // first node case
	{
			Link new=createEntry(lic);
			//new->num_violations = 1;
			new->next=NULL;
			dh[index].head = new;
			return ;
	}
	// first node is having a lesser license number than lic
	if(p->lic == lic)
	{
			// entry exists case: update violations here
			p->num_violations++;
			return;
	}
		if(p->lic > lic)
	{
				// insert at head node
				Link new= createEntry(lic);
				//new->num_violations=1;
				new->next=p;
				dh[index].head = new;
				return;
	}
	// later on cases
	while(p->next !=NULL)
	{
			if(p->next->lic == lic)
			{
					// entry exists case: update violations here
					p->next->num_violations++;
					return;
			}
			else if(p->next->lic > lic)
			{
					// insert here
					Link new= createEntry(lic);
					//new->num_violations=1;
					new->next=p->next;
					p->next = new;
					return;
			}
			p=p-> next;
	}
	// last node case
	if(p->next == NULL)
	{
			Link new=createEntry(lic);
			//new->num_violations = 1;
			new->next=NULL;
			p->next= new;
	}
	return;
}
