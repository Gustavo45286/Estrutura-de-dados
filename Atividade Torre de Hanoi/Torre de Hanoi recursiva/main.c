#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main(int argc, char *argv[]) {
	//criando os 3 pinos
	lista* pino_origem = createlist();
	lista* pino_destino = createlist();
	lista* pino_auxiliar = createlist();
	//quantidade de discos
	int qtd = 3;

	preencher_pino(pino_origem, qtd);
		
	printf(".: Conteudo dos Pinos:.\n\n");
	printf(".:origem:.\n");
	printar(pino_origem);
	printf(".:auxiliar:.\n");
	printar(pino_auxiliar);
	printf(".:destino:.\n");
	printar(pino_destino);
	
	hanoi(pino_origem, pino_destino, pino_auxiliar, qtd);
	
	return 0;
}
