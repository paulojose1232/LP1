// Conversão de decimal para octal utilizando recursão

#include <stdio.h>

int octal(int i)
{
    int d, r;

    d = i/8;
    r = i%8;

    if (d == 0)
    {
        printf("%d", r);
    }
    else
    {
        octal(d);
        printf("%d", r);//printf antes de octal(d) faz o resultado ser inverso
    }
}

int main(void)
{
int i;
printf("Entre com um numero: ");
scanf("%d", &i);

octal(i);
}
