#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float calcular(float num1, float num2, char operador) 
{
    switch (operador) 
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else 
            {
                printf("Erro: Divisao por zero\n");
                return 0;
            }
        default:
            printf("Erro: Operador invalido\n");
            return 0;
    }
}

int main() 
{
    char input[100];
    int i;
    printf("Digite uma expressao: ");
    fgets(input, 100, stdin);

    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }
        
    for(i=0; i<strlen(input); i++)
    {
        if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-')
        {
            float num1 = atof(input);
            float num2 = atof(input + i + 1);
            char operador = input[i];
            printf("Resultado: %0.2f\n", calcular(num1, num2, operador));
            break;
        }
    }

    return 0;
}