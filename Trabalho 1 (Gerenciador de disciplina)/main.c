#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define MAX 45


int main(int argc, char *argv[]) {
	
	int o, b, c;
	
	lista *li = criarlista();
	
	do {	
		printf ("   .:: Gerenciador de alunos ::.\n");
		printf ("[1]. Adicionar Novo Aluno.\n");
		printf ("[2]. Adicionar Notas.\n");
		printf ("[3]. Buscar Aluno.\n");
		printf ("[4]. Verificar se um aluno esta aprovado.\n");
		printf ("[5]. Mostrar todos os alunos, aprovacoes e medias.\n");
		printf ("[6]. Remover Aluno.\n");
		printf ("[0]. Sair.\n");
		printf ("Opcao: ");
		scanf ("%d",&o);
		system("cls");
		
		switch (o){	
		
			case 1:	
				c = inserirfinal(li);
				if(	c == 0	){
					printf("Erro.\nLista Cheia ou inexistente.");
				}					
			break;
			
			case 2:
				printf("  .::Adicionar notas::.\n");
				b=buscaraluno(li);
				if(b!= -1){
					printf("\nPosicao: %d\n", b+1);					
					printf("Nome: %s\n",li->dados[b].nome);			
					printf("Matricula: %d\n", li->dados[b].matricula);
					do{
						printf("Digite a nota 1: (0 a 30)\n");
						scanf("%f", &li->dados[b].n1);	
					}while( li->dados[b].n1 < 0 || li->dados[b].n1 > 30 );
					
					do{
						printf("Digite a nota 2: (0 a 30)\n");
						scanf("%f", &li->dados[b].n2);	
					}while( li->dados[b].n2 < 0 || li->dados[b].n2 > 30 );
					
					do{
						printf("Digite a nota 3: (0 a 40)\n");
						scanf("%f", &li->dados[b].n3);	
					}while( li->dados[b].n3 < 0 || li->dados[b].n3 > 40 );					
				}	
			break;
				
			case 3:
				if(li->qtd==0){
					printf("lista vazia.\n");	
				}else{
					printf ("  .::Buscar aluno::.\n");
					b = buscaraluno(li);
					if (b != -1){
						printf("\n .::Aluno encontrado::.\n");
						printf("Posicao: %d\n", b+1);					
						printf("Nome: %s\n",li->dados[b].nome);			
						printf("Matricula: %d\n", li->dados[b].matricula);			
						printf("Nota 1: %.1f\n",li->dados[b].n1);				
						printf("Nota 2: %.1f\n",li->dados[b].n2);		
						printf("Nota 3: %.1f\n",li->dados[b].n3);
					}
				}			
			break;	
			
			case 4:
				if(li->qtd==0){
					printf("lista vazia.\n");
				}else{
					alunoaprovado(li);	
				}
					
			break;
			
			case 5:
				if(li->qtd==0){
					printf("lista vazia.\n");	
				}else{
					listaralunos(li);
				}	
			break;
				
			case 6:
				if(li->qtd==0){
					printf("lista vazia.\n");	
				}else{
					printf("  .::Remover aluno::.\n");
					remover(li);
				}
			break;
			
					
			case 0:
				printf("Saindo...");
			break;
				
			default: 
				printf ("Opcao invalida...\n");	
					
		}
		printf("\n");
		system("pause");
		system("cls");
	}while(o!=0);
	
	return 0;
}
