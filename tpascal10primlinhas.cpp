// Escrever um algoritmo que imprima as 10 primeiras linhas do triangulo de pascal.

#include <stdio.h>

int main()
{
int matrix[10][10], cont, cont1;
for (cont=0;cont<=9;cont=cont+1)
{
for (cont1=0;cont1<=cont;cont1=cont1+1)
{
    if ((cont1 == 0) || (cont1 == cont))
    {
        matrix[cont][cont1] = 1;
    }
    else 
    {
        matrix[cont][cont1] = matrix[cont-1][cont1-1] + matrix[cont-1][cont1];
    }
}
}
for (cont=0;cont<=9;cont=cont+1)
{
    for (cont1=0;cont1<=cont;cont1=cont1+1)
    {
        printf("%d\n", matrix[cont][cont1]);
    }
}
}

