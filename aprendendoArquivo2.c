// fgets com stdin lê uma string com input do usuário 
// fgets com arquivo existente faz a leitura de uma string sem input do usuário
// std = standard
// Usando stdbool.h, invés de 1 e 0 (linha 16), pode-se usar true e false respectivamente. 

#include <stdio.h>
#include <string.h>

int main (void)
{
    char cadeia[100];

    FILE *arquivo;
    arquivo = fopen("arquivoTeste.txt", "w");

    while (1) // loop infinito até que o usuário digite ctrl+d ou ctrl+c ou ctrl+z (EOF)
    {
        printf("> ");

        if (fgets(cadeia, sizeof(cadeia), stdin) == NULL) // fgets retorna NULL quando o usuário digita ctrl+d ou ctrl+c ou ctrl+z (EOF)
            break;

        cadeia[strcspn(cadeia, "\n")] = '\0'; // remove o \n da string cadeia, sem isso o programa não para de ler e entra em loop infinito
        
        fprintf(arquivo, "%s\n", cadeia); // escreve a string cadeia no arquivo
    }
    fclose(arquivo);

    printf("Executado com sucesso.\n");

    return 0;
}