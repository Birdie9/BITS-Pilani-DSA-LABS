#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* text;
struct node;
struct loc;
typedef struct node node;
typedef struct loc loc;
struct node{
	char c;
	node* child[27];
	loc* head;

};
struct loc{
loc* next;
int pos;
};
node* createNode(char c){
	node* new=(node*) malloc(sizeof(node));
	new->head=NULL;
	new->c=c;
	int i;
	for( i=0;i<27;i++)
	{
		new->child[i]=NULL;
	}
	return new;

}
void insert(node* root,char* word,int pos){
	int i=0;
	int len=strlen(word);
	word[len]=123;
	word[len+1]='\0';
	//printf("%s\n",word);
	len++;
	node* cur=root;
	for(i=0;i<len;i++)
	{
		int c=word[i];
		if(cur->child[c-97]!=NULL)
		{
			if(c==123)
			{
				//word present before
				loc* curLoc=cur->child[c-97]->head;
				while(curLoc->next!=NULL) curLoc=curLoc->next;
				curLoc->next =(loc*) malloc(sizeof(loc));
				curLoc->next->pos=pos;
				curLoc->next->next=NULL;
				return;
			}
			else cur=cur->child[c-97];

		}
		else
		{
			char ch=word[i];
			cur->child[c-97]=createNode(ch);
			if(c==123)
			{
				//new word
				cur->child[c-97]->head =(loc*) malloc(sizeof(loc));
				cur->child[c-97]->head->pos=pos;
				cur->child[c-97]->head->next=NULL;
				return;

			}
			else cur=cur->child[c-97];
		}

	}

}
void dfs(FILE* fp,node* cur,char* word,int idx)
{
	//printf("%c ",cur->c);
	int i;
	if(cur->c==123)
	{
	word[idx]='\0';
	fprintf(fp,"%s	",word);
	printf("%s ",word);
	loc* temp=cur->head;
	if(!temp) printf("temp is null!");
	while(temp)
	{
		//printf("int temp\n");
		fprintf(fp,"%d	",temp->pos);
		printf("%d ",temp->pos);
		temp=temp->next;
	}
	fprintf(fp,"\n");
	printf("\n");
	return;
	}
	word[idx]=cur->c;
	idx++;
	for(i=0;i<27;i++)
	{
		if(cur->child[i])
		{
			dfs(fp,cur->child[i],word,idx);
		}
	}

}
void printTrie(node* root)
{
	int i;
	FILE* fp= fopen("outputLab9.txt","w");
	char word[70];
	for(i=0;i<27;i++)
		if(root->child[i])
			dfs(fp,root->child[i],word,0);
	fclose(fp);
}

int sanitize(int idx,char* word){
	int i=0;
while(tolower(text[idx])<=122 && tolower(text[idx])>=97){

	word[i]=tolower(text[idx]);
	i++;
	idx++;
}
word[i]='\0';
return idx;
}

int main(){
	long size;
FILE* fp = fopen("inputLab9.txt","r");
if(!fp) {
	printf("file not found!\n");
	return 0;
}
fseek(fp,0L,SEEK_END);
size=ftell(fp);
rewind(fp);
text=(char*)malloc(sizeof(char)*size);
if(!text) {
	printf("failed to allocate memory!");
	return 0;
}
int result=fread(text,1,size,fp);
if(result!=size){
	printf("read failed!\n");
	return 0;
}
fclose(fp);
node* root =createNode('0');
int i;
for(i=0;text[i]!='\0';i++)
{

int pos;
if(tolower(text[i])>=97  && tolower(text[i])<= 122)
{
	pos=i;
char word[70];
i=sanitize(i,word);
//printf("%s %d\n",word,pos);
insert(root,word,pos);
i--;
}
}
printTrie(root);
return 0;
}
