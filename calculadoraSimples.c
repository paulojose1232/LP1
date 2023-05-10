#include <stdio.h>

int main(void)
{
    char comando;
    double num1, num2;

    printf("Insira um comando (+, -, *, /): ");
    scanf("%c", &comando);
    printf("Insira numero 1: ");
    scanf("%lf", &num1);
    printf("Insira numero 2: ");
    scanf("%lf", &num2);

    switch(comando)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1+num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1-num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1*num2);
            break;
        case '/':
            printf("%.2lf / %.2lf = %.2lf", num1, num2, num1/num2);
            break;
        default:
            printf("Erro, operador nao compativel.");
    }

    return 0;
}