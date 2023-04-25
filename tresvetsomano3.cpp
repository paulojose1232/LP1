
/******************************************************************************
Faça um algoritmo que some o conteúdo de dois vetores e armazene o resultado em um terceiro vetor.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int tamanhovetor;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamanhovetor);
 int vet[tamanhovetor], vet1[tamanhovetor], vet2[tamanhovetor];
 int cont1;
for (cont1=0;cont1<=tamanhovetor;cont1=cont1+1)
{
    printf("Insira o valor do primeiro vetor: ");
    scanf("%d", &vet[cont1]);
    printf("Insira o valor do segundo vetor: ");
    scanf("%d", &vet1[cont1]);
}
for (cont1=0;cont1<=tamanhovetor;cont1=cont1+1)
{
    vet2[cont1]=vet[cont1]+vet1[cont1];
    printf("O valor da posição %d do terceiro vetor é: %d, ", cont1, vet2[cont1]);
}
}    
