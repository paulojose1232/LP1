/*
Exercicio 5 da lista:
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
printf("Aviso, mínimo de R$0,01 e máximo de R$1,00.\n");
printf("Atenção, siga o exemplo abaixo: \n");
printf("exemplo > 50 centavos > Digite 50.\n");
printf("Digite o valor do troco: \n");
scanf("%d", &n);
if (n>=101 || n==0)
{
    printf("Número inserido não é válido.");
    n = 0;
}
if (n/100 == 1)
{
   printf("1 moeda de 1 real.\n");
   n = n%100;
}
if (n/50 >= 1)
{
    printf("%d moeda(s) de 50 centavos, ", n/50);
    n = n%50;   
}
if (n/25 >= 1)
{
    printf("%d moeda(s) de 25 centavos, ", n/25);
    n = n%25;
}
if (n/10 >= 1)
{
    printf("%d moeda(s) de 10 centavos, ", n/10);
    n = n%10;
}
if (n/5 >= 1)
{
    printf("%d moeda(s) de 5 centavos, ", n/5);
    n = n%5;
}
if (n/1 >= 1)
{
    printf("%d moeda(s) de 1 centavo.", n/1);
    n = n%1;
}
}

