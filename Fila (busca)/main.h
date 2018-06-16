#include <stdio.h>
#include <stdlib.h>


//os dados que cada nó carrega
typedef struct Datanode{
	char nome[30];
	int id;
	
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

//
lista* createlist(){
	lista* li = (lista*) malloc(sizeof(lista));
	
	li->size = 0 ;
	li->head = NULL;
	return li;
}

// adiciona um membro no final da fila
void push(lista* li){
	if( li== NULL){
		printf(" Fila nula.\n\n");
		return;
	}
	node* novo = (node*) malloc(sizeof(node));
	datanode da;
	
	printf("\n.:: Dados ::.\n");
	printf(" id: ");
    scanf(" %d", &da.id);
	printf(" Nome: ");
    scanf(" %s", da.nome); //[^\n] 

	novo->data = da;
	novo->next = li->head;
	li->head = novo;
	li->size++;

}

//remove o primeiro membro da fila
void removeFim(lista* li){
	if( li== NULL){
		printf(" Fila nula.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Fila vazia.\n\n");
		return;
	}
	
	if(li->size == 1){
		free(li->head);
		li->head = NULL;
		li->size--;				
	}else{
		node* pointer = li->head;
	
		while( pointer->next->next != NULL){	
			pointer = pointer->next;	
		}
		
		free(pointer->next);
		pointer->next = NULL;
		li->size--;			
	}
	
}
//mostra todos os membros da fila
void printList(lista* li){
	if( li== NULL){
		printf(" Fila nula.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Fila vazia.\n\n");
		return;
	}
	
	int i= 0;
	node* pointer = li->head;
	
	printf("\n\n.:: Fila ::..\nQuantidade de menbros %d.\n\n", li->size);
	while( pointer != NULL){
		printf("Membro %d.\n",i);
		printf("Nome: %s.\n", pointer->data.nome );
		printf("id: %d.\n", pointer->data.id );
		pointer = pointer->next;
		i++;
	}
	printf("\n");		
}

//busca por im membro da fila atraves de sua posicao (iniciando em 0)
void buscaListaPos(lista* li){
	if( li== NULL){
		printf(" Fila Nula.\n\n");
		return;
	}
	if( li->size==0){
		printf(" Fila vazia.\n\n");
		return;
	}
	
	int pos, i;
	printf("\nDigite uma posicao para busca na Fila: ");
	scanf("%d", &pos);
	
	if( pos > li->size){
		printf("Posicao invalida.\n\n");
		return;
	}
	
	if(pos == 0){
		printf("\nMembro 0.\n");
		printf("Nome:   %s.\n", li->head->data.nome );
		printf("id: %d.\n", li->head->data.id );
	}else{
		node* pointer = li->head;
		
		for(i= 0; i < pos ;i++){
			pointer = pointer->next;
		};
	
		printf("\nMembro %d.\n",&i);
		printf("Nome:   %s.\n", pointer->data.nome );
		printf("Tid: %d.\n", pointer->data.id );	
	}
	
	
}
