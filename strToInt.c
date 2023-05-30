// Converte String para Inteiro (numeros tem que vir na frente).

#include <stdio.h>

int atoi(char s[]);

int main(void) 
{
	char str[100];
	int i;
	
	printf("Entre com uma string: ");
	scanf("%s", str);
	i = atoi(str);
	printf("O numero e: %d \n", i);
	
	return 0;
}

/* atoi: convert s to integer */
int atoi(char s[]){
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}