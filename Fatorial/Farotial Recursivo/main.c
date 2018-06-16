#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int fatorial(int n){
	if (n ==1){
		return 1;
	}else{
		return n*fatorial(n-1);
	}
}



int main(int argc, char *argv[]) {
	int n,result;
	printf("digite um numero: ");
	scanf("%d", &n);
	result = fatorial(n);
	printf("\nFatorial %d e: %d \n",n,result);
	
	
	system("pause");
	return 0;
}
