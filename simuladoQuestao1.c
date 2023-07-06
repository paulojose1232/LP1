// fgets para quando chega em EOF ou em new line (\n)
// rewind volta para o inicio do arquivo
// Cada linha terá 6 caracteres + 1 para o \n 
// feof retorna 1 quando chega em EOF
// Usando feof para saber quando chega em EOF (End Of File) ao invés de fgets != NULL 
// ocasionará em repetir a ultima linha do arquivo de entrada no arquivo de saída
// caso não haja um \n no final do arquivo de entrada (arq1.txt e arq2.txt)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_LINHA_MAXIMO 7 // = 7 faz com que no arquivo saida tenha new lines entre os numeros, para deixar um seguido do outro aumente o TAMANHO_LINHA_MAXIMO

void compararArquivos (FILE *arquivo1, FILE *arquivo2, FILE  *arquivoSaida)
{
    char linha1[TAMANHO_LINHA_MAXIMO];
    char linha2[TAMANHO_LINHA_MAXIMO];

    while (fgets(linha1, sizeof(linha1), arquivo1) != NULL) // enquanto não chegar em EOF ou em \n
    {
        rewind(arquivo2); // volta para o inicio do arquivo2

        while (fgets(linha2, sizeof(linha2), arquivo2) != NULL) 
        {
            if (strcmp(linha1, linha2) == 0)
            {
                fputs(linha1, arquivoSaida); // escreve no arquivoSaida
                fflush(arquivoSaida); // força a escrita no arquivoSaida (nesse caso não é necessário, mas é uma boa prática)
                break;
            }
        }
    }
}

int main(void)
{
    FILE *arqu1, *arqu2, *saida1;
    
    arqu1 = fopen("arq1.txt", "r");
    arqu2 = fopen("arq2.txt", "r");

    // Teste se os arquivos existem
    if (arqu1 == NULL || arqu2 == NULL)
    {
        printf("Arquivo não existe.\n");
        exit(1);
    }

    saida1 = fopen("saida.txt", "w");

    compararArquivos(arqu1, arqu2, saida1);

    // Se já souber o nome do arquivo saída, escreva direto no printf.
    // Caso seja um inserido pelo usuário, use a varíavel em que
    printf("Os numeros que aparecem em ambos os arquivos foram escritos no arquivo saida.txt\n");

    fclose(arqu1);
    fclose(arqu2);
    fclose(saida1);

    return 0;
}