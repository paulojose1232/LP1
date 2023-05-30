// Converte String para Inteiro (numeros tem que vir na frente) usando ponteiros.

#include <stdio.h>

void atoi(char s[], int* n);

int main(void) 
{
	char str[100];
	int i;
	
	printf("Entre com uma string: ");
	scanf("%s", str);
	atoi(str, &i);
	printf("O numero e: %d \n", i);
	
	return 0;
}

void atoi(char s[], int*n){
	int i;
	*n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		*n = 10 * *n + (s[i] - '0');
}