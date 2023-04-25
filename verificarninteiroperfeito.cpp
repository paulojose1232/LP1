/*
Exercicio 3 da lista:
Um inteiro perfeito n é igual a soma de todos os seus divisores próprios. A faixa de seus divisores 
próprios vai de 1 a (n-1). Por exemplo : 6 é um inteiro perfeito; 
a soma de todos os seus divisores próprios 
(1 + 2 + 3) é igual a 6. Escreva um programa em C que determine se um número no intervalo de 1 a 32767 é 
um inteiro perfeito.

Plano: Ler um número n entre 1 e 32767.
Entõo se eu ler o número n devo dividir n por (1 até n/2) e se o resto dessa divisão for 0, devo guardar 
esse número. Depois pego os divisores que fez o resto dar 0 e somo-os, em seguida comparo com o número n
se for igual, imprimir indicando que é inteiro perfeito, caso contrário diga que não é inteiro perfeito.
*/

#include <stdio.h>

int main()
{
int n, x, teste, y, cont;
y = 1;
x = 0;
scanf("%d", &n);
for(cont=1; cont<=n/2; cont=cont+1)
    {
      if ((n % y) == 0)
        {
       x = x + y;
        }
    y=y+1;
    }
if (x == n)
    teste = 0;
else
    teste = 2;
if (n < 1 || n > 32767)
{
    teste = 1;
}
if (teste == 1)
{
    printf("\nO número inserido não é válido");
}
if (teste == 0)
{
    printf("\nO número é inteiro perfeito");    
}
if (teste == 2)
{
    printf("\nO número não é inteiro perfeito");    
}
}
    
