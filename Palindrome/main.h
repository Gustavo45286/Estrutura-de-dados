#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//os dados que cada nó carrega
typedef struct Datanode{
	char letra[2];
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


void push(lista* li, datanode da){
	if( li==NULL ){
		printf("Pilha nula.\n\n");
		return;
	}
	
	node* novo = (node*) malloc(sizeof(node));
	
	novo->data = da;
	novo->next = li->head;
	li->head = novo;
	li->size++;

}

void pop(lista* li){
	if( li==NULL ){
		printf("Pilha nula.\n\n");
		return;
	}
	if( li->size==0){
		printf("Pilha vazia.\n\n");
		return;
	}
	
	node* pointer = li->head;
	li->head = li->head->next;
	free(pointer);
	li->size--;
		
}

void printar(lista* a){
	if( a ==NULL ){
		printf("Pilha nula.\n\n");
		return;
	}
	if( a->size==0){
		printf("Pilha vazia.\n\n");
		return;
	}

	node* pointer = a->head;
	
	while( pointer != NULL){
		printf("%s", pointer->data.letra );
		pointer = pointer->next;
	}
	printf("\n");		
}


void copiar(node* a,lista* b){
	
	node* novo = (node*) malloc(sizeof(node));
	
	novo = a;
	novo->next = b->head;
	b->head = novo;
	b->size++;
		
}

void copiaInvertido(lista* a, lista* b){
	if( a->size==0){
		printf("Pilha vazia.\n\n");
		return;
	}
	if( a== NULL){
		printf("Pilha de origem vazia.\n\n");
		return;
	}
	if( b== NULL){
		printf("Pilha de destino vazia.\n\n");
		return;
	}
	
	node* pointer = a->head;

	while( pointer != NULL){
		push(b, pointer->data);
		pointer=pointer->next;
	}
	
}

void palindrome(lista* a, lista* b){
	if( a== NULL){
		printf("Pilha de origem vazia.\n\n");
		return;
	}
	if( a->size==0){
		printf("Pilha vazia.\n\n");
		return;
	}
	if( b== NULL){
		printf("Pilha de destino vazia.\n\n");
		return;
	}
	if( a->size==0){
		printf("Pilha vazia.\n\n");
		return;
	}
	
	node* pA = a->head;
	node* pB = b->head;
	int i, j =0;
	
	while(pA != NULL){
		if( (strcmp(pA->data.letra, pB->data.letra ))== 0 ){
			j++;
		}
		pA = pA->next;
		pB = pB->next;	
	}
	
	if ( j == a->size){
		printf("\nEsta palavra e um palindrome.\n");
	}else{
		printf("\n esta palavra nao e um palindrome.\n");
	}
	
}
