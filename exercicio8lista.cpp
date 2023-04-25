/******************************************************************************
Exercicio 8 da lista:

Para um vetor A de 50 números inteiros, escrever um programa em C que determine o maior e o segundo 
maior elemento desse vetor. Assumir que todos os elementos são distintos.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int cont1, cont2, aux;
    int vet[50];
    aux = 0;
    printf("Insira os elementos do vetor A (50 elementos)\n");
    for (cont1=0;cont1<=49;cont1=cont1+1)
    {
        scanf("%d", &vet[cont1]);
    }
    
    for (cont1=0;cont1<=49;cont1=cont1+1)
    {
        for (cont2=cont1+1;cont2<=49;cont2=cont2+1)
        {
            if (vet[cont1]>vet[cont2])
            {
                aux = vet[cont2];
                vet[cont2]=vet[cont1];
                vet[cont1]= aux;
            }
          
        }
    }
    printf("O maior e o segundo maior elemento do vetor A é: ");
    printf("%d, %d.", vet[49], vet[48]);
}

