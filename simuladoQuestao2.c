#include <stdio.h>

double SomaRec(double Vet[], int i);

int main (void)
{
    int i = 5;
    int soma;
    double Vet[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("O somatorio é igual a %f", SomaRec(Vet, i) );
}

double SomaRec(double Vet[], int i)
{
    if (i==0)
        return 0;
    else
        return  Vet[i-1] + SomaRec(Vet, i-1);
}

// A recursão executa da seguinte forma:
// Vet[4] + Vet[3] + Vet[2] + Vet[1] + Vet[0] + 0;
