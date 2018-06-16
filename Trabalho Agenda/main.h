#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//os dados que cada nó carrega
typedef struct Datanode{
	char nome[30];
	char telefone[30];
	
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


void push(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	node* novo = (node*) malloc(sizeof(node));
	datanode da;
	
	printf("\n.:: Dados ::.\n");
	printf(" Nome: ");
    scanf(" %[^\n]s", da.nome);
    printf(" Tel: ");
    scanf(" %[^\n]s", da.telefone);
	
	novo->data = da;
	novo->next = li->head;
	li->head = novo;
	li->size++;

	
}


void pop(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	node* pointer = li->head;
	li->head = li->head->next;
	free(pointer);
	li->size--;
	printf("Contato Removido.\n");
		
}


void inserirFim(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if(li->size == 0){
		printf("Agenda vazia, inserindo no inico.\n");
		push(li);
		return;
	}
	node* pointer = li->head;
	node* novo = (node*) malloc(sizeof(node));
	
	datanode da;
	
	printf("\n.:: Dados ::.\n");
	printf(" Nome: ");
    scanf(" %[^\n]s", da.nome);
    printf(" Tel: ");
    scanf(" %[^\n]s", da.telefone);
	
	while( pointer->next != NULL){
		pointer = pointer->next;	
	}
	
	novo->data = da;
	novo->next = NULL;
	pointer->next = novo;
	li->size++;
	
}


void removeFim(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	if(li->size == 1){
		free(li->head);
		li->head = NULL;
		li->size--;	
		printf("Contato Removido.\n");				
	}else{
		node* pointer = li->head;
	
		while( pointer->next->next != NULL){	
			pointer = pointer->next;	
		}
		
		free(pointer->next);
		pointer->next = NULL;
		li->size--;
		printf("Contato Removido.\n");			
	}
}


void inserirOrdenado(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	if(li->size == 0){
		printf("Agenda vazia, inserindo no inico.\n");
		push(li);
		return;
	}
	
	int pos;
	printf("\nDigite uma posicao na lista: ");
	scanf("%d", &pos);
	
	if( pos > li->size){
		printf("Posicao invalida.\n\n");
		return;
	}
	
	datanode da;
	printf("\n.:: Dados ::.\n");
	printf(" Nome: ");
    scanf(" %[^\n]s", da.nome);
    printf(" Tel: ");
    scanf(" %[^\n]s", da.telefone);
    
	if(pos == 0){
		node* novo = (node*) malloc(sizeof(node));
		novo->data = da;
		novo->next = li->head;
		li->head = novo;
		li->size++;
		return;
	}
	
	int i= 0;
	node* pointer = li->head;
		
	for(i= 0; i < pos-1 ;i++){
		pointer = pointer->next;
	};

	node* novo = (node*) malloc(sizeof(node));
	
	novo->data = da;
	novo->next = pointer->next;
	pointer->next = novo;
	li->size++;
	
	
}


void removeOrdenado(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	int pos;
	printf("\nDigite uma posicao na lista: ");
	scanf("%d", &pos);
	
	if( pos > li->size){
		printf("Posicao invalida.\n\n");
		return;
	}
	
	if(pos == 0){
		pop(li);
		
	}else{
		int i= 0;
		node* pointer = li->head;
		node* del = li->head;
		for(i= 0; i < pos-1 ;i++){
			pointer = pointer->next;
			del = pointer->next;
		};
		del = pointer->next;
		pointer->next= pointer->next->next;
		free(del);
		printf("Contato Removido.\n");	
	}
		
}


void buscarListaPos(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	
	int pos, i;
	printf("\nDigite uma posicao na lista: ");
	scanf("%d", &pos);
	
	
	if( pos > li->size){
		printf("Posicao invalida.\n\n");
		return;
	}
	
	if(pos == 0){
		printf("\nContato 0.\n");
		printf("Nome:   %s.\n", li->head->data.nome );
		printf("Telefone: %s.\n", li->head->data.telefone );
		return;
	}
	
	node* pointer = li->head;
		
	for(i= 0; i < pos ;i++){
		pointer = pointer->next;
	};
	
	printf("\nContato %d.\n",&i);
	printf("Nome:   %s.\n", pointer->data.nome );
	printf("Telefone: %s.\n", pointer->data.telefone );
	
}


void buscarListaNome(lista* li){
	
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	char nome[30];
	printf("\nDigite um nome da lista: ");
	scanf(" %[^\n]s", nome);
	
	
	node* pointer = li->head;
	int i;

	while( pointer != NULL){
		if (strcmp( nome, pointer->data.nome ) == 0){
			printf("\nContato Encontrado %d.\n", i);
			printf("Nome:   %s.\n", pointer->data.nome );
			printf("Telefone: %s.\n", pointer->data.telefone );
			return;	
		}
		pointer = pointer->next;
		i++;
	}
	
	printf("\nContato nao encontrado.\n");
	return;
}


void printList(lista* li){
	if( li== NULL){
		printf(" Agenda vazia.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Agenda vazia.\n\n");
		return;
	}
	
	int i= 0;
	node* pointer = li->head;
	
	printf(".:: Contatos ::..");
	while( pointer != NULL){
		printf("\nContato %d.\n",i);
		printf("Nome:   %s.\n", pointer->data.nome );
		printf("Telefone: %s.\n", pointer->data.telefone );
		pointer = pointer->next;
		i++;
	}
	printf("\n");		
}


int menu(int x){
	printf(".:: Agenda ::.\n");
	printf("1. Inserir Contato.\n");
	printf("2. Buscar Contato.\n");
	printf("3. Remover Contato.\n");
	printf("4. Exibir Contatos.\n");
	printf("0. Sair.\n");
	printf("Escolha uma opcao: ");
	scanf("%d",&x);
	system("cls");
	return x;
}


void inserirContato(lista* li){
	int o;
	do{
		printf(".:: Inserir Contato ::.\n");
		printf("1. inserir no inicio.\n");
		printf("2. inserir no fim.\n");
		printf("3. inserir em uma posicao especifica.\n");
		printf("0. voltar.\n");
		printf("Escolha uma opcao: ");
		scanf("%d",&o);
		switch(o){
			case 1:
				push(li);
			break;
			
			case 2:
				inserirFim(li);
				
			break;
			
			case 3:
				inserirOrdenado(li);
				
			break;
			
			case 0:
				printf("voltando...\n");
			break;
			
			default:
				printf("opcao invalida.");
		}
		printf("\n");
        system("pause");
        system("cls");
	}while(o !=0);	
	
	
	
}


void buscarContato(lista* li){
	int o;
	do{
		printf(".:: Buscar Contato ::.\n");
		printf("1. Buscar por nome.\n");
		printf("2. Buscar or posicao.\n");
		printf("0. voltar.\n");
		printf("Escolha uma opcao: ");
		scanf("%d",&o);
		switch(o){
			case 1:
				buscarListaPos(li);
			break;
			
			case 2:
				buscarListaNome(li);
				
			break;
				
			case 0:
				printf("voltando...\n");
			break;
			
			default:
				printf("opcao invalida.");
		}
		printf("\n");
        system("pause");
        system("cls");
	}while(o !=0);	
}


void removerContato(lista* li){
	int o;
	do{
		printf(".:: Remover Contato ::.\n");
		printf("1. remover no inicio.\n");
		printf("2. remover no fim.\n");
		printf("3. remover em uma posicao especifica.\n");
		printf("0. voltar.\n");
		printf("Escolha uma opcao: ");
		scanf("%d",&o);
		switch(o){
			case 1:
				pop(li);
			break;
			
			case 2:
				removeFim(li);
				
			break;
			
			case 3:
				removeOrdenado(li);
				
			break;
			
			case 0:
				printf("voltando...\n");
			break;
			
			default:
				printf("opcao invalida.");
		}
		printf("\n");
        system("pause");
        system("cls");
	}while(o !=0);	
	
}
