#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main(int argc, char *argv[]) {
	
	lista* fila = createlist();
	
	push(fila);
	push(fila);
	push(fila);

	printList(fila);
	
	removeFim(fila);
	
	buscaListaPos(fila);
	
	
	
	
	return 0;
}
