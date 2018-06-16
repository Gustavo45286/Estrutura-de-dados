#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//os dados que cada nó carrega
typedef struct Datanode{
	char nome[30];
    char pressao[10];
    double temperatura;
    char sintoma[140];
    int id;
	char condicao[15];
	
} datanode;

//Nó carregando uma struct de dados e um ponteiro para o proximo nó
typedef struct Node{
	datanode data;
	struct Node* next;
} node;

//lista que possui inmformaçao sobre o tamanho da lista e um ponteiro para o primeiro nó
typedef struct Lista{
	int size;
	node *head;
} lista;


lista* createlist(){
	lista* li = (lista*) malloc(sizeof(lista));
	
	li->size = 0 ;
	li->head = NULL;
	return li;
}

datanode informacoes(){
	datanode dados;
	int o;
	printf(".:: Dados do Paciente ::.\n");
	printf("Nome: ");
	scanf(" %[^\n]s", dados.nome);
	printf("Sintoma: ");
	scanf(" %[^\n]s", dados.sintoma);
	printf("Pressao: ");
	scanf(" %[^\n]s", dados.pressao);
	printf("Temperatura: ");
	scanf(" %d", &dados.temperatura);
	do{
		printf("\n.::Escolha uma condicao:..\n");
		printf("1. Azul.\n");
		printf("2. Verde.\n");
		printf("3. Amarelo.\n");
		printf("4. Vermelho.\n");
		scanf("%d", &o);
		switch(o){
			case 1:
				dados.id = o;
				//c = "Azul";
				strcpy(dados.condicao, "Azul");
			break;
			
			case 2:
				dados.id = o;
				//c= "Verde";
				strcpy(dados.condicao, "Verde");
			break;
			
			case 3:
				dados.id = o;
			//	c  = "Amarelo";
				strcpy(dados.condicao, "Amarelo");
			break;
			
			case 4:
				dados.id = o;
			//	c = "Vermelho";
       			strcpy(dados.condicao, "Vermelho");
			break;
			
			default:
				printf("Condicao invalida.\n");
		}	
	}while((o <1) && (o > 4));
	printf("\n");
   	system("pause");
   	system("cls");
   	
	return dados;
}

void push(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	node* novo = (node*) malloc(sizeof(node));
	
	novo->data = informacoes();
	novo->next = li->head;
	li->head = novo;
	li->size++;

	
}

void removeFim(lista* li){
	if( li== NULL){
		printf(" Fila Nula.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Fila vazia.\n\n");
		return;
	}
	if(li->size == 1){
		printf("\nChamando Paciente.\n");
		printf("Condicao: %s\n", li->head->data.condicao);
		printf("Nome: %s\n", li->head->data.nome);
		printf("Sintoma: %s\n", li->head->data.sintoma);
		printf("Pressao: %s\n", li->head->data.pressao);
		printf("Temperatura: %d\n", li->head->data.temperatura);
		free(li->head);
		li->head = NULL;
		li->size--;			
	}else{
		node* pointer = li->head;
	
		while( pointer->next->next != NULL){	
			pointer = pointer->next;	
		}
		
		printf("\nChamando Paciente.\n");
		printf("Condicao: %s\n", pointer->next->data.condicao);
		printf("Nome: %s\n", pointer->next->data.nome);
		printf("Sintoma: %s\n", pointer->next->data.sintoma);
		printf("Pressao: %s\n", pointer->next->data.pressao);
		printf("Temperatura: %d\n", pointer->next->data.temperatura);
		
		free(pointer->next);
		pointer->next = NULL;
		li->size--;			
	}
}


void printList(lista* li){
	if( li== NULL){
		printf(" Fila Nula.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Fila vazia.\n\n");
		return;
	}
	
	int i= li->size;
	node* pointer = li->head;
	
	printf(".:: Pacietes ::..");
	while( pointer != NULL){
		printf("\nPaciente %d.\n", i);
		printf("Condicao: %s\n", pointer->data.condicao);
		printf("Nome: %s\n", pointer->data.nome);
		printf("Sintoma: %s\n", pointer->data.sintoma);
		printf("Pressao: %s\n", pointer->data.pressao);
		printf("Temperatura: %d\n", pointer->data.temperatura);
		pointer = pointer->next;
		i--;
	}
	printf("\n");		
}

int menu(int x){
	printf(".:: Fila de Atendimento ::.\n");
	printf("1. Atendente.\n");
	printf("2. Medico.\n");
	printf("0. Sair.\n");
	printf("Escolha uma opcao: ");
	scanf("%d",&x);
	system("cls");
	return x;
}


void inserirPaciente(lista* li){
	if( li== NULL){
		printf(" Fila nula.\n\n");
		return;
	}
	if(li->size ==0){
		push(li);
		return;
	}
	node* novo = (node*) malloc(sizeof(node));
	novo->data = informacoes();
	
	if((li->size == 1) && (novo->data.id <= li->head->data.id )){
		novo->next = li->head;
		li->head = novo;
		li->size++;
		return;
	}
	
	node* pointer = li->head;
	
	while(pointer != NULL){
		
		if(pointer->next== NULL){
			novo->next = NULL;
			pointer->next = novo;
			li->size++;
			return;
		}else if(li->head->data.id > novo->data.id){
			novo->next = li->head;
			li->head = novo;
			li->size++;
			return;	
		}else if(novo->data.id <= pointer->next->data.id){
			novo->next = pointer->next;
			pointer->next = novo;
			li->size++;
			return;	
		}
		pointer = pointer->next;
	};
}

