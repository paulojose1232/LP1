#include <stdio.h>

int main(void)
{
    char comando;
    double num1, num2;
    int flag = 0;

    printf("Insira um comando (+, -, *, /): ");
    while (flag == 0)
    {
    scanf("%c", &comando);
    if (comando == '+' || comando == '-' || comando == '*' || comando == '/')
    {
        flag = 1;
    }
    }
    
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
    }

    return 0;
}