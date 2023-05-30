//teste getchar EOF.c
#include <stdio.h>
#include <ctype.h> // para usar a funcao tolower

int main()
{


    int c;

    printf("Estou no getchar!");

    while ((c = getchar()) != EOF) //Termina com ctrl + d
        putchar(tolower(c)); //converte para minusculo

    return 0;

}