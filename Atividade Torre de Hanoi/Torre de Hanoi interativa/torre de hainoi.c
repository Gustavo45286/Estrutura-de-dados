#include <stdio.h>
#include <stdlib.h>

void main(){
	int n, x;
	printf("insira a quantidade de discos.\n");
	scanf("%d",&n);
	printf("\n");
	for (x=1; x< (1<<n) ;x++){
		printf("move da torre %i para %i.\n",(x & x-1)% 3,((x | x-1) +1)%3);
		
	}
	
	
	
	return;
}
