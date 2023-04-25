/******************************************************************************
Exercicio 13 da lista:

Dados três vetores com 10 posições cada um, preenchidos com números inteiros, fazer um programa 
em C que, após a leitura dos vetores coloque-os em ordem crescente.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int cont1, cont2, aux;
    int vet1[10], vet2[10], vet3[10];
    aux = 0;
    
    printf("Insira os elementos do primeiro vetor:\n");
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        scanf("%d", &vet1[cont1]);
    }
    
    printf("Insira os elementos do segundo vetor:\n");
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        scanf("%d", &vet2[cont1]);
    }
    
    printf("Insira os elementos do terceiro vetor:\n");
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        scanf("%d", &vet3[cont1]);
    }
    
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        for (cont2=cont1+1;cont2<=9;cont2=cont2+1)
        {
            if (vet1[cont1]>vet1[cont2])
            {
                aux = vet1[cont2];
                vet1[cont2]=vet1[cont1];
                vet1[cont1]= aux;
            }
        }
    }
    
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        for (cont2=cont1+1;cont2<=9;cont2=cont2+1)
        {
            if (vet2[cont1]>vet2[cont2])
            {
                aux = vet2[cont2];
                vet2[cont2]=vet2[cont1];
                vet2[cont1]= aux;
            }
        }
    }
    
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        for (cont2=cont1+1;cont2<=9;cont2=cont2+1)
        {
            if (vet3[cont1]>vet3[cont2])
            {
                aux = vet3[cont2];
                vet3[cont2]=vet3[cont1];
                vet3[cont1]= aux;
            }
        }
    }
    
    printf("O vetor 1 em ordem crescente é: ");
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        printf("%d, ", vet1[cont1]);
    }
    printf("\nO vetor 2 em ordem crescente é: ");
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        printf("%d, ", vet2[cont1]);
    }
    printf("\nO vetor 3 em ordem crescente é: ");
    for (cont1=0;cont1<=9;cont1=cont1+1)
    {
        printf("%d, ", vet3[cont1]);
    }
}
