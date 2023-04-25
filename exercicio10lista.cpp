/*
Exercicio 10 da lista:

Escrever um programa em C que calcule a frequência de uso de cada palavra dentro de uma cadeia de 
caracteres que possui diversas palavras. Considerar o tamanho máximo da cadeia como sendo de 80 
colunas. 
*/

#include<stdio.h>
#include<string.h>

struct dadosPalavras
{
	char palavra[50];
	int quantidade;
};
		
int main()
{
	char frase[200];
	printf("Insira a frase: ");
	gets(frase);
	char primletra,ultletra;
	int vazio, quantpalavras1, tamanho, f;
	vazio=0; 
	tamanho=-1;
	for(int i=0;frase[i]!='\0';i=i+1)
	{
		if(i==0)
		{
			primletra=frase[i];
			if(primletra==' ')
			{ 
			    vazio = vazio - 1; 
			}
		}
		if(frase[i]==' ' && frase[i-1]!=' ')
		{ 
		    vazio = vazio+1; 
		}
		ultletra=frase[i];
		tamanho=tamanho+1;
	}
	if(ultletra==' ')
	{
		vazio = vazio-1;
	}
	quantpalavras1 = vazio+1;
	char palavras[quantpalavras1-1][80];
	int cont=0;
	int k, j;
	k = 0;
	j = 0;
	for(k,j=0;j<=tamanho;j=j+1)
	{
		k=0;
		if(frase[j]!=' ' && (frase[j-1]==' ' || j==0 ) )
		{ 
			f=j;
			while(frase[f]!=' ' && f<=tamanho)
			{
				palavras[cont][k]=frase[f];
				k=k+1;
				f=f+1;
			}
			palavras[cont][k]='\0';
			cont=cont+1;
		}
	}	
	struct dadosPalavras Dados[quantpalavras1]; 
	int quantpalavras2=0;
	int repete;
	for(int i=0;i<quantpalavras1-1;i=i+1)
	{
		repete=0;
		for(int k=i+1;k<quantpalavras1;k=k+1)
		{
			if(strcmp(palavras[i],palavras[k])==0)
			{
				repete=1;
				break;
			}
		}
		if(repete==0)
		{
			strcpy(Dados[quantpalavras2].palavra,palavras[i]);
			quantpalavras2=quantpalavras2+1;
		}
	}
	strcpy(Dados[quantpalavras2].palavra,palavras[quantpalavras1-1]);
	quantpalavras2=quantpalavras2+1;
	int a;
	for(int i=0;i<quantpalavras2;i=i+1)
	{
		a=0;
		for(int j=0;j<quantpalavras1;j=j+1)
		{
			if(strcmp(Dados[i].palavra,palavras[j])==0)
			{
				a=a+1;
			}
		}
		Dados[i].quantidade=a;
	}
	for(int i=0;i<quantpalavras2;i=i+1)
	{
		printf("\n%s - %d\n",Dados[i].palavra,Dados[i].quantidade);
	}	
	return 0;
}

