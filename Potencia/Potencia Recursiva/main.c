#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int potencia(int a,int x){
	if ( x == 1){
		return a;
	}
	return a * potencia(a, x-1);
}


int main(int argc, char *argv[]) {
	int a,b;
	printf("Digite um numero: ");
	scanf("%d",&a);
	printf("\nDigite a potencia deste numero: ");
	scanf("%d",&b);
	printf("\nO numero %d elevado a potencia %d e igual a: %d\n\n", a, b, potencia(a,b));
	
	
	system("pause");
	return 0;
}
