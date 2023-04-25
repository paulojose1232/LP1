#include<stdio.h>
#include<stdlib.h>	//Necessaria para usar o system("cls")
#include <locale.h> //necess?rio para usar setlocale
#include<string.h>
#include<conio.h>//Necess?ria pro getch

//Structs
struct local{
	char regiao[15];
	char estado[30];
};
struct descricao{
	char nome[30];
	char tipo[30];
	struct local local;
	char qualidade[30];
	char resumo[100];
};

//Prot?tipos das Fun??es
void menuPrincipal(FILE *arquivo);
void inputData(FILE *arquivo);
void Regiao(struct descricao *ponteiro,FILE *arquivo);
void SelecaoEstados(struct descricao *ponteiro);
void RecepcaoEstados(char estado[][20],struct descricao *ponteiro);
void Tipos(struct descricao *ponteiro,FILE *arquivo);
void Avaliacao(struct descricao *ponteiro,FILE *arquivo);
void PesquisarPorRegiao(FILE *arquivo);
void PesquisarPorNome(FILE *arquivo);
void Cabecalho(char titulo[]);
void AlterarDescricao(int num,FILE *arquivo);

int main(){
	setlocale(LC_ALL, "Portuguese");
	FILE *arquivo;
	arquivo=fopen("eventos.bin","rb");
	menuPrincipal(arquivo);
}

void Cabecalho(char titulo[]){
	fflush(stdin);
	system("cls");
	printf("----------------------------------------------------");
	printf("\n%s",titulo);
	printf("\n----------------------------------------------------\n");
}

void inputData(FILE *arquivo){
	fclose(arquivo);	
	char titulo[]={"NOME DA ATRA??O TUR?STICA"};
	struct descricao evento,*ptr;
	ptr=&evento; //ptr aponta para evento
	arquivo=fopen("eventos.bin","ab");	
	if(arquivo==NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
		getchar();
		exit(0); //Finaliza a execu??o do codigo
	}	
	Cabecalho(titulo);
	printf("\nInforme o nome da atra??o: ");
	gets(evento.nome);
	
	Tipos(&evento,arquivo);
	Regiao(&evento,arquivo);
	SelecaoEstados(&evento);
	Avaliacao(&evento,arquivo);
	
	strcpy(titulo,"RESUMO DA ATRA??O");
	Cabecalho(titulo);
	
	printf("\nDescreva-a de forma sucinta: ");
	gets(evento.resumo);
	
	fwrite(&evento,sizeof(descricao),1,arquivo); //Escreve no arquivo em binario
	fclose(arquivo);//Fecha o arquivo
	
	printf("\n\nInforma??es salvas com sucesso!");
	getchar();
	fflush(stdin);
	
	arquivo=fopen("eventos.bin","rb");
	menuPrincipal(arquivo);
}

/////////////////////////TIPOS/////////////////////////////
void Tipos(struct descricao *ponteiro,FILE *arquivo){
	char tipos[7][20]={"Restaurante","Praia","Show","Teatro","Parque","Museu"};
	char titulo[]={"TIPO DE ATRA??O"};
	int opcao;
	do{	
		Cabecalho(titulo);
		for(int i=0;strcmp(tipos[i],"")!=0;i++){
			printf("\n%d)%s",i+1,tipos[i]);
		}
		printf("\n7)Retornar ao menu principal");
		printf("\n\nDigite a op??o desejada: ");
		scanf("%d",&opcao);
	}while(opcao<1 || opcao>7);
	if(opcao==7){
		fclose(arquivo);
		arquivo=fopen("eventos.bin","rb");	
		menuPrincipal(arquivo);
	}else{
		strcpy(ponteiro->tipo,tipos[opcao-1]);
	}
}

///////////////////////AVALIA??ES///////////////////////////
void Avaliacao(struct descricao *ponteiro,FILE *arquivo){
	char avaliacoes[][20]={"?timo","Bom","Regular","Ruim","P?ssimo","Caro","Barato","Gr?tis"};
	char titulo[]={"AVALIA??O DE ATRA??O"};
	int opcao;
	do{
		Cabecalho(titulo);
		for(int i=0;strcmp(avaliacoes[i],"")!=0;i++){
			printf("\n%d)%s",i+1,avaliacoes[i]);
		}
		printf("\n9)Cancelar e retornar ao menu principal");
		printf("\n\nDigite a op??o desejada: ");
		scanf("%d",&opcao);
	}while(opcao<1 || opcao>9);
	if(opcao==9){
		fclose(arquivo);
		arquivo=fopen("eventos.bin","rb");	
		menuPrincipal(arquivo);
	}else{
		strcpy(ponteiro->qualidade,avaliacoes[opcao-1]);
	}
}

/////////////////////REGI?O///////////////////////////////
void Regiao(struct descricao *ponteiro,FILE *arquivo){
	int opcao;
	char regioes[6][20]={"Norte","Nordeste","Centro-Oeste","Sudeste","Sul"};
	char titulo[]={"SELE??O REGIONAL"};
	do{
		Cabecalho(titulo);
		for(int i=0;strcmp(regioes[i],"")!=0;i++){
			printf("\n%d)%s",i+1,regioes[i]);
		}
		printf("\n6)Cancelar e retornar ao menu principal");
		printf("\n\nDigite a op??o desejada: ");
		scanf("%d",&opcao);
	}while(opcao<1 || opcao>6);
	if(opcao==6){
		fclose(arquivo);
		arquivo=fopen("eventos.bin","rb");	
		menuPrincipal(arquivo);
	}else{
		strcpy(ponteiro->local.regiao,regioes[opcao-1]);
	}
}

/////////////////////////ESTADOS/////////////////////////////////////
void SelecaoEstados(struct descricao *ponteiro){
	int comparacao;
	comparacao=strcmp(ponteiro->local.regiao,"Norte");
	if(comparacao==0){
		char estados[][20]={"Acre","Amap?","Amazonas","Par?","Rond?nia","Roraima","Tocantins"};
		RecepcaoEstados(estados,ponteiro);
	}else{
		comparacao=strcmp(ponteiro->local.regiao,"Nordeste");
		if(comparacao==0){
			char estados[11][20]={"Alagoas","Bahia","Cear?","Maranh?o","Para?ba","Pernambuco","Piau?","Rio Grande do Norte","Sergipe"};
			RecepcaoEstados(estados,ponteiro);
		}else{
			comparacao=strcmp(ponteiro->local.regiao,"Centro-Oeste");
			if(comparacao==0){
				char estados[][20]={"Goi?s","Mato Grosso","Mato Grosso do Sul"};
				RecepcaoEstados(estados,ponteiro);
			}else{
				comparacao=strcmp(ponteiro->local.regiao,"Sudeste");
				if(comparacao==0){
					char estados[][20]={"Espirito Santo","Minas Gerais","Rio de Janeiro","S?o Paulo"}; 
					RecepcaoEstados(estados,ponteiro);
				}else{
					char estados[][20]={"Paran?","Santa Catarina","Rio Grande do Sul"};
					RecepcaoEstados(estados,ponteiro);
				}
			}
		}
	}	
}

//Menu sele??o de Estados
void RecepcaoEstados(char estado[][20],struct descricao *ponteiro){
	int tamanho;
	int opcao=0;
	char titulo[]={"SELE??O ESTADUAL"};
	do{
		tamanho=0;		
		Cabecalho(titulo);
		for(int i=0;strcmp(estado[i],"")!=0;i++){
			printf("\n%d)%s",i+1,estado[i]);
			tamanho++;
		}
		printf("\n\nSelecione a op??o desejada: ");
		scanf("%d",&opcao);
	}while(opcao<1 || opcao>tamanho);
	strcpy(ponteiro->local.estado,estado[opcao-1]);	
}

////////////////////////MENU PRINCIPAL////////////////////////
void menuPrincipal(FILE *arquivo){
	int opcao;
	char titulo[]={"ATRA??ES TUR?STICAS DO BRASIL"};
	do{
		Cabecalho(titulo);
		printf("\n1)Consultar os dados de uma regi?o");	//OK
		printf("\n2)Incluir uma descri??o");	//OK
		printf("\n3)Alterar uma descri??o");	//OK
		printf("\n4)Excluir uma descri??o");	//OK
		printf("\n5)Mostrar uma descri??o");	//OK
		printf("\n6)Sair");
		printf("\n\nDigite a op??o desejada: ");
		scanf("%d",&opcao);
	}while(opcao<1 || opcao>6);	
	switch(opcao){
		case 1:
			PesquisarPorRegiao(arquivo); //aqui o ponteiro da ruim
			break;
		case 2:
			inputData(arquivo); //Adiciona uma nova atra??o
			break;
		case 3:
			AlterarDescricao(2,arquivo); //2 para editar
			break;
		case 4:
			AlterarDescricao(1,arquivo); //1 para excluir
			break;
		case 5:
			PesquisarPorNome(arquivo); //Mostra uma atra??o -> botar no mesmo bola de exclusao e edi??o
			break;
		case 6:
			exit(0);
			break;
	}
}

//FUN??ES DE PESQUISA
void PesquisarPorRegiao(FILE *arquivo){
	struct descricao evento,filtro;
	char regiao[30];
	int contador=0;
	
	if(arquivo==NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
		getchar();
		menuPrincipal(arquivo);
	}else{
		Regiao(&filtro,arquivo);
		strcpy(regiao,filtro.local.regiao);
		system("cls");
		printf("----------------------------------------------------");
		printf("\nRegi?o %s:",regiao);
		printf("\n----------------------------------------------------\n");				
		getchar();
		while( fread(&evento,sizeof(descricao),1,arquivo)==1){
			if(strcmp(evento.local.regiao,regiao)==0){
				contador++;
				printf("Nome: %s\n",evento.nome);
				printf("Tipo: %s\n",evento.tipo);
				printf("local: %s\n",evento.local.estado);
				printf("qualidade: %s\n",evento.qualidade);
				printf("resumo: %s\n\n",evento.resumo);
			}
		}
		if(contador==0){
			printf("\nNenhuma atra??o encontrada\n");	
		}
		getchar();
		fflush(stdin);
		fclose(arquivo);
		arquivo=fopen("eventos.bin","rb");
		menuPrincipal(arquivo);
	}
}
void PesquisarPorNome(FILE *arquivo){
	char titulo[]={"PESQUISA POR NOME"};	
	struct descricao evento,*ptr;
	char nome[30];
	
	if(arquivo==NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
		getchar();
		menuPrincipal(arquivo);
	}else{
		Cabecalho(titulo);
		fflush(stdin);
		printf("Digite o nome da atra??o desejada: ");
		gets(nome);
		
		printf("\nResultado da Pesquisa:\n\n");
		int contador=0;
		while( fread(&evento,sizeof(descricao),1,arquivo)==1){
			if(strcmp(evento.nome,nome)==0){
				contador++;
				printf("Nome: %s\n",evento.nome);
				printf("Tipo: %s\n",evento.tipo);
				printf("local: %s\n",evento.local.estado);
				printf("Avalia??o: %s\n",evento.qualidade);
				printf("resumo: %s\n\n",evento.resumo);
			}
		}
		if(contador==0){
			printf("ATRA??O N?O ENCONTRADA!");
			getchar();
		}else{
			getchar();
		}
	}
	fflush(stdin);
	fclose(arquivo);
	arquivo=fopen("eventos.bin","rb");
	menuPrincipal(arquivo);
}

void AlterarDescricao(int num,FILE *arquivo){
	FILE *arquivoSubstituto;
	char nomeArquivo[]={"eventos.bin"};
	char nomedois[]={"segundo.bin"};
	struct descricao evento,*ptr;

	if(arquivo==NULL){
		printf("\nN?o foi poss?vel abrir o arquivo");
		getchar();
		fflush(stdin);
		menuPrincipal(arquivo);
	}else{
		arquivoSubstituto=fopen("substituto.bin","wb");
		if(arquivoSubstituto==NULL){
			printf("\nN?o ser? poss?vel fazer altera??es. Tente novamente mais tarde.\n");
			getchar();
			fflush(stdin);
			menuPrincipal(arquivo);
		}else{
			system("cls");
			printf("----------------------------------------------------");
			if(num==1){
				printf("\nEXCLUS?O DE ATRA??O");
			}else{
				printf("\nEDI??O DE ATRA??O");
			}
			printf("\n----------------------------------------------------\n");
			char nome[30];
			fflush(stdin);
			if(num==1){
				printf("Digite o nome da atra??o que voc? deseja excluir: ");	
			}else{
				printf("Digite o nome da atra??o que voc? deseja editar: ");
			}
			gets(nome);
			printf("\nResultado da Pesquisa:\n\n");
			int contador=0;
			
			while(fread(&evento,sizeof(descricao),1,arquivo)==1){
				if(strcmp(evento.nome,nome)==0){
					contador++;
					printf("Nome: %s\n",evento.nome);
					printf("Tipo: %s\n",evento.tipo);
					printf("local: %s\n",evento.local.estado);
					printf("Avalia??o: %s\n",evento.qualidade);
					printf("resumo: %s\n\n",evento.resumo);	
					getchar();
					fflush(stdin);
					if(num==2){
						struct descricao auxiliar;
						char titulo[]={"NOME DA ATRA??O TUR?STICA"};
						
						Cabecalho(titulo);
						printf("\nInforme o nome da atra??o: ");
						gets(auxiliar.nome);
						
						Tipos(&auxiliar,arquivo);
						Regiao(&auxiliar,arquivo);
						SelecaoEstados(&auxiliar);
						Avaliacao(&auxiliar,arquivo);
						
						strcpy(titulo,"RESUMO DA ATRA??O");
						Cabecalho(titulo);
						
						fflush(stdin);
						printf("\nDescreva-a de forma sucinta: ");
						gets(auxiliar.resumo);						
						fwrite(&auxiliar,sizeof(descricao),1,arquivoSubstituto);
					}	
				}else{
					fwrite(&evento,sizeof(descricao),1,arquivoSubstituto);
				}
			}
			fclose(arquivoSubstituto);
			fclose(arquivo);
			rename("eventos.bin","segundo.bin");
			remove(nomedois);
			rename("substituto.bin","eventos.bin");
			arquivo=fopen("eventos.bin","rb");
	
			if(contador==0){
				printf("\nNenhuma atra??o encontrada");
			}
			getchar();
			fflush(stdin);
			menuPrincipal(arquivo);
		}
	}
}
