#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funcao que faz Octal para Binario
int octalToBinary(int octalNumber)
{
    int decimalNumber = 0, i=0;
    long long binaryNumber = 0;

    while (octalNumber != 0)
    {
        decimalNumber += (octalNumber % 10) * pow(8,i);
        ++i;
        octalNumber /= 10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }
    printf("Numero binario = %lld\n", binaryNumber);
    
    return 0;
}

// Funcao que faz Octal para Hexadecimal
int octalToHexadecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    char hexadecimalNumber[100];

    while (octalNumber != 0)
    {
        decimalNumber += (octalNumber % 10) * pow(8,i);
        ++i;
        octalNumber /= 10;
    }

    i = 0;

    while (decimalNumber != 0)
    {
        hexadecimalNumber[i] = decimalNumber % 16;
        decimalNumber /= 16;
        ++i;
    }

    printf("Numero hexadecimal = ");

    for (int j = i - 1; j >= 0; --j)
    {
        if (hexadecimalNumber[j] > 9)
        {
            printf("%c", hexadecimalNumber[j] + 55);
        }
        else
        {
            printf("%d", hexadecimalNumber[j]);
        }
    }

    return 0;
}

int main(void)
{
    int octalNumber;
    printf("Digite um numero octal: ");
    scanf("%d", &octalNumber);
    octalToBinary(octalNumber); // Chamada da funcao já imprimindo o resultado
    octalToHexadecimal(octalNumber); // Chamada da funcao já imprimindo o resultado
    return 0;
}