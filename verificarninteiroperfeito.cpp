/*
Exercicio 3 da lista:
Um inteiro perfeito n � igual a soma de todos os seus divisores pr�prios. A faixa de seus divisores 
pr�prios vai de 1 a (n-1). Por exemplo : 6 � um inteiro perfeito; 
a soma de todos os seus divisores pr�prios 
(1 + 2 + 3) � igual a 6. Escreva um programa em C que determine se um n�mero no intervalo de 1 a 32767 � 
um inteiro perfeito.

Plano: Ler um n�mero n entre 1 e 32767.
Ent�o se eu ler o n�mero n devo dividir n por (1 at� n/2) e se o resto dessa divis�o for 0, devo guardar 
esse n�mero. Depois pego os divisores que fez o resto dar 0 e somo-os, em seguida comparo com o n�mero n
se for igual, imprimir indicando que � inteiro perfeito, caso contr�rio diga que n�o � inteiro perfeito.
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
    printf("\nO n�mero inserido n�o � v�lido");
}
if (teste == 0)
{
    printf("\nO n�mero � inteiro perfeito");    
}
if (teste == 2)
{
    printf("\nO n�mero n�o � inteiro perfeito");    
}
}
    
