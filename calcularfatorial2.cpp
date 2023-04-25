/*
Escreva um programa em C que calcule o fatorial de um número inteiro positivo. 
*/

#include <stdio.h>

int main()
{
int n, x, y, resultado, cont;
x = 1;
y = 1;
scanf("%d", &n);
for(cont=1;cont<n;cont=cont+1)
{
    x = x * y;
    y = y + 1;
}
resultado = (n*x);
printf("O fatorial de n é: %d", resultado);
return 0;
}
