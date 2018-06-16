#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	lista* agenda = createlist();
	int o;
	
	do{
		o = menu (o);
		switch (o){
		
			case 1:
				inserirContato(agenda);
			break;
				
			case 2:
				buscarContato(agenda);
			break;
		
			case 3:
				removerContato(agenda);
			break;
		
			case 4:
				printList(agenda);
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
