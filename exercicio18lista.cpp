/*
Exercicio 18 da lista:

Faça um programa em C se imprima os N primeiros números que sejam primos e 
façam parte da série de Fibonacci.
*/

#include <stdio.h>
int main() 
{
  int i, n, teste,cont1,n2;

  int t1 = 0;
  int t2 = 1;
  cont1 = 0;
  int proxtermo = t1 + t2;

  printf("Insira o numero desejado de termos para a serie de fibonacci e numeros primos: ");
  scanf("%d", &n);
  printf("Série de Fibonacci: %d, %d, ", t1, t2);
  for (i=3;i<=n;i=i+1) 
  {
    printf("%d, ", proxtermo);
    t1 = t2;
    t2 = proxtermo;
    proxtermo = t1 + t2;
  }
  for (cont1=0;cont1<=n;cont1=cont1+1)
{
    teste = 0;
    n2 = cont1;
  if (n2==0 || n2==1)
    {
        teste = 1;
    }
    for (i=2;i<=n2/2;i=i+1)
    {
        if (n2 % i == 0)
        {
            teste = 1;
            break;
        }
    }
	if (teste == 0)
	{
    	printf("\n%d e numero primo.",n2);
	}
	else
	{
    	printf("\n%d nao e numero primo.",n2);
	}
}
  return 0;
}
