/*
Exercicio 9 da lista:

Escrever um programa em C que calcule e imprima o número de caracteres distintos presentes em uma 
cadeia de caracteres dada. Considerar o tamanho máximo da cadeia como sendo de 80 colunas.
*/
#include <stdio.h>
#include <string.h>

 int main()
 {
    char cadeia[80];
    gets(cadeia);
    int cont1, cont2, x = 0;
    int tamcadeia = strlen(cadeia);
     for(cont1=0; cont1<tamcadeia; cont1=cont1+1)
     {
        int flag=0;
        for(cont2=0; cont2<cont1; cont2=cont2+1)
        {
            if(cadeia[cont1]==cadeia[cont2])
            {
                flag=1;
                break;
            }
        }
        if(flag==0){
            x = x+1;
        } 
    }
    printf("%d",x);

    return 0;
 }

