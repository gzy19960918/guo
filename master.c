#include "gzy.h"
/* In this function, we use manager in file named "iando.c"*/
int main()
{
	table *t = malloc(sizeof(table));
	while(1){
		manager(&t);
	}
	return 0;
}
