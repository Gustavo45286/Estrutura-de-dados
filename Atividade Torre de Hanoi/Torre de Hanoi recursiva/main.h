#include <stdio.h>
#include <stdlib.h>



//os dados que cada nó carrega
typedef struct Datanode{
	int disco;
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


void push(lista* li, int da){
	node* novo = (node*) malloc(sizeof(node));
	
	novo->data.disco = da;
	novo->next = li->head;
	li->head = novo;
	li->size++;

	
}

void pop(lista* li){
	
	if( li->size==0){
		printf("Pino vazio.\n\n");
		return;
	}
	
	node* pointer = li->head;
	li->head = li->head->next;
	free(pointer);
	li->size--;
		
}

void printar(lista* li){
	
	if( li->size==0){
		printf(" Pino vazio.\n\n");
		return;
	}
	
	node* pointer = li->head;
	
	while( pointer != NULL){
		printf("  %d\n", pointer->data.disco );
		pointer = pointer->next;
	}
	printf("\n");		
}


//move o disco do topo de uma lista para outra
void move(lista* a,lista* b){
	if( a->size==0){
		printf("Pino vazio.\n\n");
		return;
	}
	
	node* pointer = a->head;
	a->head = a->head->next;
	a->size--;
	
	pointer->next = b->head;
	b->head = pointer;
	b->size++;
	

	
}

//preenche uma lista com certa quantidade de discos
void preencher_pino(lista* li, int qtd){
	do {
		push(li, qtd);
		qtd--;
	}while( qtd > 0);
	
	
}

// HANOI TOWER !!!(com recursao)
void hanoi(lista* origem,lista* destino,lista* auxiliar, int qtd){
	if(qtd == 1){
		printf("----------------------------------------\n.:Movendo discos:.\n\n");
		move(origem, destino);
		printf(".:origem:.\n\n");
		printar(origem);
		printf(".:auxiliar:.\n\n");
		printar(auxiliar);
		printf(".:destino:.\n\n");
		printar(destino);
		return;
	}else{
		hanoi(origem,auxiliar,destino,qtd-1);
		printf("----------------------------------------\n.:Movendo discos:.\n\n");
		move(origem, destino);
		printf(".:origem:.\n\n");
		printar(origem);
		printf(".:auxiliar:.\n\n");
		printar(auxiliar);
		printf(".:destino:.\n\n");
		printar(destino);
		hanoi(auxiliar,destino,origem, qtd-1);
	}
		
}
