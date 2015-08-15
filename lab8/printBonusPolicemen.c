#include "PoliceTreeOps.h"


static inline int getMaxamount(PoliceTree root)
{
		PoliceTree p=root;
		if(p == NULL)
				return 0;

		if(p->right  == NULL)
				return p->amount;
		while(p->right !=NULL)
		{
			p=p->right;
		}
		return p->amount;
}
void printTree(FILE* fp,PoliceTree root,double edge)
{
    	PoliceTree p,q;

		p=root;
		if(p==NULL)
		{
			return;
		}
		if(p->amount>=edge){
		printTree(fp,p->left,edge);
        fprintf(fp,"%d %d\n",p->id,p->amount);
		}
		printTree(fp,p->right,edge);

}
void printBonusPolicemen(PoliceTree root)
{
root=reorderByFineAmount(root);
FILE* fp= fopen("bonus.txt","w");
int max=getMaxamount(root);
double edge=.9*max;
PoliceTree prev=NULL,cur=root;
printTree(fp,root,edge);
fclose(fp);
}
