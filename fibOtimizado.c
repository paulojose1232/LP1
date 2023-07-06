#include <stdio.h>

int fib (int n);

int main (void)
{
    int num;
    printf("Insira um numero inteiro positivo: ");
    scanf("%d", &num);

    printf("O termo %d da sequencia de Fibonacci vale %d\n", num, fib(num));
}

int fib (int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    
    return fib(n - 1) + fib(n - 2);
}