/******************************************************************************

Escrever um algoritmo que leia 100 numeros inteiros e distintos, faça a média dos números pares e imprima os números pares que possuem valor maior que a média.

Plano: Ler 100 numeros para um vetor
para cada numero lido descobrir se é par > somar com os pares anteriores e contar a qtd
calculo da media 
faço uma comparaçao e todos os numeros que forem pares serao comparados com a media. quando forem maiores que a media, entao devo imprimi-los
*******************************************************************************/
#include <stdio.h>

int main()
{
    int soma, cad, cont1, cont2,aux, outroaux,maisumcontador, mediadospares, somadnv;
    float media;
    int vet[5];
    int outrovetor[5];
    maisumcontador = 0;
    soma = 0;
    somadnv = 0;
    mediadospares = 0;
    media = 0;
    aux = 0;
    outroaux=0;
    cad = 0;
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        outrovetor[cont1] = 0;
        scanf("%d", &vet[cont1]);
        soma = soma + vet[cont1];
    }
    
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        if (vet[cont1]%2==0)
        {
        outrovetor[cad]=vet[cont1];
        maisumcontador=maisumcontador+1;
        cad=cad+1;
        }
    }
    cad = 0;
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        somadnv = somadnv + outrovetor[cad];
        cad = cad+1;
    }
    mediadospares = somadnv/maisumcontador;
    printf("Os pares que possuem valor maior que a média dos pares é: ");
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        if (outrovetor[cont1] > mediadospares)
        {
            printf("%d, ", outrovetor[cont1]);
        }
    }
}