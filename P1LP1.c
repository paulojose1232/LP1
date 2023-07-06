// Na linha 71, pode-se colocar fgets dentro do while e por no lugar:
// while (feof(arquivo) == 0)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int fatorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fatorial(n-1);
}

int coef2(int n)
{
    int i;
    int x1, x2, x3, x4, x5, x6;

    for (i = 0; i <= n; i++)
    {
        x1 = (n + i - 1);
        x2 = (fatorial(x1));
        x3 = (fatorial(i));
        x4 = (n-1);
        x5 = (x3*fatorial(x4));
        x6 = (x2/x5);
    }

    x6 = x6*2;

    return x6;
}


int coef1(int n, int i)
{
    int x1, x2, x3, x4, x5, x6;

    if (i == -1)
    {
        return 0;
    }

    x1 = (n + i - 1);
    x2 = (fatorial(x1));
    x3 = (fatorial(i));
    x4 = (n-1);
    x5 = (x3*fatorial(x4));
    x6 = (x2/x5);

    return x6 + coef1(n, i-1);
}


int main (void)
{
    int number, cont;
    int n, i;
    char linha[100];
    FILE *arquivo;

    arquivo = fopen("entrada.txt", "r");
    printf("n----------coeficientes\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';
        n = atoi(linha);
        printf("%d", n);
        printf("----------%d\n", coef2(n));
        //i = n; // Para rodar o iterativo, tire os comentarios dessa linha e da linha de baixo
        //printf("----------%d\n", coef1(n, i));
    }
    fclose(arquivo);

    return 0;
}
