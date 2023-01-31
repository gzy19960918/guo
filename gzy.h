#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
	int **val;
	int record;
	int *attribute;
}table;

typedef struct{
	table *tab;
	int *sheet;
}database;

void contrast(char *s, table **t);
void create(table **t);
void write(table **t, int i, int j, int x);
void read(table *t);
void find(table *t, int i, int j);
char *getoper();
void manager(table **t);
void save(table *t);
