#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN 10
#define MAX_COL 10

int main(int argc, char *argv[]) {
	
	int mat[MAX_LIN][MAX_COL];
	int mat2[MAX_LIN][MAX_COL];
	int mat3[MAX_LIN][MAX_COL];
	int i, j, k;
	
	//Preencher matriz 
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
		
		//	mat[i][j]= (j+1)+(i*10);		 //preencher toda a matriz de 1 a 100
			mat[i][j]= i+1;					//preencher matriz com o indice de linha +1
		}
	}
	
	printf(".::Matriz impressa::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			printf("[%d]",mat[i][j]);
			
		}
		printf("\n");
	}
	
	
	printf("\n\n.::Diagonal principal::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			
			if (i==j){
				printf("[%d]",mat[i][j]);
			}else{
				printf("[--]");	
			}
			
		}
		printf("\n");
	}
	
	
	printf("\n\n.::Diagonal secundaria::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			
			if (i+j==9){
				printf("[%d]",mat[i][j]);
			}else{
				printf("[--]");	
			}
			
		}
		printf("\n");
	}
	
	printf("\n\n.::Triangulo superior::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			
			if ((i==j)||(i+j<=j*2)){
				printf("[%d]",mat[i][j]);
			}else{
				printf("[--]");	
			}
			
		}
		printf("\n");
	}
	
	
	printf("\n\n.::Triangulo inferior::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			
			if ((i==j)||(i+j>=j*2)){
				printf("[%d]",mat[i][j]);
			}else{
				printf("[--]");	
			}
			
		}
		printf("\n");
	}	
	
	
	printf("\n\n.::Multiplicar Matrizez::.\n");
	printf("Multiplicando a Matriz1 pela Matriz2.\n\n");
	
	printf(".::Matriz1::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			printf("[%d]",mat[i][j]);
			
		}
		printf("\n");
	}
	
	
	//Preencher matriz2 
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
		//	mat2[i][j]= (((MAX_LIN*MAX_COL)-j)-(i*10)); 		  //preencher toda a matriz de 100 a 1.
			mat2[i][j]= i+1;									//preencher matriz com o indice de linha +1.	
		}
	}
	
	//zerar matriz3
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			mat3[i][j]= 0;
			
		}
	}
	
	
	printf("\n\n.::Matriz2::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			printf("[%d]",mat2[i][j]);
			
		}
		printf("\n");
	}
	

	
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			for(k=0 ; k< MAX_LIN;k++){
				mat3[i][j]	+= mat[i][k]*mat2[k][j]; 
				
			}	
		}
	}
	
	printf("\n\n.::Resultado::.\n\n");
	for(i=0; i < MAX_LIN; i ++){
		for(j=0; j < MAX_COL; j++){
			printf("[%d]",mat3[i][j]);
			
		}
		printf("\n");
	}
	
	
	
	return 0;
}
