#include <stdio.h>
#include <stdlib.h>


int fribonnaci(int n){
  if (n == 0 || n == 1)
    return n;
  else
    return (fribonnaci(n-1) + fribonnaci(n-2));
}

void main(){
	int n, i = 0, j;
  
	printf("Digite a quantidade de termos:\n");
	scanf("%d", &n);
	printf("\nOs termos sao:\n");
	
	for (j = 1; j <= n; j++){
    	printf("%d\n", fribonnaci(i));
    	i++;
	}
 
  return;
}
 

