#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerString(char **str) 
{
    size_t bufferSize = 1024; // Tamanho do buffer 
    *str = (char *)malloc(bufferSize * sizeof(char));
    
    printf("Insira uma string: ");
    fgets(*str, bufferSize, stdin); // Ler a string do teclado
    
    if ((*str)[0] == '\n') 
    {
        free(*str);
        *str = NULL;
    }
}

void converteCharEscape(char *str, char **stringConvertida) 
{
    if (str == NULL) 
    {
        *stringConvertida = NULL;
        return;
    }
    
    size_t len = strlen(str);
    *stringConvertida = (char *)malloc((2 * len + 1) * sizeof(char)); // Aloca memória para a string convertida
    
    int j = 0;
    for (size_t i = 0; i < len; i++) 
    {
        switch (str[i]) 
        {
            case '\t':
                (*stringConvertida)[j++] = '\\';
                (*stringConvertida)[j++] = 't';
                break;
            case '\f':
                (*stringConvertida)[j++] = '\\';
                (*stringConvertida)[j++] = 'f';
                break;
            case '\v':
                (*stringConvertida)[j++] = '\\';
                (*stringConvertida)[j++] = 'v';
                break;
            case '\n':
                (*stringConvertida)[j++] = '\\';
                (*stringConvertida)[j++] = 'n';
                break;
            case '\r':
                (*stringConvertida)[j++] = '\\';
                (*stringConvertida)[j++] = 'r';
                break;
            default:
                (*stringConvertida)[j++] = str[i];
        }
    }
    (*stringConvertida)[j] = '\0'; // Chegou no Null entao acabou a string
}

void printString(char *str) 
{
    if (str == NULL) 
    {
        printf("Linha vazia inserida. Programa finalizado.\n");
        return;
    }
    
    printf("String convertida: %s\n", str);
}

int main() {
    char *str = NULL;
    while (1) 
    {
        lerString(&str);
        
        char *stringConvertida;
        converteCharEscape(str, &stringConvertida);
        
        printString(stringConvertida);
        
        free(str); // Libera memória alocada por getline
        free(stringConvertida);
        
        if (str == NULL) 
        {
            break;
        }
    }
    
    return 0;
}
