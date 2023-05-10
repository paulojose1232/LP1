#include <stdio.h>

int main()
{
    char ch1, ch2;
    printf("Introduza um caracter: ");
    scanf("%c", &ch1);
    printf("Introduza outro caracter: ");
    scanf(" %c", &ch2); // o espaço antes do %c é necessário para ignorar o \n
    printf("Os caracteres introduzidos foram '%c' e '%c'", ch1, ch2);
    return 0;
}