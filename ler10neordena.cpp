/******************************************************************************
Escrever um programa em C que leia 10 n�meros inteiros distintos e os ordene do menor para o maior
*******************************************************************************/
#include <stdio.h>

#define N 10 

int vetor[N];
int i, j, aux;

int main()
{
for (i=0;i<N;i++)
    {
     printf("\nDigite um n�mero: ");
     scanf("%d", &vetor[i]);
    }
for (i=0;i<(N-1);i++)
    for(j=(i+1);j<N;j++)
        if (vetor[j]<vetor[i])
            {
                aux = vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }
printf("O vetor ordenado �:\n");
for (i=0;i<N;i++)
    {
    printf("%d;",vetor[i]);
    }
return 0;
}
