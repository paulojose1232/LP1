#include <stdio.h>

void lerString(char* str) {
    printf("Insira uma string (Ctrl+D para termianr): ");
    int caracter;
    int i = 0;
    while ((caracter = getchar()) != EOF) {
        str[i++] = caracter;
    }
    str[i] = '\0';
}

void converteString(const char* input, char* output) {
    while (*input) {
        switch (*input) {
            case '\t':
                *output++ = '\\';
                *output++ = 't';
                break;
            case '\f':
                *output++ = '\\';
                *output++ = 'f';
                break;
            case '\v':
                *output++ = '\\';
                *output++ = 'v';
                break;
            case '\n':
                *output++ = '\\';
                *output++ = 'n';
                break;
            case '\r':
                *output++ = '\\';
                *output++ = 'r';
                break;
            default:
                *output++ = *input;
                break;
        }
        input++;
    }
    *output = '\0';
}

void printString(const char* str) {
    printf("String convertida: %s\n", str);
}

int main() {
    char inputString[100];
    char outputString[200]; // Dobra o tamanho para garantir que cabe a string convertida

    lerString(inputString);
    converteString(inputString, outputString);
    printString(outputString);

    return 0;
}
