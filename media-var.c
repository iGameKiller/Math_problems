//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 11

/*Exercício 11 (media-var.c). Neste exercício o programador deverá construir um programa em
linguagem C que recebe uma lista de números reais de tamanho variado, informado pelo usuário,
que representam valores observados de algum fenômeno. Na notação matemática a seguir n indica
o número de observações tomadas, enquanto que x i indica o valor da i-ésima observação.
Após receber estes dados o programa deverá calcular a média amostral, cujo cálculo é dado pela
Equação 10:
n
x 1 + x 2 + · · · + x n
1 X
x =
=
x i
n
n
(10)
i=1
De posse da média, o programa deverá calcular também a variância amostral, cujo cômputo é feito
mediante aplicação da Equação 11:
s 2 =
n
X
x i − x
i=1
 2
n − 1
Por fim, média e variância amostrais são apresentadas como resultado no console.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void variancia(int *vet, int tam, float media);
void variancia(int *vet, int tam, float media){

	int sub;
	int potencia;
	int soma;
	float divisao;

	for (int i = 0; i < tam; i++){
		sub = vet[i] - media;
		potencia = (sub,2);
		soma = soma + potencia;
	}

	divisao = soma/tam;

	divisao = pow(divisao,2);

	printf("A Variância Amostral é de %f\n",divisao);
}

void media(int* vet, int tam);
void media(int* vet, int tam){

	float media;

	for (int i = 0; i < tam; i++){
		media += vet[i];
	}

	media = media/tam;

	printf("A media é de %f\n",media);

	variancia(vet, tam, media);
}

void main(){

	int tam;
	int *vet;

	printf("Qual é o tamanho da lista ?\n");
	scanf("%d",&tam);

	vet = malloc(tam * sizeof(int));

	printf("\n");

	for (int i = 0; i < tam; i++){
		printf("Insira o %d° número",i+1);
		scanf("%d",&vet[i]);	
		printf("\n");
	}

	media(vet,tam);
	free(vet);
	printf("\n");
}
