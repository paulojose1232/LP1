/******************************************************************************
Exercicio 2 da lista:
Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via teclado, é ou 
não primo.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int n, i, teste;
    teste = 0;
    printf("Insira o numero para verificar se e primo: ");
    scanf("%d", &n);
    
    if (n==0 || n==1)
    {
        teste = 1;
    }
    
    for (i=2;i<=n/2;i=i+1)
    {
        if (n % i == 0)
        {
            teste = 1;
            break;
        }
    }
	if (teste == 0)
	{
    	printf("%d e numero primo.",n);
	}
	else
	{
    	printf("%d nao e numero primo.",n);
	}
return 0;
}
