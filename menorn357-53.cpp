/******************************************************************************
Exercicio 1 da lista:
Escreva um programa em C que encontre o menor inteiro postivo n que atenda as seguintes condições:
n/3 = x inteiro e resto 2
n/5 = y inteiro e resto 3 
n/7 =  z inteiro e resto 4
*******************************************************************************/

#include <stdio.h>

int main()
{
    int a;
    for (a=0;a<=100;a=a+1)
    {
        if (((a % 3) == 2) && ((a % 5) == 3) && ((a % 7) == 4))
        {
            printf("%d", a);
            break;
        }
    }
    return 0;
}
