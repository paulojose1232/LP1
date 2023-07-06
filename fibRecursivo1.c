#include <stdio.h>

int fibonacci(int n)
{
    if (n<2 && n>=0)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main (void) 
{
	int i, j;
	printf("Entre com um numero:");
	scanf("%d", &i);
	
	j = fibonacci(i);
	
	printf("%d", j);
}