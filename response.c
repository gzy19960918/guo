#include "gzy.h"
/* 
 * It judge which operator was put in and make sure it can work.
 */
void contrast(char *s, table **t)
{
	printf("If you want to select or write, split with ' '\n");
	if(memcmp(s, "write", 5) == 0){
		int i, j, x;
		printf("Write down the index:");
		scanf("%d %d", &i, &j);
		getchar();
		printf("Write down the values: ");
		scanf("%d", &x);
		getchar();
		write(t, i, j, x);
	}else if(memcmp(s, "read", 4)==0){
		read(*t);
	}else if(memcmp(s, "find", 4) == 0){
		int i, j;
		printf("Write down the indexes you would like to select.");
		scanf("%d %d", &i, &j);
		getchar();
		find(*t, i, j);
	}else if(memcmp(s, "create", 6) == 0){
		create(t);
	}else if(memcmp(s, "save", 4) == 0){
		save(*t);
	}else if(memcmp(s, "clear", 5) == 0){
		system("clear");
	}else{
		printf("We havn't applied this opperator, please try again later.\n");
		exit(-1);
	}
}
/*
 * Create a table.
 */
void create(table **t)
{
	(*t)->val = malloc(sizeof(int*));
	(*t)->val[0] = malloc(sizeof(int));
	(*t)->record = 0;
	(*t)->attribute = malloc(sizeof(int));
	(*t)->attribute[(*t)->record] = 0;
}
/* Write data in it. */
void write(table **t, int i, int j, int x)
{
	if((*t)->record < i){
		(*t)->val = realloc((*t)->val, (i+1) * sizeof(int*));
		(*t)->val[i] = malloc((j+1) * sizeof(int));
		(*t)->record = i;
		(*t)->attribute = realloc((*t)->attribute, (i+1) * sizeof(int));
		(*t)->attribute[i] = j;
	}else if((*t)->attribute[i] < j){
		(*t)->val[i] = realloc((*t)->val[i], (j+1)*sizeof(int));
		(*t)->attribute[i] = j;
	}
	(*t)->val[i][j] = x;
}
/* Print all of the data we wrote. */
void read(table *t)
{
	for(register int i=0; i <= t->record; i++){
		printf("db[%d]: ", i);
		for(register int j = 0; j <= t->attribute[i]; j++){
			printf("%-4d", t->val[i][j]);
		}
		printf("\n");
	}
}
/* Find the value with the index we put in. */
void find(table *t, int i, int j)
{
	if(i > t->record || j > t->attribute[i]){
		printf("You select a bad index! Please use read to check it\n");
		exit(0);
	}
	printf("The values you searched to is: %4d\n", t->val[i][j]);
}

