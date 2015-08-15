#include "PoliceTreeOps.h"
#include<assert.h>

int height(PoliceTree node)
{
    if(node==NULL) return 0;
    //else return node->height;
    int h1=height(node->left);
    int h2=height(node->right);
    if(h1>h2) return 1+h1;
   // else return 1+h2;
}
int getBalance(PoliceTree node)
{
    if(node==NULL)return 0;
    int h1=height(node->left);
    int h2=height(node->right);
    return h1-h2;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}

PoliceTree rightRotate(PoliceTree y)
{
    PoliceTree x = y->left;
    PoliceTree T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
PoliceTree findPred(PoliceTree root,PoliceTree node)
{
    PoliceTree cur=root;
    while(cur->left)
    {
        cur=cur->left;
    }
    if(cur==node) return NULL;
    while(cur->succ!=node)
    {
        cur=cur->succ;
    }
    return cur;
}
PoliceTree leftRotate(PoliceTree x)
{
    PoliceTree y = x->right;
    PoliceTree T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}
int findkey(int key,PoliceTree node){
    PoliceTree cur=node;
    while(cur!=NULL)
    {
        if(cur->amount==key) return 1;
        else if(cur->amount<key) cur=cur->right;
        else cur=cur->left;
    }
    return 0;
}
int check(int bal,int key,PoliceTree node)
{
    if(bal >1) return findkey(key,node->left);
    else if(bal<-1) return findkey(key,node->right);
    return 1;
}
static inline PoliceTree insertByFine(PoliceTree root,PoliceTree node, int key,int id,PoliceTree prevNode)

{
    if(node==NULL) {
    PoliceTree new2=(PoliceTree)malloc (sizeof(PoliceTreeNode));
    new2->left=NULL;
    new2->right=NULL;
    new2->height=1;
    if(prevNode && prevNode->right==NULL)
    {
        new2->succ=prevNode->succ;
        prevNode->succ=new2;
    }
    else if(prevNode)
    {
        new2->succ=prevNode;
        PoliceTree temp=(findPred(root,prevNode));
        if(temp)temp->succ=new2;
    }
    else new2->succ=NULL;
    new2->amount=key;
    new2->id=id;

    return new2;
    }


    if(key>node->amount) node->right=insertByFine(root,node->right,key,id,node);
    else {
            node->left=insertByFine(root,node->left,key,id,node);

    }
    node->height = max(height(node->left), height(node->right)) + 1;
    int bal=getBalance(node);

    //assert(check(bal,key,node));
    //left left case
    if(bal>1 && key<=node->left->amount){
        return rightRotate(node);
    }
    //left right case
    else if(bal>1 && key>node->left->amount){
       node->left=leftRotate(node->left);

        return rightRotate(node);
    }
    //right right case
    else if(bal<-1 &&  key>node->right->amount)
    {
        if(node->right==NULL) printf("1");
        return leftRotate(node);
    }
    //right left case
    else if (bal<-1 && key<=node->right->amount)
    {
        node->right=rightRotate(node->right);
        if(node->right==NULL)printf("2");
        return leftRotate(node);
    }
    return node;
}

PoliceTree reorderByFineAmount(PoliceTree root)
{
PoliceTree cur=root;
while(cur->left!=NULL)
{
cur=cur->left;
}
PoliceTree newRoot=NULL;
while(cur!=NULL)
{
newRoot=insertByFine(newRoot, newRoot,cur->amount,cur->id,NULL);
//printPoliceTree(newRoot);
cur=cur->succ;
}

return newRoot;
}
