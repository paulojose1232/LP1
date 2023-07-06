#include <stdio.h>

int SomaVet(int vetor[], int i);

int main(void)
{
    int i, k;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &k);
    int vetor[k];
    printf("Agora insira os elementos do vetor (valores inteiros): ");
    for (i = 0; i<k; i++)
    {
        scanf("%d", &vetor[i]);
    }
    printf("A soma dos vetores vale: %d", SomaVet(vetor, k));
}

int SomaVet(int vetor[], int i)
{
    if (i == 0)
    {
        return 0;
    }
    else
    {
        return vetor[i-1] + SomaVet(vetor, i-1);
    }
}
