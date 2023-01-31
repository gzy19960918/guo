#include "gzy.h"
/* We get an opertor from scanf. */
char *getoper(){
	char *s = malloc(30*sizeof(char));
	printf("What would you like to do?\n");
	scanf("%s", s);
	getchar();
	return s;
}
/* We pass it to function "contrast" in file "response.c". */
void manager(table **t)
{
	char *s = getoper();
	contrast(s, t);
}
/* This function save current data to file "table", but if we wouldn't 
 * restert programe, it will product duplicate data, it's not good enough. */
void save(table *t)
{
	FILE *f = NULL;
	f = fopen("table", "a");
	for(register int i=0; i <=t->record; i++){
		if(sizeof(t->val[i]) < sizeof(int*)){
			continue;
		}
		for(register int j=0; j <= t->attribute[i]; j++){
			if(t->val[i][j] >= 0){
				fprintf(f, "%d\t", t->val[i][j]);
			}
		}
		fputs("\n", f);
	}
	fclose(f);
}
