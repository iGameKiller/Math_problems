//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 6
#include <stdio.h>
#include <stdlib.h>

/*Exercício 6 (fibonacci.c). A sequência de Fibonacci é um padrão numérico que ocorre em muitos
seres vivos, como é o caso do Nautilus (Nautilidae), no fruto de alguns pinheiros, nas pétalas de
algumas flores, em girassóis, abacaxis, dentre outros 1 .
1
http://britton.disted.camosun.bc.ca/fibslide/jbfibslide.htm
5Foi percebida pela primeira vez no século 12 por Leonardo de Pisa, conhecido como Leonardo Fi-
bonacci. É uma sequência infinita que inicia-se com 0 e 1, que são os dois primeiros termos da
sequência. A partir destes termos, para n ≥ 2, os próximos valores podem ser calculados utilizando-
se a relação de recorrência: F n = F n−1 + F n−2 . Podemos dizer que de forma geral F n calcula o
n-ésimo termo da sequência segundo a Equação 7:


se n = 0
 0
(7)
F n = 1
se n = 1


F n−1 + F n−2 se n ≥ 2
Aplicando a fórmula dada, pode-se gerar os termos da sequência
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, . . .
Neste exercício pede-se que o aluno crie um programa capaz de exibir a sequência de Fibonacci até
o n-ésimo termo, informado pelo usuário. O programa deverá imprimir um termo da sequência por
linha.
Dica: crie uma função que calcule o valor da sequência para o k-ésimo termo informado, e chame-a
para cada termo 1 ≤ k ≤ n.*/

int main(){

	int termo = 0;
	int a = 0;
	int b = 1;
	int aux = 0;

	printf("Qual termo de fibonacci deseja calcular ?\n");
	scanf("%d",&termo);

	printf("Série de Fibonacci\n");
	printf("%d ",b);

	for (int i = 0; i < termo; i++){

		aux = a + b;
		a = b;
		b = aux;

		printf("%d ",aux);
	}

	printf("\n");
}