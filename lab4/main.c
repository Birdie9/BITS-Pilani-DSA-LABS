#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pathlength;
int path_so_far[100][2];
enum Boolean{
false,
true
};
struct maze{
int grid[100][100];
} ;
typedef struct maze maze;
typedef enum Boolean Boolean;
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
 path_so_far[100][2],int cur_idx, int past_i, int past_j)
{
Boolean ret;
if (m.grid[posi][posj]==9)
{

pathlength=cur_idx;
path_so_far[cur_idx][0]=posi;
path_so_far[cur_idx][1]=posj;
return true;
}
if (posi-1>=0 && m.grid[posi-1][posj]!=1 && (past_i!=posi-1 || past_j!=posj))
{ret=findCheese (m, n,posi-1, posj, path_so_far,cur_idx+1, posi, posj);
if (ret==true)
{
path_so_far[cur_idx][0]=posi;
path_so_far[cur_idx][1]=posj;
return true;
}
}
if (posi+1<n && m.grid[posi+1][posj]!=1 &&( past_i!=posi+1 || past_j!=posj))
{ret=findCheese (m, n,posi+1, posj, path_so_far,cur_idx+1, posi, posj);
if (ret==true)
{
path_so_far[cur_idx][0]=posi;
path_so_far[cur_idx][1]=posj;
return true;
}
}
if (posj-1>=0 && m.grid[posi][posj-1]!=1 && (past_i!=posi || past_j!=posj-1))
{ret=findCheese(m, n,posi, posj-1, path_so_far,cur_idx+1, posi, posj);
if (ret==true)
{
path_so_far[cur_idx][0]=posi;
path_so_far[cur_idx][1]=posj;
return true;
}
}
if(posj+1<n && m.grid[posi][posj+1]!=1 && (past_i!=posi||past_j!=posj+1))
{ret=findCheese(m,n, posi, posj+1, path_so_far,cur_idx+1, posi, posj);
if (ret==true)
{
path_so_far[cur_idx][0]=posi;
path_so_far[cur_idx][1]=posj;
return true;
}
}
return false;
}

int main(int argc,char** arg)
{
int i;
maze * mz=(maze*) malloc (sizeof(maze));
int size=createMaze(mz,"input2.txt");
findCheese(*mz,size,0,0,path_so_far,0,-1,-1);
for(i=0;i<=pathlength;i++)
{
printf("%d %d\n", path_so_far[i][0],path_so_far[i][1]);
}
return 0;
}

