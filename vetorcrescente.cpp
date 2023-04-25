/******************************************************************************

Escrever um algoritmo que leia 100 numeros inteiros e distintos e imprima os numeros lidos em ordem crescente.

Plano:

*******************************************************************************/
#include <stdio.h>

int main()
{
    int soma,cont1, cont2,aux, outroaux;
    float media;
    int vet[5];
    soma = 0;
    media = 0;
    aux = 0;
    outroaux=0;
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        scanf("%d", &vet[cont1]);
        soma = soma + vet[cont1];
    }
    
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
      outroaux=outroaux+1;
      cont2=outroaux;
        for (cont2=outroaux;cont2<=4;cont2=cont2+1)
        {
            if (vet[cont1]>vet[cont2])
            {
                aux = vet[cont2];
                vet[cont2]=vet[cont1];
                vet[cont1]= aux;
            }
          
        }
    }
    printf("O vetor ordenado é assim: ");
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        printf("%d, ", vet[cont1]);
    }
}

