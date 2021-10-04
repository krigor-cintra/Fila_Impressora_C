#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct impressora{
	int id_doc;
	int qtd;
	char ndoc[90];
	struct impressora *proximo;
};


//Criação de chave de identificação automatica 'idaut'
int a = 0;
int *b;
int idaut(){
	b=&a;
	 a=*b+1;
	 b=&a;
	return *b;
};

struct fila{
	struct impressora *primeiro, *ultimo;
};

//seria mandando o documento para 'impressão docimp', no caso você coloca o nome + quantidade
struct impressora* docimp(char nome[90],int quantidade){
	struct impressora* docimp = (struct impressora* )malloc(sizeof(struct impressora));
		docimp->id_doc = idaut();
		strcpy(docimp->ndoc , nome);
		docimp->qtd=quantidade;
		
		docimp->proximo=NULL;
};

//criação da fila de impressão 'filaimp' -  começa com os valores vazios = NULL
struct fila* filaimp(){
	struct fila* fila = (struct fila* )malloc(sizeof(struct fila));
	fila->primeiro=fila->ultimo=NULL;
};


//Ordeando a fila de documentos que chega
void enfileirar( struct fila* fila, char nome[90],int quantidade){
	struct impressora* docn = docimp(nome,quantidade);
	
	if(fila->ultimo ==NULL){
		fila->primeiro = fila->ultimo = docn;
		return;
	}
	fila->ultimo->proximo=docn;
	fila->ultimo=docn;
};

//saida do documentod quando é concluida a impressão
void docout (struct fila * fila){
	if (fila->primeiro==NULL){
		return;
	}
	struct impressora* nv = fila->primeiro;
	fila->primeiro = fila->primeiro->proximo;
	if(fila->primeiro==NULL){
		fila->ultimo;
	}
	free(nv);
};

int main() {
	int a,b,c = 0;
	char d[90];
	struct fila* fila = filaimp();
	
	printf("Quantos documentos deseja imprimir? \n");
	scanf("%i",&a);
	
	for (; b<a ; b++){
		printf("Digite o nome do Documento: \n");
		scanf("%s",&d);
		printf("Digite a quantidade que deseja imprimir: \n");
		scanf("%i",&c);
		enfileirar(fila,d,c);
		printf("Documento enviado para fila de impressao.\n");
	};
	
		printf("\nPrimeiro da fila: %d \nDocumento: %s \n",fila->primeiro->id_doc, fila->primeiro->ndoc);
	//printf("\nProximo da fila: %d \nDocumento %s \n", fila->primeiro->proximo->id_doc, fila->primeiro->proximo->ndoc);
	printf("\nUltimo  da fila: %d \nDocumento: %s \n", fila->ultimo->id_doc,fila->ultimo->ndoc );
	
	for(;b>0;b--){
		printf("\nDocumento sendo impresso: %s, \n Quantidade: %d\n",fila->primeiro->ndoc,fila->primeiro->qtd);
		docout(fila);
	};
	
	
	return 0;
}
