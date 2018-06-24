#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void insertionSort(int arr[], int n){
   int i, x, j;
   for (i = 1; i < n; i++){
       x = arr[i];
       j = i-1;
       
       while (j >= 0 && arr[j] > x){
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = x;
   }
}



void printArray(int arr[], int size){
    int i;
    printf(".::Vetor::.\n");
    printf("Pos | Valor\n");
    for (i=0; i < size; i++){
		printf("[%d] | %d\n", i, arr[i]);	
	}    
    printf("\n");
}

int main(int argc, char *argv[]) {
	
	int* vet = (int*)calloc(MAX, sizeof(int));
	int i,j;
	clock_t Ticks[2];
	double Tempo;
		
	for(i=0; i < MAX ; i++){
		vet[i] = rand() % 100000 ; 
	}
	
	printArray(vet, MAX);
	
    Ticks[0] = clock();
	insertionSort(vet,MAX);
    Ticks[1] = clock();
    
    printArray(vet, MAX);
    
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.", Tempo);
	
	
	return 0;
}
