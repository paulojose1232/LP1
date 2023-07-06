#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int vetinput(float vet[], char nome[])
{ 
	FILE *arquivo;
	char tamStr[6]; // Número de elementos do vetor, 5 casas decimais + \n
	char num[50];
	int tamInt;
	int i = 0;
	
	if ((arquivo = fopen(nome,"r")) != NULL)
	{
    	fgets (tamStr, sizeof(tamStr), arquivo);
    	//tamStr[strcspn(tamStr, "\n")] = '\0';
	    tamInt = atoi(tamStr);
	
	    while (feof(arquivo) == 0)
	    {
		    fgets (num, sizeof(num), arquivo);
		    //num[strcspn(num, "\n")] = '\0';
		    vet[i] = atof(num);
		    i++;
		}
	} 
	else
	{
		return 0;
	}
	fclose (arquivo);
	
	return tamInt;
}