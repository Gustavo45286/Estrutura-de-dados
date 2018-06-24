#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

///////////////////////Bubble
void bubble_sort (int arr[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
		   if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}
////////////////////////insertion sort
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
/////////////////////////// selection sort
void selectionSort(int arr[], int n){
    int i, j, menor, troca;
 
    for (i = 0; i < n-1; i++){
        menor = i;
        for (j = i+1; j < n; j++)
			if (arr[j] < arr[menor]){
		  		menor = j;	
			}
			if( i != menor){
				troca = arr[menor];
				arr[menor] = arr[i];
				arr[i] = troca;
			}   
        
    }
}
//////////////////////////////// Merge sort

void merge(int arr[], int e, int m, int d){
    int i, j, k;
    int n1 = m - e + 1;
    int n2 =  d - m;
 
    /* cria arrays temporarios*/
    int E[n1], D[n2];
 
    /* Copia a data para os arrays temporarios E[] e D[] */
    for (i = 0; i < n1; i++){
    	E[i] = arr[e + i];
	}
        
    for (j = 0; j < n2; j++){
		D[j] = arr[m + 1+ j];	
	}
        
    /* uni os arrays temmporarios devolta em arr[e..d]*/
    i = 0; // Index inicial do primeiro subarray
    j = 0; // Index inicial do segundo subarray 
    k = e; // Index inicial dos arrays unidos
    while (i < n1 && j < n2){
        if (E[i] <= D[j]){
            arr[k] = E[i];
            i++;
        }else{
            arr[k] = D[j];
            j++;
        }
        k++;
    }
 
    /* Copia os elementos restantes de E[] caso exeista algum  */
    while (i < n1){
        arr[k] = E[i];
        i++;
        k++;
    }
 
    /* Copia os elementos restantes de D[] caso exeista algum */
    while (j < n2){
        arr[k] = D[j];
        j++;
        k++;
    }
}

/* As variaveis "e" para o index da esquerda e "d" para o index da direita assim criando os subArrays   */
void mergeSort(int arr[], int e, int d){
    if (e < d){
        
        
        int m = e+(d-e)/2;
 
        // ordena a primeira e segunda metade
        mergeSort(arr, e, m);
        mergeSort(arr, m+1, d);
 
        merge(arr, e, m, d);
    }
}
//////////////////////////////////////////////  quick sort

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
	int * vet2 = (int*)calloc(MAX, sizeof(int));	
	int * vet3 = (int*)calloc(MAX, sizeof(int));
	int * vet4 = (int*)calloc(MAX, sizeof(int));
	int * vet5 = (int*)calloc(MAX, sizeof(int));
	int i,j;
	clock_t Ticks[2];
	double Tempo;
	
	for(i=0; i < MAX ; i++){
		vet[i] = rand() % MAX ; 
		vet2[i] =vet[i];
		vet3[i] =vet[i];
		vet4[i] =vet[i];
		vet5[i] = vet[i];
	}
		
	//printArray(vet, MAX);
	
	printf("\n.:: bubble sort::.\n");
	Ticks[0] = clock();
    bubble_sort(vet, MAX);
    Ticks[1] = clock();
   // printArray(vet, MAX);
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.\n", Tempo);
	free(vet);
	
	printf("\n.:: Insertion Sort::.\n");
	Ticks[0] = clock();
	insertionSort(vet2,MAX);
    Ticks[1] = clock();
    //printArray(vet2, MAX);
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.\n", Tempo);
	free(vet2);
	
	
	printf("\n.:: Selection Sort ::.\n");
    Ticks[0] = clock();
    selectionSort(vet3, MAX);
    Ticks[1] = clock();
   // printArray(vet3, MAX);
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.\n", Tempo);
	free(vet3);
	
	
	printf("\n.:: Merge Sort ::.\n");
    Ticks[0] = clock();
    mergeSort(vet4,0, MAX -1); 
    Ticks[1] = clock();
   // printArray(vet4, MAX);
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.\n", Tempo);
	free(vet4);
	
	printf("\n.:Quick Sort::.\n");
    Ticks[0] = clock();
    quickSort(vet5, 0, MAX-1);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
    //printArray(vet5, MAX);
	printf("Tempo gasto: %g s.", Tempo);
	free(vet5);
	
	
	
	return 0;
}
