#include "PoliceTreeOps.h"


static inline PoliceTree createTreeNode(PoliceId id, int amount)
{
		PoliceTree new = (PoliceTree) malloc(sizeof(PoliceTreeNode));
		if(new == NULL)
		{
				fprintf(stderr, "\nOut of memory while inserting in in_BST\n");
				exit(-1);
		}

		new->succ=NULL;
		new->left=NULL;
		new->right = NULL;
		new->amount = amount;
		new->id=id;
		return new;

}

PoliceTree insertByPoliceId(PoliceTree root, PoliceId id, int amount)
{
	PoliceTree p, prev, succ;
	p=prev=succ = NULL;
	if(root == NULL)
	{
			PoliceTree new=createTreeNode(id, amount);
			return new;
	}
	p=root;
	while (p != NULL)
	{
		if(p->id == id)// if entry found, then update amount
		{
			p->amount = p->amount + amount;
//			break;
			return root;
		}
		else if(id < p->id) // search left tree
		{
				succ = p;
				if (p->left == NULL)
				{
						PoliceTree new= createTreeNode(id, amount);
						p->left = new;
//						new->succ = succ;
						if(prev != NULL)
						{
								new->succ = prev->succ;
								prev->succ = new;
						}
						else
								new->succ=succ;
						return root;
				}
				p=p-> left;
		}
		else if(p->id < id) // search right tree
		{
				prev=p;
				if (p->right== NULL)
				{
						PoliceTree new= createTreeNode(id, amount);
						p->right = new;
						if(prev != NULL)
						{
								new->succ = prev->succ;
								prev->succ = new;
						}
						else
								new->succ=succ;

/*
						new->succ = prev->succ;
						prev->succ = new;
*/
						return root;
				}
				p=p->right;
		}
	}
	return root;
}
