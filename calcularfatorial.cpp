/******************************************************************************
Exercicio 4 da lista:
Escreva um programa em C que calcule o fatorial de um n�mero inteiro positivo. 
*******************************************************************************/

#include <stdio.h>
int fatorial (int a);
int main()
{
int a, b, c;
printf("Digite um numero inteiro: ");
scanf("%d", &a);
printf("%d", fatorial(a));    
}
int fatorial(int a)
{
    int d;
    if (a == 0)
    {
        d = 1;
        return (d);
    }
    d = a*fatorial(a-1);
    return (d);
}
