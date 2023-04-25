#include <stdio.h>
int main ()
{
int a, b;
printf("Digite o valor em celsius\n");
scanf("%d", &a);
b = ((a * 1.8) + 32);
printf("O valor em fahrenheit:%d", b);
return 0;
}