/******************************************************************************

Escrever um algoritmo que leia 50 n�meros inteiros e imprima todos que forem maiores que a m�dia simples dos numeros lidos.

Plano:
Devo ler 50 numeros e guarda-los em um vetor;
Cada numero lido deve ser somado com seus antecessores;
dividir a soma por 50 (m�dia);
para cada n�mero lido devo comparar com a m�dia, toda vez que o n�mero for maior que a m�dia, devo imprimir.
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
    printf("A m�dia vale %d.\n", media);
    for (cont=0;cont<=4;cont=cont+1)
    {
        if (vet[cont] > media)
        {
            printf("O n�mero %d � maior que a m�dia.\n", vet[cont]);
        }
    }
}


