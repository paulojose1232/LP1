#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("Insira uma expressao (exemplo 2.3*3): ");
    scanf("%f%c%f", &num1, &operator, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Resultado: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Resultado: %.2f\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Resultado: %.2f\n", result);
            } else {
                printf("Erro, divisao por zero\n");
            }
            break;
        default:
            printf("Erro, operando invalido.");
            break;
    }

    return 0;
}