//Fibonacci com numero de chamadas e argumentos

#include <stdio.h>

int nChamadas = 0;
int chamada[100];

int fibonacci(int n)
{
    nChamadas++;
    chamada[n]++;
    if (n<2 && n>=0)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main (int argc, char *argv[])
{
    int n, f, k, l, i;

    for (i=0; i<argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    if (argc>1)
    {
        sscanf(argv[1], "%d", &l);
    }
    else{
        printf("Entre com um numero: ");
        scanf("%d", &l);
    }

    //f = fibonacci(n);
    for (n=0; n<=l; n++)
    {
        printf("%d ", fibonacci(n));
        printf("\n");
    }
    printf("f_%d=%d\n", n, f);

    printf("Numero de chamadas = %d\n", nChamadas);

    for (k=0;k<=n;k++)
    {
        printf("f_%d=%d\n", k, chamada[k]);
    }
    printf("\n");
}