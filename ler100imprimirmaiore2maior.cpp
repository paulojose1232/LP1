/******************************************************************************
Progama: Ler 100 n�meros inteiros distintos e no final imprimir o maior n�mero e o segundo maior n�mero.

Plano: devo ler um n�mero e consider�-lo como sendo o maior n�mero, depois leio mais um n�mero e comparo
o primeiro com o segundo. O maior deles � guardado e leio mais um n�mero em seguida at� o final dos 100.
Finalmente imprimo o n�mero guardado no final que ser� o maior.

*******************************************************************************/
#include <stdio.h>

int main()
{
int numero1, numero2, m1, m2, numero3, cont;
printf("Digite um n�mero: ");
scanf("%d", &numero1);
m1 = numero1;
printf("Digite um n�mero: ");
scanf("%d", &numero2);
if (numero2 < numero1)
{
    m2 = numero2;
}
if (numero2 > numero1)
{
    m1 = numero2;
    m2 = numero1;
}
for(cont=1;cont<4;cont++)
    {
    printf("Digite um n�mero: ");
    scanf("%d", &numero3);
    if (numero3 > m1)
    {
    m2 = m1;
    m1 = numero3;
    }
    if ((numero3 > m2) && (numero3 < m1))
    {
    m2 = numero3;
    }
    }
printf("\nO maior n�mero �: %d", m1);
printf("\nO segundo maior n�mero �: %d", m2);
return 0;
}

