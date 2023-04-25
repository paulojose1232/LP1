/******************************************************************************
Escrever um algoritmo que leia n�meros inteiros para dois vetores 
com 5 elementos cada e apresente o resultado de

somat�rio5i=1(a[i]+b[6-1])
*******************************************************************************/
#include <stdio.h>

int main()
{
    int vet[5], vet1[5];
    int conttras, soma, cont;
conttras = 4;
soma = 0;
for (cont=0;cont<=4;cont=cont+1)
{
    printf("Insira o elemento do vetor 1: ");
    scanf("%d", &vet[cont]);
}
for (cont=0;cont<=4;cont=cont+1)
{
    printf("Insira o elemento do vetor 2: ");
    scanf("%d", &vet1[cont]);
}
for (cont=0;cont<=4;cont=cont+1)
{
    soma = vet[cont] + vet1[conttras] + soma;
    conttras = conttras - 1;
}
printf("A soma vale %d", soma);
return 0;
}