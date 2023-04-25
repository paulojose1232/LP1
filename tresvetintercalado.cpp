/******************************************************************************
Faça um algoritmo que leia dois vetores com 10 elementos cada e gere um terceiro com 20 elementos.
cujos valores deverão ser compostos pelos elementos intercalados dos dois outros vetores.
ao final, imprimir os dois vetores originais e o terceiro vetor com os valores intercalados.
*******************************************************************************/
#include <stdio.h>

int main()
{
 int vet[9], vet1[9], vet2[19];
 int cont1, contador, outrocontador;
 contador = 0;
 outrocontador = 1;
for (cont1=0;cont1<=9;cont1=cont1+1)
{
    printf("Insira o valor do primeiro vetor: ");
    scanf("%d", &vet[cont1]);
    printf("Insira o valor do segundo vetor: ");
    scanf("%d", &vet1[cont1]);
}
for (cont1=0;cont1<=9;cont1=cont1+1)
{
    vet2[contador] = vet[cont1];
    vet2[outrocontador] = vet1[cont1];
    contador = contador + 2;
    outrocontador = outrocontador + 2;
}
for (cont1=0;cont1<=9;cont1=cont1+1)
{
    printf("Primeiro vetor posição %d possui valor %d, ", cont1, vet[cont1]);
}
for (cont1=0;cont1<=9;cont1=cont1+1)
{
    printf("Segundo vetor posição %d possui valor %d, ", cont1, vet1[cont1]);
}
for (cont1=0;cont1<=19;cont1=cont1+1)
{
    printf("Terceiro vetor posição %d possui valor %d, ", cont1, vet2[cont1]);
}
}    
