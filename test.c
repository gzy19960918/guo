#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[]){
	int **a = (int**)malloc(10 * sizeof(int*));
	register int i=0;
	for(; i < 10; i++){
		a[i] = (int*)malloc(sizeof(int*));
		a[i][0] = 1;
	}i--;
	printf("------%d %d------\n", i, a[i][0]);
	a = realloc(a, 20 * sizeof(int*));
	for(i = 10; i < 20; i++){
		a[i] = (int*)malloc(sizeof(int));
		a[i][0] = 1;
	}i--;
	printf("-------%d, %d-------\n", i, a[i][0]);
	return 0;
}
