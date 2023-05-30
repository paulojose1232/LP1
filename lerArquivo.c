#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char filename[100];
    FILE *file;
    char ch;
    int printableChars = 0;
    int totalChars = 0;
    int linhas = 0;

    printf("Entre com o nome do arquivo:  ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro no arquivo %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        totalChars++;

        if (isprint(ch)) {
            printableChars++;
        }

        if (ch == '\n') {
            linhas++;
        }
    }

    printf("Numero de caracteres lidos: %d\n", totalChars);
    printf("Numero de caracteres printaveis lidos: %d\n", printableChars);
    printf("Numero de linhas: %d\n", linhas);

    fclose(file);
    return 0;
}
