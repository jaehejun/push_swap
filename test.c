#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int *b;

	int	a;

	a = 5;
	
	//b = (int *)malloc(sizeof(int));
	*b = 3;
	printf("B : %p\n", b);
	printf("B : %d\n", *b);
	printf("A : %p\n", &a);

	b = &a;
	printf("A : %p\n", &a);
	printf("B : %p\n", b);

	return (0);
}