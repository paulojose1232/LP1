//arquivo usando scanf
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   FILE * arquivo;
   char nome[100];
   char mensagem[100];

   printf("Entre com o nome do arquivo: ");
   scanf("%s", nome);

   printf("Entre com a mensagem: ");
   scanf("%s", mensagem);

   arquivo = fopen("nome", "w");

   fprintf(arquivo, "%s", mensagem);

   fclose(arquivo);

    return 0;
}