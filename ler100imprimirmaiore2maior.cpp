/******************************************************************************
Progama: Ler 100 números inteiros distintos e no final imprimir o maior número e o segundo maior número.

Plano: devo ler um número e considerá-lo como sendo o maior número, depois leio mais um número e comparo
o primeiro com o segundo. O maior deles é guardado e leio mais um número em seguida até o final dos 100.
Finalmente imprimo o número guardado no final que será o maior.

*******************************************************************************/
#include <stdio.h>

int main()
{
int numero1, numero2, m1, m2, numero3, cont;
printf("Digite um número: ");
scanf("%d", &numero1);
m1 = numero1;
printf("Digite um número: ");
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
    printf("Digite um número: ");
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
printf("\nO maior número é: %d", m1);
printf("\nO segundo maior número é: %d", m2);
return 0;
}

