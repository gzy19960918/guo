#include <stdio.h>
#include <stdlib.h>

union ab{
	int a;
	char b;
};

int main(){
	union ab one;
	one.a=1;
	printf("%d, %c\n", one.a, one.b);
	printf("%p, %p\n",one.a, one.b);
	one.b = '2';
	printf("%d, %c\n", one.a, one.b);
	printf("%p, %p\n",one.a, one.b);
}
