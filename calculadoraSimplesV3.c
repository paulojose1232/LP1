#include <stdio.h>

int main()
{
char operando;
int escolha;
float num1, num2;
int flag = 0;

while (flag == 0)
{
printf("Escolha o operando: ");
scanf("%s", &operando);
printf("\nEscolha o primeiro numero: ");
scanf("%f", &num1);
printf("\nEscolha o segundo numero: ");
scanf("%f", &num2);
switch(operando)
{
    case '+':
        printf("A soma dos numeros e: %f",num1+num2);
        break;
    case '-':
        printf("A subtracao dos numeros e: %f",num1-num2);
        break;
    case '*':
        printf("A multiplicacao dos numeros e: %f",num1*num2);
        break;
    case '/':
        printf("A divisao dos numeros e: %f",num1/num2);
        break;
}
    printf("\nDeseja continuar? (1 para sim ou 0 para nao)");
    scanf("%d", &escolha);
    if (escolha == 1)
    {
        flag = 0;
    }
    if (escolha == 0)
    {
        flag = 1;
    }
}
return 0;
}