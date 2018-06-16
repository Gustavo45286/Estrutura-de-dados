#include <stdio.h>
#include <stdlib.h>

void main(){
	int n, prox, i;
	int n1 = 0; 
	int n2 = 1;
	
	printf("Sequencia de Fribonnaci.\n\nDigite o numero de valores a serem exibidos: ");
	scanf("%d", &n);
 	
	for (i = 0; i < n; i++){
		if (i <= 1){
			prox = i;
		}else{
			prox = n1 + n2;
			n1 = n2;
			n2 = prox;
		}
    	printf("%d\n", prox);
	}
	
	system("pause");
	return ;
}


