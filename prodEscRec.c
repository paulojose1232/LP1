#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vetinput.h"
#include "escalar.h"

int main (void)
{
	char nome1[50];
	char nome2[50];
	float vet1[50];
	float vet2[50];
	int tam1;
	int tam2;
	long double prod;
	
	scanf("%s", nome1);
	scanf("%s", nome2);
	
	tam1 = vetinput(vet1, nome1);
	tam2 = vetinput(vet2, nome2);
	
	if (tam1 == 0)
	{
		printf ("Erro: arquivo do vetor 1 nao foi encontrado\n");
		return 1;
	}
	if (tam2 == 0)
	{
		printf ("Erro: arquivo do vetor 2 nao foi encontrado\n");
		return 1;	
	}
	if (tam1 == tam2)
	{
	    prod = escalar(vet1, vet2, tam1);
		printf ("%.3Lf\n", prod);
	} 
	else
	{
		printf ("Erro: os vetores possuem comprimentos distintos\n");
	}
	
	return 0;
}
