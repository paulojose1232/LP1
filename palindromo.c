#include <stdio.h>
#include <string.h>

// Programa em C para checar se uma cadeia é um palíndromo usando fgets.
// Poderia usar a biblioteca ctype.h e então a função tolower e um loop para colocar a string em letra minúscula.

int main(void)
{
	char str1[100];
	char str2[100];
	int igual, i, n;
	
	printf("Entre com uma string: ");	
	fgets(str1,100,stdin);
	
	str1[strcspn(str1, "\n")] = '\0'; // Troca o \n do final da string por um \0.
	
	printf("O tamanho da string é de %ld elementos.\n", strlen(str1));
	
        n = strlen(str1); // Coloco o tamanho da string em uma variável.
	
	for (i=0; i<strlen(str1); i++)
	{
	    str2[i] = str1[n-1]; // Copio os elementos da string para uma outra string só que invertido.
	    n--;
	}

	printf("A string normal é: %s.\n", str1);
	printf("A string invertida é: %s.\n", str2);
    	printf("A string é um palíndromo? ");
    
	igual = strcmp(str2, str1); // Não precisaria usar uma variável, poderia fazer a comparação direto.
	if (igual == 0)
		printf("SIM\n");
	else
		printf("NÃO\n");
    return 0;
}
