/******************************************************************************
Calcular a combinacao de dois numeros
*******************************************************************************/
#include <stdio.h>

long fatorial (int n);

int main()
{
    int n, s;
    float comb;
    printf("Escolha o valor de n: ");
    scanf("%d", &n);
    printf("Escolha o valor de s: ");
    scanf("%d", &s);
    comb = fatorial (n)/(fatorial (s)*fatorial(n-s));
    printf("%.2f",comb); 
}

long fatorial (int n)
{
    long res;
    if (n==0)
        {
            res = 1;
            return(res);
        }
        res = n*fatorial(n-1);
        return(res);
}