#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *arquivo;
    char nomeArquivo[100];
    char conteudoArquivo;
    printf("Insira o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    
    while (feof(arquivo) == 0)
    {
        conteudoArquivo = fgetc(arquivo); 
        printf("%c", conteudoArquivo);
    }

    fclose(arquivo);

    return 0;
}