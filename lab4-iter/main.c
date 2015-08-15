#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pathlength;
int path_so_far[100][2];
enum Boolean{
false,
true
};
struct stack1{
int top;
int mat[100][4];
};
struct maze{
int grid[100][100];
} ;
typedef struct maze maze;
typedef enum Boolean Boolean;
typedef struct stack1 stack1;
int createMaze(maze* mz,char* filename)
{
FILE * fp=fopen(filename,"r");
int i,j, rows=0;
char line[1000];
fgets(line,sizeof(line),fp);
char* token=strtok(line," ");
while(token)
{
rows++;
token=strtok(NULL," ");
}
fclose(fp);
fp=fopen(filename,"r");
for(i=0;i<rows;i++){
for(j=0;j<rows;j++)
{
fscanf(fp,"%d",&(mz->grid[i][j]));
printf("%d ",mz->grid[i][j]);
}printf("\n");
}
return rows;
}

//Boolean done[100][100];

Boolean findCheese(maze m, int n, int posi, int posj, int
 path_so_far[100][2],int past_i, int past_j)
{
    int cur_idx=0;
    int path[100][100][2];
    Boolean ret=false;
    stack1* ptr=(stack1*)malloc(sizeof(stack1));
    stack1 stack=(*ptr);
    stack.top=0;
    stack.mat[0][0]=posi;
    stack.mat[0][1]=posj;
    stack.mat[0][2]=-1;
    stack.mat[0][3]=-1;
while(stack.top>=0 && ret==false){
posi=stack.mat[stack.top][0];
posj=stack.mat[stack.top][1];
past_i=stack.mat[stack.top][2];
past_j=stack.mat[stack.top][3];
path[posi][posj][0]=past_i;
path[posi][posj][1]=past_j;
stack.top--;
cur_idx++;
if (m.grid[posi][posj]==9)
{
ret=true;
break;
}
if (posi-1>=0 && m.grid[posi-1][posj]!=1 && (past_i!=posi-1 || past_j!=posj))
{
    stack.top++;
    stack.mat[stack.top][0]=posi-1;
    stack.mat[stack.top][1]=posj;
    stack.mat[stack.top][2]=posi;
    stack.mat[stack.top][3]=posj;
}
if (posi+1<n && m.grid[posi+1][posj]!=1 &&( past_i!=posi+1 || past_j!=posj))
{
stack.top++;
    stack.mat[stack.top][0]=posi+1;
    stack.mat[stack.top][1]=posj;
    stack.mat[stack.top][2]=posi;
    stack.mat[stack.top][3]=posj;
}
if (posj-1>=0 && m.grid[posi][posj-1]!=1 && (past_i!=posi || past_j!=posj-1))
{
stack.top++;
    stack.mat[stack.top][0]=posi;
    stack.mat[stack.top][1]=posj-1;
    stack.mat[stack.top][2]=posi;
    stack.mat[stack.top][3]=posj;
}
if(posj+1<n && m.grid[posi][posj+1]!=1 && (past_i!=posi||past_j!=posj+1))
{
stack.top++;
    stack.mat[stack.top][0]=posi;
    stack.mat[stack.top][1]=posj+1;
    stack.mat[stack.top][2]=posi;
    stack.mat[stack.top][3]=posj;
}
}
if(ret==true)
{
    int i=0;pathlength=0;
    int curi=posi,curj=posj;
    path_so_far[i][0]=curi;
        path_so_far[i][1]=curj;
        i++;
        pathlength++;
    while(curi!=0 || curj!=0)
    {
        path_so_far[i][0]=path[curi][curj][0];
        path_so_far[i][1]=path[curi][curj][1];
        int curit=path[curi][curj][0];
        int curjt=path[curi][curj][1];
        curi=curit;
        curj=curjt;
        i++;
        pathlength++;
    }
    return true;
}
return false;
}

int main(int argc,char** arg)
{
int i;
maze * mz=(maze*) malloc (sizeof(maze));
int size=createMaze(mz,"input2.txt");
findCheese(*mz,size,0,0,path_so_far,-1,-1);
for(i=pathlength-1;i>=0;i--)
{
printf("%d %d\n", path_so_far[i][0],path_so_far[i][1]);
}
return 0;
}

