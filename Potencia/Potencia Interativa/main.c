#include <stdio.h>
#include <stdlib.h>

void main(){
	int x, z;
	int i;
	
	printf("Calculo de uma potencia .\n\n");
	printf("Digite um numero: ");
	scanf("%d", &x);
	printf("Digite a seu expoente: ");
	scanf("%d", &z);
	
	
	if(z==0){
		x = 1;
	}else{
		int j = x;
		for (i =1; i < z; i++ ){
			x *= j;
		}	
	}
	
	printf("Resultado: %d \n",x);
	
	system("pause");
	return ;
}
