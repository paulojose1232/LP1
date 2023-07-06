#include <stdio.h>
#include <string.h>

struct funcionario 
{
	char nome[51];
	char matricula[13];
	char endereco[66];
	char cpf[12];
	char cod_banco[4];
	char agencia[6];
	char conta[9];
	float valor_hora;
	float salario_mes;
	int ordem;
};

struct hora 
{
	char matricula[13];
	int horas;
};

void le_funcionario(FILE *, struct funcionario*);
void le_horas(FILE *, struct hora*);
void calc_salario(struct funcionario* funcionarios, struct hora* horas);
void ordena (struct funcionario* funcionarios);
void escreve (struct funcionario* funcionarios);

int main (void) 
{
	struct funcionario funcionarios[10];
	struct hora horas[10];
	FILE *arq_func;
	FILE *arq_horas;
	FILE *arq_folha;
	// Abre arquivos
	arq_func = fopen("Funcionarios.txt", "r");
	arq_horas = fopen("Novembro.txt", "r");
	// Ler funcionarios
	le_funcionario(arq_func, funcionarios);
	// Ler horas
	le_horas(arq_horas, horas);
	// Calcular o salário
	calc_salario(funcionarios, horas);
	// Escreve folha
	// Ordenar as funcionarios
	ordena(funcionarios);
	// Gravar a folha
	escreve(funcionarios);
}

void le_funcionario(FILE *arq_func, struct funcionario* funcionarios) 
{
	int i;
	char str[10];
	for (i=0; i<10; i++) 
	{
		fgets(funcionarios[i].nome, 51, arq_func); getc(arq_func);
		fgets(funcionarios[i].matricula, 13, arq_func);	getc(arq_func);
		fgets(funcionarios[i].endereco, 66, arq_func); getc(arq_func);
		fgets(funcionarios[i].cpf, 12, arq_func); getc(arq_func);		
		fgets(funcionarios[i].cod_banco, 4, arq_func); getc(arq_func);
		fgets(funcionarios[i].agencia, 6, arq_func); getc(arq_func);	
		fgets(funcionarios[i].conta, 9, arq_func); getc(arq_func);
		fgets(str, 10, arq_func);
		sscanf(str, "%f", &funcionarios[i].valor_hora);
	}
}

void le_horas(FILE *arq_horas, struct hora* horas) 
{
	int i;
	char str[10];

	for (i=0; i<10; i++) 
	{
		fgets(horas[i].matricula, 13, arq_horas); getc(arq_horas);

		fgets(str, 10, arq_horas);
		sscanf(str, "%d", &horas[i].horas);
	}
}

void calc_salario(struct funcionario* funcionarios, struct hora* horas) 
{
	int i, j, achou;

	for (i=0; i<10; i++) 
	{
		j=0; achou=0;
		while (achou==0) 
		{
			if (strcmp(funcionarios[i].matricula, horas[j].matricula)==0)
			{
				funcionarios[i].salario_mes = funcionarios[i].valor_hora*horas[j].horas;
				achou = 1;
			}
			j++;
		}
	}
}

void ordena (struct funcionario* funcionarios) 
{
	int i, j, cont;

	for (i=0; i<10; i++)
	{
		cont = 0;
		for (j=0; j<10; j++) 
		{
			if (strcmp(funcionarios[i].nome, funcionarios[j].nome)>0)
				cont++;
			funcionarios[i].ordem = cont;	
		}
	}
}

void escreve (struct funcionario* funcionarios) 
{
	int i, j;
	
	for (i=0; i<10; i++)
	{
		for (j=0; j<10; j++) 
		{
			if (funcionarios[j].ordem==i) 
				printf("%s|%s|%s|%s|%s|%.2f\n", funcionarios[j].nome, funcionarios[j].cpf, funcionarios[j].cod_banco, funcionarios[j].agencia, funcionarios[j].conta, funcionarios[j].salario_mes);
		}
	}
}

