/******************************************************************************

Escrever um algoritmo que leia 50 números inteiros e imprima todos que forem maiores que a média simples dos numeros lidos.

Plano:
Devo ler 50 numeros e guarda-los em um vetor;
Cada numero lido deve ser somado com seus antecessores;
dividir a soma por 50 (média);
para cada número lido devo comparar com a média, toda vez que o número for maior que a média, devo imprimir.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int soma,media,cont;
    int vet[5];
    soma = 0;
    media = 0;
    for (cont=0;cont<=4;cont=cont+1)
    {
        scanf("%d", &vet[cont]);
        soma = soma + vet[cont];
    }
        media = soma/5;
    printf("A média vale %d.\n", media);
    for (cont=0;cont<=4;cont=cont+1)
    {
        if (vet[cont] > media)
        {
            printf("O número %d é maior que a média.\n", vet[cont]);
        }
    }
}


