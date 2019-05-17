//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 14

/*Exercício 14 (prodmatriz.c). O Algoritmo 3 descreve, em pseudo-código, as operações necessárias
para realizar o produto de uma matriz A nn por uma matriz B nn .
Algoritmo 3 OPERACAO-COM-MATRIZES(A: matriz n × n, B: matriz n × n)
1: {Realiza a multiplicação C = A × B}
2: for i ← 1 to n do
3:
for j ← 1 to n do
4:
c ij ← 0
5:
for k ← 1 to n do
6:
c ij ← c ij + a ik · b kj
7:
end for
8:
end for
9: end for
Isto posto, escreva um programa em linguagem C que receba as dimensões de duas matrizes quadradas
A e B, preenche cada elemento das matrizes segundo o que o usuário informar via console aplica o
Algoritmo 3 para calcular o produto matricial A × B.*/

#include <stdlib.h>
#include <stdio.h>

int main(){

	int **mat;
	int **mat1;
	int **res;
	int dim;

	printf("Qual é a dimensão da matriz ?\n");
	scanf("%d",&dim);

	mat = malloc(dim * sizeof(int));
	mat1 = malloc(dim * sizeof(int));
	res = malloc(dim * sizeof(int));

	for (int i = 0; i < dim; i++){
		mat[i] = malloc(dim * sizeof(int));
		mat1[i] = malloc(dim * sizeof(int));
		res[i] = malloc(dim * sizeof(int));
	}

	for (int i = 0; i < dim; i++){

		for (int j = 0; j < dim; j++){

			printf("Matriz 1 linha %d coluna %d recebe:\n",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}

	for (int i = 0; i < dim; i++){

		for (int j = 0; j < dim; j++){

			printf("Matriz 2 linha %d coluna %d recebe:\n",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}

	for (int i = 0; i < dim; i++){

		for (int j = 0; j < dim; j++){

			res[i][j] = 0;
			
			for (int k = 0; k < dim; k++){
				res[i][j] += mat[i][k] * mat1[k][j];
			}
		}
	}

	for (int i = 0; i < dim; i++){

		for (int j = 0; j < dim; j++){

			printf("%d ",res[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < dim; ++i){
		for (int i = 0; i < dim; ++i){
			free(mat[i][j]);
		}
	}

	return(0);
}