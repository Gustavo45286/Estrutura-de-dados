#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
Criar uma lista de prioridade para um pronto socorro
Duas visoes
	-Atendente
		->Cadastrar Paciente 
			->incerir paciente na fila (ordenado por prioridade)
			   -> Dados
				  -Nome
				  -Pressão
				  -Temperatura
				  -Sintoma
				  ->Condição 	(^ +) prioridade 
						-vermelho
						-amarelo		
						-verde
						-azul
	-Médico
		-Chamar paciente (remove primeiro da fila)
		-Listar Paciente (listar todos os pacientes)
*/

int main(int argc, char *argv[]) {
	lista* fila = createlist();
	int o, g;
	
	do{
		o = menu (o);
		switch (o){
			case 1:
				do{
					printf(".:: Atendente ::..\n");
					printf("1. Inserir paciente.\n");
					printf("2. Mostrar fila de atendimento.\n");
					printf("0. Voutar.\n");
					printf("escolha uma opcao: ");
					scanf("%d", &g);
					system("cls");
					switch(g){
					
						case 1:
							inserirPaciente(fila);
						break;
					
						case 2:
							printList(fila);
						break;
					
						case 0:
							printf("Voutando...");
						break;
		
						default:
        				    printf("Opcao invalida."); 
					}
					printf("\n");
    			    system("pause");
    			    system("cls");
				}while(g != 0 );
			break;
				
			case 2:
				do{
					printf(".:: Medico ::..\n");
					printf("1. Chamar paciente.\n");
					printf("2. Mostrar fila de atendimento.\n");
					printf("0. Voutar.\n");
					printf("escolha uma opcao: ");
					scanf("%d", &g);
					system("cls");
					switch(g){
					
						case 1:
							removeFim(fila);
						break;
					
						case 2:
							printList(fila);
						break;
					
						case 0:
							printf("Voutando...");
						break;
		
						default:
        				    printf("Opcao invalida."); 
					}
					printf("\n");
    			    system("pause");
    			    system("cls");
				}while(g != 0 );
				
			break;
		
			case 0:
				printf("Saindo...");
			break;
		
			default:
        	    printf("Opcao invalida.");    
        }
        
        printf("\n");
        system("pause");
        system("cls");		
	}while(o != 0);
		
	return 0;
}
