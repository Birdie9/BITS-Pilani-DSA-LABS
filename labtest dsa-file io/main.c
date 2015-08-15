#include <stdio.h>
#include <stdlib.h>

#include<string.h>
int main()
{
    char str[50],str2[8];
    FILE * fp= fopen("input.txt","r");
    fgets(str,8,fp);
    fgets(str2,8,fp);
    printf("%s \n%s \n",str,str2);
    fclose(fp);
    fp= fopen("input.txt","r");
    fgets(str,20,fp);
    char* sec=strpbrk(str," ");
    sec++;
    printf("%s",sec);
    printf("*****************\n");
    FILE * fp2=fopen("maze.txt","r");
    char line[100];
    fgets(line,100,fp2);

    char* token=strtok(line," \n");
    int i=0;
    while(token!=NULL)
    {
        i++;
        printf("%s\n",token);
                token=strtok(NULL," ");
    }
    fclose(fp);
    fp2=fopen("maze.txt","r");
    int mat[i][i],k,j;
    for(j=0;j<i;j++)for(k=0;k<i;k++)fscanf(fp2,"%d",&mat[j][k]);
     for(j=0;j<i;j++){for(k=0;k<i;k++)printf("%4d ",mat[j][k]);printf("\n");}
    return 0;
}
