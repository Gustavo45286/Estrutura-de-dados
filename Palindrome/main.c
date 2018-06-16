#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[]) {
	
	datanode da;
	lista* pilhaA = createlist();
	lista* pilhaB = createlist();
	
	printf("Digite uma palavra letra por letra para verificar se e um palindrome.\n\n");
	do{
		printf("Digite uma letra da palavra ou 0 para parar: ");
		scanf(" %[^\n]s", &da.letra);
		if (( (strcmp(da.letra, "0" )) != 0)){
			push(pilhaA, da);
		}
				
	}while( (strcmp(da.letra, "0" )) != 0);
	

	copiaInvertido(pilhaA,pilhaB);
	
	printf("\nPilha 2. \nPalavra: ");
	printar(pilhaB);
	printf("\nPilha 1.\nPalavra: ");
	printar(pilhaA);

	palindrome(pilhaA,pilhaB);
	
	system("pause");
	return 0;
}
