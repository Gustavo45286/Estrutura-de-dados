#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
        // divide a primeira e segunda metade
        mergeSort(arr, e, m);
        mergeSort(arr, m+1, d);
 		// une as metades divididas em ordem
        merge(arr, e, m, d);
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
		
//	printArray(vet, MAX);
	
	Ticks[0] = clock();
    mergeSort(vet,0, MAX -1); 
    Ticks[1] = clock();
    
   printArray(vet, MAX);
    
    Tempo = (Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC; //* 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g s.", Tempo);
	
	
	return 0;
}



