/*
 O troco em moedas é uma combinação de moedas com os seguintes valores : 
R$ 1,00 ; 0,50; 0,25; 0,10; 0,05; 0,01 
 Escreva um programa em C que leia qualquer valor em centavos (R$0,01 até R$1,00). Calcule e imprima 
seu equivalente em moedas. Encontre a solução que utilize o menor número possível de moedas. 

*/

#include <stdio.h>

int main()
{
int n, resultado, x, y, z, a, b, c, d, e, f, g;
x = 0;
printf("Digite o valor do troco: \n");
printf("Atenção, siga o exemplo abaixo: \n");
printf("exemplo > 2 reais 50 centavos > Digite 250.\n");
scanf("%d", &n);
if (n%100 >= 1)
{
    x = n/100;   
    printf("%d moedas de 1 real, ", x);
    x=x*100;
    n = n - x;
}
if (n%50 >= 1)
{
     x = n/50;   
    printf("%d moedas de 50 centavos, ", x);
    x=x*10;
    n = n - x;
}
if (n%25 >= 1)
{
     x = n/25;   
    printf("%d moedas de 25 centavos, ", x);
    x=x*10;
    n = n - x;
}
if (n%10 >= 1)
{
     x = n/10;   
    printf("%d moedas de 10 centavos, ", x);
    x=x*10;
    n = n - x;
}
if (n%5 >= 1)
{
     x = n/5;   
    printf("%d moedas de 5 centavos, ", x);
    n = n - x;
}
if (n%1 >= 0)
{
     x = n/1;   
    printf("%d moedas de 1 centavo.", x);
    n = n - x;
}
return 0;
}
