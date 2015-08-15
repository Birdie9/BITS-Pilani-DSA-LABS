#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DriverHashOps.h"
#include "PoliceTreeOps.h"


static inline int countLines(FILE *fp)
{

char c;
int count=0;

do{
		c=fgetc(fp);
		if(c == '\n')
				count++;
} while (c!= EOF);

return count;
}



int main(int argc, char *argv[])
{
		FILE * fp;
		int line_count, i;
#define BUF_SIZE 100
		char buffer[BUF_SIZE];

		DriverHash dh;
		PoliceTree root = NULL;

		if(argc != 2)
		{
				fprintf(stderr, "Usage: %s <filename>", argv[0]);
				exit(-1);
		}

		fp= fopen(argv[1], "r");

		line_count = countLines (fp);
		printf("\n No of lines in %s is %d\n", argv[1], line_count);

		rewind(fp);

	//  initialize the data structures....
		initializeHash(dh);
		root=NULL;

	// Take input from the files...
		for (i=0; i< line_count; i++)
		{
				int len,ret;
				int id, l, amount;
				PoliceId pid;
				License lic;


				fgets(buffer, BUF_SIZE, fp);
				buffer[BUF_SIZE-1] = '\0'; // for safety
				len=strlen(buffer);
				if (buffer[len-1] == '\n')
					buffer[len-1]='\0';
				len=strlen(buffer); // for dealing with empty lines
				printf("Reading line %d: %s =>( %d ) \n",i, buffer, len);
				ret=sscanf(buffer,"%d,%d,%d", &id, &l, &amount);
				if(ret< 3)// for dealing with empty lines
				{
						printf("last line was incomplete line\n");
						break;
				}
				pid = (PoliceId) id;
				lic = (License) l;
				// populate the data structures
				insertHash(dh, l);
				root = insertByPoliceId(root, pid, amount);
/*		printf("Current tree is: \n");
		printPoliceTree(root);
		printf("\n");
*/
		}
		fclose(fp);

// do real work.

		printf("Current tree is: \n");
		printPoliceTree(root);
		printf("\nReorder by fine amount\n");
		root=reorderByFineAmount(root);
		printf("\nAfter reordering the tree is: \n");
		printPoliceTree(root);
		printViolators(dh);
		printf("\nPrinted Violators.\n");

		printPoliceTree(root);

		printBonusPolicemen(root);
		printf("\nPrinted bonus.\n");

// destroy the DS
		destroyPoliceTree(root);
		destroyHash(dh);
		
	return 0;
}
