#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*	Essa funcao pega o ultimo elemento como pivo, colocando-o
	em sua posicao correta no array organizado com os elementos menores
	a sua direita e o maiores a sua esquerda
*/
int partition (int arr[], int low, int high){
    int pivo = arr[high];    // pivo
    int i = (low - 1);  // Index do menor elemento
	int j, t;
    for (j = low; j <= high- 1; j++){
        // se o elemento atual for menor ou igual ao pivo
        if (arr[j] <= pivo){
            i++;  // incrementa a index do menor elemento 
            t = arr[i];
            arr[i] = arr[j] ;
			arr[j] = t;
        }
    }
    t = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = t;
    return (i + 1);
}

/* Funcao principal que implementa o quicksort
	arr[]: Array a ser organizado
	low: index do inicio
	high: index do fim
*/
void quickSort(int arr[], int low, int high){
    if (low < high){
        /* pi e a index da particao */
        int pi = partition(arr, low, high);
 		// organiza separadamente os elemento antes de depois do ponto de particao
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(vet, 0, MAX-1);
    Ticks[1] = clock();
    
    printArray(vet, MAX);
    
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.", Tempo);
	
	
	return 0;
}

