//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 12

/*Exercício 12 (ordenacao.c). Um algoritmo de ordenação consiste em um método computacional
que recebe um vetor V de dimensão n contendo valores numéricos desordenados, e retorna o vetor
V ajustado com os elementos menores precedendo os maiores (isto é, coloca-os em ordem).
Um dos algoritmos mais famosos de ordenação de fácil implementação é o algoritmo conhecido
por ‘Ordenação por Seleção’. Ele recebe um vetor V de entrada e varre-o em ordem crescente de
8índice, buscando um substituto de menor magnitude dentre os elementos ainda não inspecionados
para substituir pelo elemento da i-ésima posição em inspeção. Um pseudo-código da ordenação por
seleção é dada no Algoritmo 2.*/

#include <stdio.h>
#include <stdlib.h>

void ordena(int* vet, int tam);
void ordena(int* vet, int tam){

	for (int i = 0; i < tam; i++){

		int menor;
		int aux;

		menor = i;

		for(int j = i + 1; j < tam; j++){
				
				if (vet[menor] > vet[j]){
					menor = j;
				}
		}

		if(i != menor){
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
		}
	}

	printf("Vetor ordenado: ");

	for (int i = 0; i < tam; i++){
		printf("%d ",vet[i]);
	}

	printf("\n");
}

void main(){

	int tam;
	int *vet;

	printf("Quantos elementos o vetor terá\n");
	scanf("%d",&tam);

	vet = malloc(tam * sizeof(int));

	for (int i = 0; i < tam; i++){
	
		printf("Qual é o número da %d° posição do vetor ?\n",i+1);
		scanf("%d",&vet[i]);
	}

	printf("Vetor original: ");
	for (int i = 0; i < tam; i++){
		printf("%d ",vet[i]);
	}

	printf("\n");

	ordena(vet,tam);
	free(vet);
}
