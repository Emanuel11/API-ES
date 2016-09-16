#include <stdio.h>
//#define MAX 8
#include <time.h>
#define MAX 500000

void impresssao (int v[]) {
	int i;
	for(i =0; i < MAX; i++) printf("%d", v[i]);
	printf("\n");
}

void intercalacao (int v[], int inicio, int fim) {
	int meio = (inicio + fim) / 2;
	int esq = inicio;
	int dir = meio + 1;
	int aux [fim - inicio +1];
	int i = 0;
	while (esq <= meio && dir <=fim){
		if (v[esq] < v[dir] ) aux[i++] = v[esq++];
		else aux[i++] = v[dir++];
	}
	while (esq <= meio) aux[i++] = v[esq++];
	while (dir <= fim ) aux[i++] = v[dir++];
		int j = inicio;
		for (i = 0; i < fim - inicio + 1; i++, j++){
			v[j] = aux[i];
		}
}

void mergeSort (int v[], int inicio, int fim ) {
	if (inicio < fim){
		int meio = (inicio + fim) / 2;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio + 1, fim);
		intercalacao(v, inicio, fim);
	}
}

int main() {
	//int vetor [MAX] = {10, 40, 50, 80, 20, 30, 70};
	//int vetor [MAX] = {80, 70, 60, 50, 40 ,30, 20, 10};
	int vetor [MAX];
	int i; 
	srand(time(NULL));
	for (i = 0; i < MAX; i++){
		//vetor[i] = MAX - i;
		vetor[i] = rand() % MAX;
	}

	mergeSort(vetor, 0, MAX -1);
	
	//intercalacao(vetor, 0, MAX-1);
	//intercalacao(vetor, 2, 5); //escolher intervalo para aplicar a funcao intercalacao
	
	//impressao(vetor);
	return 0;
}
