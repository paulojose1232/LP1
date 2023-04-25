#include<stdio.h>
#include<stdlib.h>	
#include <locale.h> 
#include<string.h>
#include<conio.h>

//Struct para os produtos
struct pratosEbebidas{
	char nome[30];
	char codigo[10];
	float preco;
};

//Struct para os garcons
struct Garcons{
	char nome[30];
	char codigo[10];
};

//Structs para mesas e produtos
typedef struct Pedidos NoPedido;
struct Pedidos{
	char codigoPedido[10];
	int quantidade;
	NoPedido *prox;
};
typedef struct Mesas NoMesa;
struct Mesas{
	int numMesa;
	char codigo_garcom[10];
	float totalPedido;
	NoPedido *pedidos;
	NoMesa *ant, *prox;
};

//Prot?tipos das fun??es para os produtos
void areaProdutos();
void menuProdutos(FILE *produtos);
void cadastrarProduto(FILE *produtos);
void consultarRegistros(FILE *produtos);
void alterarProduto(int num,FILE *produto);
void mostrarProdutos(FILE *produtos);

//Prototipos das funcoes para os garcons
void areaGarcons();
void menuGarcons(FILE *garcons);
void cadastrarGarcom(FILE *garcons);
void consultarGarcons(FILE *garcons);
void alterarGarcom(int num,FILE *garcons);
void mostrarGarcons(FILE *garcons);

//Prot?tipos das das fun??es usadas em mesas e produtos
int verificarMesa(NoMesa *Lista,int num);
NoMesa* cria_no_mesa();
NoPedido* cria_no_pedido();
NoPedido* buscaPedidoPedido(char nomePedido[30],NoPedido *ponteiro,NoMesa *Lista);
NoMesa* buscaGarcom(char nomeGarcom[30],NoMesa *Lista);
NoMesa* buscaPedido(char nomePedido[30],NoMesa *Lista);
NoMesa* AdicionaPedidoSemMesa(NoMesa *Lista,char codigo[10],int quantidade);
NoMesa *finalCadastro(NoMesa *novo);
NoMesa *NaoExisteMesa(NoMesa *Lista,int numMesa);
NoMesa* ExisteMesa(NoMesa *Lista,int numMesa);
NoMesa* AdicionarPedido(NoMesa *Lista);
NoMesa* alterarPedido(NoMesa* Lista,int num);
void imprimir(NoMesa* Principal);
void Cardapio();
void Menu(NoMesa *Lista);
void MenuPedidos(Mesas *Lista);
void imprimir_conta(NoMesa* mesa);
void imprimirMesa(NoMesa* Principal);
void fecharConta(NoMesa *Lista);
void manualPrograma();



int main(){
	setlocale(LC_ALL, "Portuguese");
	//areaProdutos();
	//areaGarcons();
	NoMesa *Lista;
	Lista=NULL;
	Menu(Lista);
}

//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////PARTE 1//////////////////////////////////////////
void areaProdutos(){
	FILE *produtos;
	produtos=fopen("produtos.bin","rb");
	if(produtos==NULL){	//Se o arquivo n?o existir, cria
		produtos=fopen("produtos.bin","wb");
		fclose(produtos);
		produtos=fopen("produtos.bin","rb");
	}
	menuProdutos(produtos);	
}
void areaGarcons(){
	FILE *garcons;
	garcons=fopen("garcons.bin","rb");
	if(garcons==NULL){	//Se o arquivo n?o existir, cria
		garcons=fopen("garcons.bin","wb");
		fclose(garcons);
		garcons=fopen("garcons.bin","rb");
	}
	menuGarcons(garcons);
}

void menuGarcons(FILE *garcons){
	int opcao;
	do{
		system("cls");
		printf("---------------------------------");
		printf("\nGAR?ONS");
		printf("\n---------------------------------");	
		printf("\n1)Cadastrar novo gar?om");
		printf("\n2)Deletar dados de um gar?om");	//informa o codigo do produto e deleta
		printf("\n3)Alterar dados de um gar?om");	//informa o codigo do produto e altera
		printf("\n4)Consultar dados de um gar?om"); //informa o nome do produto e aparece as informa??es sobre ele
		printf("\n5)Mostrar todos os gar?ons");
		printf("\n6)Voltar ao menu principal");
		printf("\n7)Fechar o programa");
		printf("\n\nInforme a op??o desejada: ");
		scanf("%d",&opcao);
		fflush(stdin);
	}while(opcao<1 || opcao>7);
	
	switch(opcao){
		case 1:
			cadastrarGarcom(garcons);
			break;
		case 2: 
			alterarGarcom(1,garcons);
			break;
		case 3:
			alterarGarcom(2,garcons);
			break;
		case 4:
			consultarGarcons(garcons);
			break;
		case 5:
			mostrarGarcons(garcons);
			break;
		case 6:
			//menuPrincipal();
			break;	
		case 7:
			fclose(garcons);
			exit(0);
	}
}
void menuProdutos(FILE *produtos){
	int opcao;
	do{
		system("cls");
		printf("---------------------------------");
		printf("\nPRODUTOS");
		printf("\n---------------------------------");	
		printf("\n1)Cadastrar novo produto");
		printf("\n2)Deletar um produto");	//informa o codigo do produto e deleta
		printf("\n3)Alterar produto");	//informa o codigo do produto e altera
		printf("\n4)Consultar produto"); //informa o nome do produto e aparece as informa??es sobre ele
		printf("\n5)Mostrar todos os produtos");
		printf("\n6)Voltar ao menu principal");
		printf("\n7)Fechar o programa");
		printf("\n\nInforme a op??o desejada: ");
		scanf("%d",&opcao);
		fflush(stdin);
	}while(opcao<1 || opcao>7);
	
	switch(opcao){
		case 1:
			cadastrarProduto(produtos);
			break;
		case 2: 
			alterarProduto(1,produtos);
			break;
		case 3:
			alterarProduto(2,produtos);
			break;
		case 4:
			consultarRegistros(produtos);
			break;
		case 5:
			mostrarProdutos(produtos);
			break;
		case 6:
			//menuPrincipal();
			break;
		case 7:
			fclose(produtos);
			exit(0);
	}
}

void cadastrarGarcom(FILE *garcons){
	fclose(garcons);	
	struct Garcons novoGarcom;
	garcons=fopen("garcons.bin","ab");
	fflush(stdin);
	if(garcons==NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
		getchar();
		exit(0); //Finaliza a execu??o do codigo
	}else{
		system("cls");
		printf("---------------------------------");
		printf("\nCADASTRO DE GAR?OM");
		printf("\n---------------------------------");
		
		printf("\nInforme o nome do gar?om: ");
		gets(novoGarcom.nome);
		fflush(stdin);
		
		printf("\nInforme o c?digo do gar?om: ");
		gets(novoGarcom.codigo);
		fflush(stdin);
		
		getchar();
		fflush(stdin);
		
		fwrite(&novoGarcom,sizeof(Garcons),1,garcons); //Escreve no arquivo em binario
		fclose(garcons);//Fecha o arquivo
	
		printf("\n\nInforma??es salvas com sucesso!");
		getchar();
		fflush(stdin);
	
		garcons=fopen("garcons.bin","rb");
		menuGarcons(garcons);
	}
}
void cadastrarProduto(FILE *produtos){
	fclose(produtos);	
	struct pratosEbebidas novoProduto;
	produtos=fopen("produtos.bin","ab");
	fflush(stdin);
	if(produtos==NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
		getchar();
		exit(0); //Finaliza a execu??o do codigo
	}else{
		system("cls");
		printf("---------------------------------");
		printf("\nCADASTRO DE PRODUTO");
		printf("\n---------------------------------");
		
		printf("\nInforme o nome do produto: ");
		gets(novoProduto.nome);
		fflush(stdin);
		
		printf("\nInforme o c?digo do produto: ");
		gets(novoProduto.codigo);
		fflush(stdin);
		
		float b;
		printf("\nInforme o pre?o do produto: ");
		scanf("%f",&novoProduto.preco);
				
		fflush(stdin);
		getchar();
		fflush(stdin);
		
		fwrite(&novoProduto,sizeof(pratosEbebidas),1,produtos); //Escreve no arquivo em binario
		fclose(produtos);//Fecha o arquivo
	
		printf("\n\nInforma??es salvas com sucesso!");
		getchar();
		fflush(stdin);
	
		produtos=fopen("produtos.bin","rb");
		menuProdutos(produtos);
	}
}

void consultarGarcons(FILE *garcons){
		char nome[30];
		int contador=0;
		struct Garcons garcom; 
		system("cls");
		printf("---------------------------------");
		printf("\nBUSCA DE GAR?OM");
		printf("\n---------------------------------");
		fflush(stdin);
		
		printf("\nInforme o nome do gar?om: ");
		gets(nome);
		fflush(stdin);
		
		while( fread(&garcom,sizeof(Garcons),1,garcons)==1){
			if(strcmp(garcom.nome,nome)==0){
				contador++;
				printf("\nNome do gar?om: %s",garcom.nome);
				printf("\nC?digo do gar?om: %s",garcom.codigo);
			}
		}
		if(contador==0){
			printf("\nNenhum gar?om encontrado!");
		}
		getchar();
		fflush(stdin);
		fclose(garcons);
		garcons=fopen("garcons.bin","rb");
		menuGarcons(garcons);
}

void mostrarGarcons(FILE *garcons){
	system("cls");
	printf("---------------------------------");
	printf("\nGAR?ONS CADASTRADOS");
	printf("\n---------------------------------");
	
	int contador=0;
	struct Garcons garcom; 
	
	while( fread(&garcom,sizeof(Garcons),1,garcons)==1){
		contador++;
		printf("\n\nNome do gar?om: %s",garcom.nome);
		printf("\nC?digo do gar?om: %s",garcom.codigo);
	}
	if(contador==0){
		printf("\nNenhum gar?om cadastrado");
	}
	fclose(garcons);
	garcons=fopen("garcons.bin","rb");
	getchar();
	fflush(stdin);
	menuGarcons(garcons);
}
void mostrarProdutos(FILE *produtos){
	system("cls");
	printf("---------------------------------");
	printf("\nPRODUTOS CADASTRADOS");
	printf("\n---------------------------------");
	
	int contador=0;
	struct pratosEbebidas prato; 
	
	while( fread(&prato,sizeof(pratosEbebidas),1,produtos)==1){
		contador++;
		printf("\n\nNome do prato: %s",prato.nome);
		printf("\nC?digo do prato: %s",prato.codigo);
		printf("\nPre?o do prato: R$ %.2f",prato.preco);
	}
	if(contador==0){
		printf("\nNenhum produto cadastrado");
	}
	fclose(produtos);
	produtos=fopen("produtos.bin","rb");
	getchar();
	fflush(stdin);
	menuProdutos(produtos);
}

void consultarRegistros(FILE *produtos){
		char nome[30];
		int contador=0;
		struct pratosEbebidas produto; 
		system("cls");
		printf("---------------------------------");
		printf("\nBUSCA DE PRODUTO");
		printf("\n---------------------------------");
		fflush(stdin);
		
		printf("\nInforme o nome do produto: ");
		gets(nome);
		fflush(stdin);
		
		while( fread(&produto,sizeof(pratosEbebidas),1,produtos)==1){
			if(strcmp(produto.nome,nome)==0){
				contador++;
				printf("\nNome do produto: %s",produto.nome);
				printf("\nC?digo do produto: %s",produto.codigo);
				printf("\nPre?o do produto %.2f R$",produto.preco);
			}
		}
		if(contador==0){
			printf("\nNenhum produto encontrado!");
		}
		getchar();
		fflush(stdin);
		fclose(produtos);
		produtos=fopen("produtos.bin","rb");
		menuProdutos(produtos);
}

void alterarGarcom(int num,FILE *garcons){
	fflush(stdin);
	FILE *garcomsubstituto;
	char nome[30];
	char nomeArquivo[]={"garcons.bin"};
	char nomeSecundario[]={"garcomsecundario.bin"};
	int contador=0;
	struct Garcons garcom; 
	
	
	garcomsubstituto=fopen("garcomsubstituto.bin","wb");
	if(garcomsubstituto==NULL){
			printf("\nN?o ser? poss?vel fazer altera??es. Tente novamente mais tarde.\n");
			getchar();
			fflush(stdin);
			fclose(garcons);
			exit(0);
	}else{
				
		system("cls");
		printf("---------------------------------");
		if(num==1){
			printf("\nDELETAR GAR?OM");
		}else{
			printf("\nEDITAR DADOS DE UM GAR?OM");
		}
		printf("\n---------------------------------");
		fflush(stdin);
		
		printf("\nInforme o nome do gar?om: ");
		gets(nome);
		fflush(stdin);
		
		while( fread(&garcom,sizeof(Garcons),1,garcons)==1){
			if(strcmp(garcom.nome,nome)==0){
				contador++;
				printf("\nNome do gar?om: %s",garcom.nome);
				printf("\nC?digo do gar?om: %s",garcom.codigo);
				getchar();
				fflush(stdin);
				if(num==2){
					
					struct Garcons auxiliar; 
					
					system("cls");
					printf("\nNovos dados do gar?om: ");
					
					printf("\n\nNome do gar?om: ");
					gets(auxiliar.nome);
					fflush(stdin);
						
					printf("\nC?digo do gar?om: ");
					gets(auxiliar.codigo);
					fflush(stdin);											
											
					fwrite(&auxiliar,sizeof(Garcons),1,garcomsubstituto);
					
				}
			}else{
				fwrite(&garcom,sizeof(Garcons),1,garcomsubstituto);
			}
		}
		fclose(garcomsubstituto);
		fclose(garcons);
		
		rename("garcons.bin","garcomsecundario.bin");		
		remove(nomeSecundario);
		rename("garcomsubstituto.bin","garcons.bin");
		
		garcons=fopen("garcons.bin","rb");
		
		if(contador==0){
			printf("\nNenhum gar?om encontrado!");
		}
		getchar();
		fflush(stdin);
		menuGarcons(garcons);
		}
}
void alterarProduto(int num,FILE *produtos){
	fflush(stdin);
	FILE *substituto;
	char nome[30];
	char nomeArquivo[]={"produtos.bin"};
	char nomeSecundario[]={"secundario.bin"};
	int contador=0;
	struct pratosEbebidas produto; 
	
	
	substituto=fopen("substituto.bin","wb");
	if(substituto==NULL){
			printf("\nN?o ser? poss?vel fazer altera??es. Tente novamente mais tarde.\n");
			getchar();
			fflush(stdin);
			fclose(produtos);
			exit(0);
	}else{
				
		system("cls");
		printf("---------------------------------");
		if(num==1){
			printf("\nDELETAR PRODUTO");
		}else{
			printf("\nEDITAR PRODUTO");
		}
		printf("\n---------------------------------");
		fflush(stdin);
		
		printf("\nInforme o nome do produto: ");
		gets(nome);
		fflush(stdin);
		
		while( fread(&produto,sizeof(pratosEbebidas),1,produtos)==1){
			if(strcmp(produto.nome,nome)==0){
				contador++;
				printf("\nNome do produto: %s",produto.nome);
				printf("\nC?digo do produto: %s",produto.codigo);
				printf("\nPre?o do produto %.2f R$",produto.preco);
				getchar();
				fflush(stdin);
				if(num==2){
					
					struct pratosEbebidas auxiliar; 
					
					system("cls");
					printf("\nNovos dados do produto: ");
					
					printf("\n\nNome do produto: ");
					gets(auxiliar.nome);
					fflush(stdin);
						
					printf("\nC?digo do produto: ");
					gets(auxiliar.codigo);
					fflush(stdin);
						
					printf("\nPre?o do produto: ");
					scanf("%f",&auxiliar.preco);
					fflush(stdin);
												
											
					fwrite(&auxiliar,sizeof(pratosEbebidas),1,substituto);
					
				}
			}else{
				fwrite(&produto,sizeof(pratosEbebidas),1,substituto);
			}
		}
		fclose(substituto);
		fclose(produtos);
		
		rename("produtos.bin","secundario.bin");
		remove(nomeSecundario);
		rename("substituto.bin","produtos.bin");		
		produtos=fopen("produtos.bin","rb");
		
		
		if(contador==0){
			printf("\nNenhum produto encontrado!");
		}
		getchar();
		fflush(stdin);
		menuProdutos(produtos);
		}
}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////PARTE 2/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////Cria??o dos N?s///////////////////////
NoMesa* cria_no_mesa(){
	NoMesa *novo_no;
	novo_no=(NoMesa*)malloc(sizeof(NoMesa));
	return novo_no;
}
NoPedido* cria_no_pedido(){
	NoPedido *novo_no;
	novo_no=(NoPedido*)malloc(sizeof(NoPedido));
	return novo_no;
}

//////////////////////////////////////////////////////////////////////
////////////////////BUSCA NOS ARQUIVOS///////////////////////////////
NoPedido* buscaPedidoPedido(char nomePedido[30],NoPedido *ponteiro,NoMesa *Lista){
	FILE *arquivo;
	arquivo=fopen("produtos.bin","rb");
	char codigo[10];
	int contador=0;
	struct pratosEbebidas prato; 
	float total=Lista->totalPedido;
	
	while( fread(&prato,sizeof(pratosEbebidas),1,arquivo)==1){
		if(strcmp(prato.nome,nomePedido)==0){
			contador++;
			int quantidade;
			printf("\nInforme a quantidade do pedido: ");
			scanf("%d",&quantidade);
			fflush(stdin);
			total=total+(prato.preco*quantidade);
			Lista->totalPedido=total;
			ponteiro->quantidade=quantidade;
			strcpy(ponteiro->codigoPedido,prato.codigo);
		}
	}
	fclose(arquivo);

	if(contador==0){	
		ponteiro=NULL;
		return ponteiro;
	}else{
		return ponteiro;
	}
	
}

NoMesa* buscaGarcom(char nomeGarcom[30],NoMesa *Lista){
	FILE *arquivo;
	arquivo=fopen("garcons.bin","rb");
	char codigo[10];
	int contador;
	struct Garcons garcom;
	while( fread(&garcom,sizeof(Garcons),1,arquivo)==1){
		if(strcmp(garcom.nome,nomeGarcom)==0){
			contador++;	
			strcpy(Lista->codigo_garcom,garcom.codigo);
			break;
		}
	}
	fclose(arquivo);
	if(contador==0){
		strcpy(Lista->codigo_garcom,"\0");
	}
	return Lista;
}

NoMesa* buscaPedido(char nomePedido[30],NoMesa *Lista){
	FILE *arquivo;
	arquivo=fopen("produtos.bin","rb");
	char codigo[10];
	int contador=0;
	struct pratosEbebidas prato; 
	float total=0;
	
	while( fread(&prato,sizeof(pratosEbebidas),1,arquivo)==1){
		if(strcmp(prato.nome,nomePedido)==0){
			contador++;
			int quantidade;
			printf("\nInforme a quantidade do pedido: ");
			scanf("%d",&quantidade);
			fflush(stdin);
			total=total+(prato.preco*quantidade);
			Lista->totalPedido=total;
			Lista=AdicionaPedidoSemMesa(Lista,prato.codigo,quantidade);
		}
	}
	fclose(arquivo);
	if(contador==0){
		Lista->pedidos=NULL;
	}
	return Lista;		
}


/////////////////////////////////////////////////////////////////////
////////////////////////CADASTRO DE PEDIDO//////////////////////////
int verificarMesa(NoMesa *Lista,int num){
	if(Lista==NULL){
		return false;
	}else{
		NoMesa *aux;
		aux=Lista;
		int achou=false;
		while(aux!=NULL){
			if(aux->numMesa==num){
				achou=true;
			}
			aux=aux->prox;
		}
		return achou;
	}
}

NoMesa* AdicionaPedidoSemMesa(NoMesa *Lista,char codigo[10],int quantidade){
	NoPedido *novo=cria_no_pedido();
	strcpy(novo->codigoPedido,codigo);
	novo->quantidade=quantidade;
	novo->prox=NULL;
	Lista->pedidos=novo;
	return Lista;
}
NoMesa *finalCadastro(NoMesa *novo){
	char nomeGarcom[30];
		do{
			printf("\nInforme o nome do Garcom:  ");
			gets(nomeGarcom);
			fflush(stdin);
			novo=buscaGarcom(nomeGarcom,novo);
			
		}while(strcmp(novo->codigo_garcom,"\0")==0);
		
		char nomePedido[30];
		do{
			printf("\nInforme o nome do pedido de acordo com o cardapio: ");
			gets(nomePedido);
			fflush(stdin);
			
			novo=buscaPedido(nomePedido,novo);	
		}while(novo->pedidos==NULL);
		return novo;
}

NoMesa *NaoExisteMesa(NoMesa *Lista,int numMesa){
	
	NoMesa *novo=cria_no_mesa();
	
	if(Lista==NULL){
		
		Lista=novo;
		novo->prox=NULL;
		novo->ant=NULL;
		novo->numMesa=numMesa;
		novo=finalCadastro(novo);
		
		return Lista;
	}else{
		NoMesa *amador,*corredor;
		corredor=Lista;
		while(corredor->prox!=NULL){
			amador=corredor;
			corredor=corredor->prox;
		}
		corredor->prox=novo;
		novo->ant=corredor;
		novo->prox=NULL;
		novo->numMesa=numMesa;
		novo=finalCadastro(novo);
		return Lista;
	}
}

NoMesa* ExisteMesa(NoMesa *Lista,int numMesa){
	NoMesa *aux;
	aux=Lista;
	while(aux->numMesa!=numMesa){
		aux=aux->prox;
	}
	NoPedido *corredor;
	corredor=aux->pedidos;
	while(corredor->prox!=NULL){
		corredor=corredor->prox;
	}
	NoPedido *amador;
	char nomePedido[30];
	do{
		amador=cria_no_pedido();
		printf("\nInforme o nome do pedido de acordo com o cardapio: ");
		gets(nomePedido);
		fflush(stdin);
		amador=buscaPedidoPedido(nomePedido,amador,aux);
	}while(amador==NULL);
	
	corredor->prox=amador;
	amador->prox=NULL;
	
	return Lista;
}

NoMesa* AdicionarPedido(NoMesa *Lista){
	system("cls");
	printf("-------------------------------------");
	printf("\nCADASTRO DE PEDIDO");
	printf("\n-------------------------------------");
	int mesa,existeMesa;
	printf("\nInforme a mesa: ");
	scanf("%d",&mesa);
	fflush(stdin);
	existeMesa=verificarMesa(Lista,mesa);
	
	if(existeMesa==false){
		Lista=NaoExisteMesa(Lista,mesa);
	}else{
		Lista=ExisteMesa(Lista,mesa);
	}
	return Lista;
}

//////////////////////////////////////////////////////////////////
////////////////////////IMPRESSAO////////////////////////////////
void imprimir(NoMesa* Principal){
	system("cls");
	printf("----------------------------------------");
	printf("\nPEDIDOS");
	printf("\n----------------------------------------");
	NoMesa* corredor;
	NoPedido *aux,*inicio;
	corredor=Principal;
	int contador=0;
	while(corredor!=NULL){
		contador++;
		printf("\n\nMESA %d",corredor->numMesa);
		printf("\nCodigo do Garcom: %s",corredor->codigo_garcom);
		printf("\nPedidos: ");
		aux=corredor->pedidos;
		while(aux!=NULL){
			printf("\nCodigo do pedido: %s",aux->codigoPedido);
			printf("   -   Quantidade do pedido: %d",aux->quantidade);
			aux=aux->prox;
		}
		printf("\nTotal: %.2f",corredor->totalPedido);
		corredor=corredor->prox;
	}
	if(contador==0){
		printf("\nNenhum pedido encontrado!");
	}
	getchar();
	fflush(stdin);
}

void imprimirMesa(NoMesa* Principal){
	system("cls");
	printf("----------------------------------------");
	printf("\nConsulta de mesa");
	printf("\n----------------------------------------");
	int mesa;
	printf("\nInforme o numero da mesa: ");
	scanf("%d",&mesa);
	fflush(stdin);
	NoMesa *corredor;
	corredor=Principal;
	if(corredor==NULL){
		
		printf("\nN?o existe mesa cadastrada");
		getchar();
		fflush(stdin);
		
	}else{
		
		while(corredor!=NULL && corredor->numMesa!=mesa){
			corredor=corredor->prox;
		}
		
		if(corredor==NULL){
			
			printf("\nMesa n?o encontrada");
			getchar();
			fflush(stdin);
			
		}else{
			
			NoPedido *aux;
			aux=corredor->pedidos;
			printf("\nMESA %d",mesa);
			printf("\nC?digo do gar?om: %s",corredor->codigo_garcom);
			printf("\nPedidos: ");
			while(aux!=NULL){
				printf("\nCodigo do pedido: %s",aux->codigoPedido);
				printf("   -   Quantidade do pedido: %d",aux->quantidade);
				aux=aux->prox;
			}
			printf("\nTotal: %.2f",corredor->totalPedido);
			getchar();
			fflush(stdin);
			
		}	
	}
}

void Cardapio(){
	FILE *arquivo;
	arquivo=fopen("produtos.bin","rb");
	struct pratosEbebidas prato;
	system("cls");
	printf("----------------------------------");
	printf("\nCARDAPIO");
	printf("\n----------------------------------");
	while( fread(&prato,sizeof(pratosEbebidas),1,arquivo)==1){
		printf("\n\nProduto: %s",prato.nome);
		printf("\nPre?o: %.2f",prato.preco);
	}
	fclose(arquivo);
	getchar();
	fflush(stdin);
}

void imprimir_conta(NoMesa* mesa){
	FILE *arquivo;
	arquivo=fopen("produtos.bin","rb");
	struct pratosEbebidas prato; 
	
	printf("\nMESA %d",mesa->numMesa);
	printf("\nCodigo do Gar?om: %s",mesa->codigo_garcom);
	
	NoPedido *aux;
	aux=mesa->pedidos;
	int contador=0;
	while(aux!=NULL){

		arquivo=fopen("produtos.bin","rb");
		while( fread(&prato,sizeof(pratosEbebidas),1,arquivo)==1 ){//&& contador==0){
			contador=0;

			if(strcmp(prato.codigo,aux->codigoPedido)==0 && contador==0){
				printf("\n%s - R$%.2f - Quantidade: %d",prato.nome,prato.preco,aux->quantidade);
				contador=1;
			}
		}
		fclose(arquivo);
		aux=aux->prox;
	}
	printf("\nTotal: %.2f",mesa->totalPedido);
	getchar();
	fflush(stdin);	
}

void fecharConta(NoMesa *Lista){
	system("cls");
	printf("----------------------------------------");
	printf("\nFECHAMENTO DE CONTA");
	printf("\n----------------------------------------");
	int mesa;
	printf("\nInforme o numero da mesa: ");
	scanf("%d",&mesa);
	fflush(stdin);
	int existe=verificarMesa(Lista,mesa);
	
	if(existe==0){
		
		printf("\nN?o existe conta aberta nesta mesa!");
		getchar();
		fflush(stdin);
		MenuPedidos(Lista);
		
	}else{
		
		NoMesa *corredor,*amador;
		corredor=amador=Lista;
		while(corredor->prox!=NULL){
			amador=corredor;
			corredor=corredor->prox;
		}
		if(Lista->numMesa==mesa){	//verifica se ? a primeira mesa
		
			imprimir_conta(Lista);			
			if(Lista->prox==NULL){	//verifica se ? a primeira e unica mesa
				
				Lista=NULL;
				MenuPedidos(Lista);
				
			}else{	//? a primeira mas n?o a unica
				
				amador=corredor=Lista;
				amador=amador->prox;
				amador->ant=NULL;
				corredor->prox=NULL;
				free(corredor);
				Lista=amador;
				MenuPedidos(Lista);	
			}
			
		}else if(corredor->numMesa==mesa){	//Verifica se ? a ultima mesa
			
			imprimir_conta(corredor);		
			amador->prox=NULL;
			corredor->ant=NULL;
			free(corredor);
			MenuPedidos(Lista);	
			
		}else{ //N?o ? a primeira nem a ultima mesa
			
			amador=corredor=Lista;
			while(corredor!=NULL){
				if(corredor->numMesa==mesa){
					imprimir_conta(corredor);									
					amador->prox=corredor->prox;
					corredor->prox->ant=amador;
					corredor->ant=NULL;
					corredor->prox=NULL;
					free(corredor);
				}
				amador=corredor;
				corredor=corredor->prox;
			}
			MenuPedidos(Lista);	
			
		}	
	}
}


///////////////////////////////////////////////////////////////
///////////////////ALTERA??O DE PEDIDO////////////////////////
NoMesa* alterarPedido(NoMesa *Lista,int num){	//Se num for 1->altera o pedido. Se for diferente de 1, exclui
	system("cls");
	printf("-------------------------------------------");
	if(num==1){
		printf("\nEDI??O DE PEDIDO");
	}else{
		printf("\nDELE??O DE PEDIDO");
	}
	printf("\n-------------------------------------------");
	
	int mesa;
	printf("\nInforme o numero da mesa: ");
	scanf("%d",&mesa);
	fflush(stdin);
	
	int achou=verificarMesa(Lista,mesa);
	
	if(achou==0){
		
		printf("\nMesa n?o encontrada! ");
		getchar();
		fflush(stdin);
		return Lista;
		
	}else{
		
		NoMesa *aux;
		aux=Lista;
		while(aux->numMesa!=mesa){
			aux=aux->prox;
		}

		char codigo[10];
		printf("Informe o codigo do pedido: ");
		gets(codigo);
		fflush(stdin);
		int contador=0;
			
		
		if(num==1){

			NoPedido *corredor;
			corredor=aux->pedidos;

			while(corredor->prox!=NULL && (strcmp(corredor->codigoPedido,codigo))!=0){
				corredor=corredor->prox;
			}
			
			if(strcmp(corredor->codigoPedido,codigo)!=0){
				
				printf("\nPedido n?o encontrado!");
				getchar();
				fflush(stdin);
				return Lista;
			}else{
				char nomePedido[30];
				FILE *arquivo;
				arquivo=fopen("produtos.bin","rb");				
				struct pratosEbebidas prato; 
				float total=0;	
				while( fread(&prato,sizeof(pratosEbebidas),1,arquivo)==1){
					if(strcmp(prato.codigo,corredor->codigoPedido)==0){
						total=prato.preco*corredor->quantidade;
						break;
					}
				}
				fclose(arquivo);
				aux->totalPedido=aux->totalPedido-total;
				
				NoPedido* marcaposicao;
				marcaposicao=corredor;
				
				do{
					corredor=marcaposicao;
					printf("\nInforme o nome do pedido de acordo com o cardapio: ");
					gets(nomePedido);
					fflush(stdin);
					corredor=buscaPedidoPedido(nomePedido,corredor,aux);
				}while(corredor==NULL);
				
				return Lista;
			}
		
		}else{

			NoPedido *corredor;
			corredor=aux->pedidos;

			while(corredor->prox!=NULL && (strcmp(corredor->codigoPedido,codigo))!=0){
				corredor=corredor->prox;
			}
			if(strcmp(corredor->codigoPedido,codigo)!=0){	//Verifica se existe o pedido na mesa
			
				printf("\nPedido n?o encontrado!");
				getchar();
				fflush(stdin);
				return Lista;

			}else{
				
				//Remove do total o pedido a ser excluido				
				char nomePedido[30];
				FILE *arquivo;
				arquivo=fopen("produtos.bin","rb");				
				struct pratosEbebidas prato; 
				float total=0;	
				while( fread(&prato,sizeof(pratosEbebidas),1,arquivo)==1){
					if(strcmp(prato.codigo,corredor->codigoPedido)==0){
						total=prato.preco*corredor->quantidade;
						break;
					}
				}
				fclose(arquivo);
				aux->totalPedido=aux->totalPedido-total;
				
								
				NoPedido *ultimo,*primeiro;
				ultimo=aux->pedidos;
				primeiro=aux->pedidos;
				
				while(ultimo->prox!=NULL){
					ultimo=ultimo->prox;
				}
				
				if(strcmp(primeiro->codigoPedido,codigo)==0){	//Verifica se ? o primeiro pedido
					NoPedido *substituto;
					substituto=aux->pedidos;
					if(substituto->prox==NULL){	//verifica se h? somente um pedido-> exclui a mesa
						
						if(aux->ant==NULL){		//Verifica se ? a primeira mesa da lista
						
							if(aux->prox==NULL){	//verifica se ? a unica mesa da lista-> zera a lista
								free(aux);								
								Lista=NULL;
								getchar();
								fflush(stdin);
								return Lista;
							}
							NoMesa* primeira;
							primeira=aux;
							aux=aux->prox;
							primeiro->prox=NULL;
							aux->ant=NULL;
							free(primeiro);
							Lista=aux;
							return Lista;
							
						}else if(aux->prox==NULL){	//verifica se ? a ultima
						
							aux->ant->prox=NULL;
							aux->ant=NULL;
							free(aux);
							return Lista;
							
						}else{		//se n?o ? a primeira e nem a ultima, ta no meio
							
							aux->prox->ant=aux->ant;
							aux->ant->prox=aux->prox;
							aux->prox=NULL;
							aux->ant=NULL;
							free(aux);
							return Lista;
							
						}	
						
					}else{	//H? mais de um pedido-> exclui o pedido
					
						substituto=substituto->prox;
						primeiro->prox=NULL;
						free(primeiro);
						aux->pedidos=substituto;
						return Lista;	
						
					}
					
				}else if(strcmp(ultimo->codigoPedido,codigo)==0){	//verifica se ? o ultimo pedido
				
						NoPedido *anterior;
						anterior=aux->pedidos;
						while(anterior->prox!=ultimo){
							anterior=anterior->prox;
						}
						anterior->prox=NULL;
						free(ultimo);
						return Lista;
						
				}else{	//N?o ? o primeiro nem o ultimo pedido
				
					NoPedido *apagador,*acompanhante;
					apagador=aux->pedidos;
					while(strcmp(apagador->codigoPedido,codigo)!=0){
						acompanhante=apagador;
						apagador=apagador->prox;
					}
					acompanhante->prox=apagador->prox;
					apagador->prox=NULL;
					free(apagador);
					return Lista;
					
				}
			}
		}	
	}
}

//////////////////////////////////////////////////////////////
//////////////////MANUAL DO PROGRAMA/////////////////////////
void manualPrograma(){
	system("cls");
	printf("----------------------------------------------");
	printf("\nINFORMA??ES SOBRE O PROGRAMA");
	printf("\n----------------------------------------------");
	printf("\nMENU PRINCIPAL: Permite movimenta??es entre os menus de Ivent?rio, Funcion?rios, Pedidos e Card?pio");
	printf("\n\nCARD?PIO: Exibe todos os itens cadastrados");
	printf("\n\nIVENT?RIO: Permite ao usu?rio inserir, consultar, alterar e excluir itens. Esses itens que s?o mostrados no Card?pio");
	printf("\n\nFUNCION?RIOS: Permite ao us?rio inserir, consultar, alterar e excluir informa??es sobre os gar?ons");
	printf("\n\nPEDIDOS: Neste menu ? poss?vel visualizar pedidos de uma mesa espec?fica, visualizar todos os pedidos cadastrados e fechar a conta de uma mesa.");
	printf("Al?m disso, atrav?s deste menu ? possivel inserir, alterar e excluir pedidos(Caso s? exista um pedido na mesa, ela ser? removida).No entanto, h? algumas condi??es:");
	printf("\nPara inserir um pedido ? necess?rio que o item desejado esteja cadastrado(exista no card?pio) e que o gar?om esteja cadastrado.");
	printf("\nPara alterar ou excluir um pedido ? necess?rio ter conhecimento do n?mero da mesa e do c?digo do pedido.");
	getchar();
	fflush(stdin);
}

/////////////////////////////////////////////////////////////
//////////////////////////MENUS/////////////////////////////
void Menu(NoMesa *Lista){
	int opcao=0;
	do{
		system("cls");
		printf("----------------------------------------------");
		printf("\nRESTAURANTE");
		printf("\n----------------------------------------------");
		printf("\n1)Pedidos");
		printf("\n2)Card?pio");
		printf("\n3)Produtos");
		printf("\n4)Funcion?rios");
		printf("\n5)Informa??es sobre o programa");
		printf("\n6)Sair");
		
		printf("\n\nInforme a op??o desejada: ");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao){
			case 1:
				MenuPedidos(Lista);
				break;
			case 2:
				Cardapio();
				Menu(Lista);
			case 3:
				//Arquivos com produtos
				areaProdutos();
				Menu(Lista);
				break;
			case 4:
				//arquivos com dados dos garcons
				areaGarcons();
				Menu(Lista);
				break;
			case 5:
				manualPrograma();
				Menu(Lista);
				break;
			case 6:
				exit(0);
				
		}
	}while(opcao<1 || opcao>6);	
}

void MenuPedidos(Mesas *Lista){
	int opcao=0;
	do{
		system("cls");
		printf("----------------------------------------------");
		printf("\nPEDIDOS");
		printf("\n----------------------------------------------");
		printf("\n1)Cadastrar pedido");	//OK
		printf("\n2)Alterar pedido");	//OK
		printf("\n3)Excluir pedido");	//OK
		printf("\n4)Consultar mesa");	//OK
		printf("\n5)Mostrar todos os pedidos");	//OK
		printf("\n6)Fechar Conta");	//OK
		printf("\n7)Voltar ao Menu principal");	//OK
		
		printf("\n\nInforme a op??o desejada: ");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao){
			case 1:
				Lista=AdicionarPedido(Lista);	//OK
				MenuPedidos(Lista);
				break;
			case 2:
				Lista=alterarPedido(Lista,1);	//OK
				MenuPedidos(Lista);
				break;
			case 3:
				Lista=alterarPedido(Lista,2);	//OK
				MenuPedidos(Lista);
				break;
			case 4:
				imprimirMesa(Lista);//arquivos com dados dos garcons
				MenuPedidos(Lista);
				break;
			case 5:
				imprimir(Lista);
				MenuPedidos(Lista);
				break;
			case 6:
				fecharConta(Lista);
				break;
			case 7: 
				Menu(Lista);
				break;
		}
	}while(opcao<1 || opcao>7);	
}
