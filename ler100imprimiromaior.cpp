/******************************************************************************
Progama: Ler 100 n�meros inteiros distintos e no final imprimir o maior n�mero.

Plano: devo ler um n e consider�-lo como sendo o maior n�mero, depois leio mais um n�mero e comparo
o primeiro com o segundo. O maior deles � guardado e leio mais um n�mero em seguida at� o final dos 100.
Finalmente imprimo o n�mero guardado no final que ser� o maior.

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

