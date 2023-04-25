/******************************************************************************
Progama: Ler 100 números inteiros distintos e no final imprimir o maior número.

Plano: devo ler um n e considerá-lo como sendo o maior número, depois leio mais um número e comparo
o primeiro com o segundo. O maior deles é guardado e leio mais um número em seguida até o final dos 100.
Finalmente imprimo o número guardado no final que será o maior.

*******************************************************************************/
#include <stdio.h>

int main()
{
int n, m, cont;
m = 0;
for(cont=1;cont<101;cont++)
    {
        scanf("%d", &n);
        if (n > m) 
        m = n;
    }
printf("%d", m);
    return 0;
}

