#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void merge(int *vetor, int inicio, int metade, int fim, int crescente){
	int index1, index2, index, tamanho;
	tamanho = fim-inicio+1;
	int* temp = malloc(sizeof(int)*tamanho);
	index1 = inicio;
	index2 = metade+1;
	index = 0;

	//Comparações de uma metade com outra
	if(crescente==1){
		while(index1 <= metade && index2 <= fim){
			if(vetor[index1] < vetor[index2]){
				temp[index] = vetor[index1];
				index1++;
			}
			else{
				temp[index] = vetor[index2];
				index2++;
			}
			index++;
		}
	}
	else{
		while(index1 <= metade && index2 <= fim){
			if(vetor[index1] > vetor[index2]){
				temp[index] = vetor[index1];
				index1++;
			}
			else{
				temp[index] = vetor[index2];
				index2++;
			}
			index++;
		}
	}
	//Copia numeros que sobraram na primeira metade(se sobrarem)
	for( ; index1 <= metade; index1++, index++)
	    temp[index] = vetor[index1];

	//Copia numeros que sobraram na segunda metade(se sobrarem)
	for( ; index2 <= fim; index2++, index++)
	    temp[index] = vetor[index2];

	//Copia o resultado do temporário para o vetor original
	for(index=inicio; index<=fim; index++)
		vetor[index] = temp[index-inicio];
	
	free(temp);
}

void mergeSort(int *vec, int inicio, int fim, int crescente){
	if(inicio < fim){
		int metade = (inicio + fim)/2;
		
		mergeSort(vec, inicio, metade, crescente);
		mergeSort(vec, metade+1, fim, crescente);
		merge(vec, inicio, metade, fim, crescente);
	}
}

void printVetor(int* vetor, int size, char str[128]){
	int i;
	printf("%s", str);
	for(i=0; i<size-1; i++)
		printf("%d ", vetor[i]);
		
	printf("%d\n", vetor[i]);
}

int main(){
	int size, i;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &size);
	int* vetor = malloc(sizeof(int)*size);
	
	printf("Preencha o vetor:\n");
	for(i=0; i<size; i++)
		scanf("%d", vetor+i);
		
	mergeSort(vetor, 0, size-1, true);
	printVetor(vetor, size, "Vetor crescente:\n");
	mergeSort(vetor, 0, size-1, false);
	printVetor(vetor, size, "Vetor decrescente:\n");
	
	free(vetor);
	system("pause");
	return 0;
}
