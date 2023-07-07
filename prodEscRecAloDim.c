#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int vetinput(float **vet, char nome[]) // Recebe o endereço de memória do ponteiro para o vetor e o nome do arquivo de entrada 
{
	FILE *arquivo;
	char tamStr[6]; // Número de elementos do vetor, 5 casas decimais + \n
	char num[50];
	int tamInt;
	int i = 0;

	if ((arquivo = fopen(nome, "r")) != NULL) 
	{
		fgets(tamStr, sizeof(tamStr), arquivo);
		tamInt = atoi(tamStr);

		*vet = (float *)malloc(tamInt * sizeof(float)); // Aloca a memória necessária para o vetor 

		while (feof(arquivo) == 0) 
		{
			fgets(num, sizeof(num), arquivo);
			(*vet)[i] = atof(num); // Atribui o valor lido do arquivo para o vetor 
			i++;
		}
	} 
	else 
	{
		return 0;
	}
	fclose(arquivo);

	return tamInt;
}

float escalar(float vet1[], float vet2[], int i) 
{
	if (i >= 0) 
	{
		return (vet1[i] * vet2[i] + escalar(vet1, vet2, i - 1));
	}

	return 0;
}

int main(void) 
{
	char nome1[50];
	char nome2[50];
	float *vet1 = NULL; // Ponteiro para o vetor 1 
	float *vet2 = NULL; // Ponteiro para o vetor 2
	int tam1;
	int tam2;
	long double prod;

	scanf("%s", nome1);
	scanf("%s", nome2);

	tam1 = vetinput(&vet1, nome1); // Passa o endereço de memória do vetor para a função vetinput
	tam2 = vetinput(&vet2, nome2); 
	
	if (tam1 == 0) 
	{
		printf("Erro: arquivo do vetor 1 nao foi encontrado\n");
		return 1;
	}
	if (tam2 == 0) 
	{
		printf("Erro: arquivo do vetor 2 nao foi encontrado\n");
		return 1;
	}
	if (tam1 == tam2) 
	{
		prod = escalar(vet1, vet2, tam1);
		printf("%.3Lf\n", prod);
	} 
	else 
	{
		printf("Erro: os vetores possuem comprimentos distintos\n");
	}

	free(vet1); // Libera a memória alocada para os vetores 
	free(vet2);

	return 0;
}