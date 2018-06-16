#include <stdio.h>
#include <stdlib.h>

void main(){
	int x;
	int i;
	int j = 1;
	
	printf("Calculo de um fatorial.\n\n");
	printf("Digite um numero: ");
	scanf("%d", &x);
	
	
	for (i =0; i < x; i++ ){
		j = j*(i+1);
	}
	printf("O fatorial de %d e: %d.\n\n", x, j);

	system("pause");
	return ;
}
