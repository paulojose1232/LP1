#include <stdio.h>

int maxmin(int *, int *);

int main(void)
{
	int a, b;
	a = 1;
	b = 3;
	
	printf("Antes a == %d, b == %d\n", a, b);
	
	maxmin(&a, &b);

	printf("Depois a == %d, b == %d\n", a, b);
}

int maxmin(int *x, int *y)
{
	int temp;
	
	if (*y>*x)
	{
		temp = *x;
		*x = *y;
		*y = temp;
		
	}
	printf("Dentro &a == %p, &b == %p\n", &x, &y); //endereco de memoria de x e y
}
