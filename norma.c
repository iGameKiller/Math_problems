//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 3

/*Exercício 3 (norma.c). Seja um vetor v que pertence ao espaço R n . A norma de um vetor (também
chamada de módulo do vetor) é o comprimento deste vetor, calculado pela distância de seu ponto
final até a origem. De maneira geral, a norma do vetor mede o tamanho do segmento de reta das
coordenadas do vetor v até a origem do sistemas de coordenadas.
A norma de um vetor com n dimensões pode ser generalizada a partir do Teorema de Pitágoras na
fórmula dada na Equação 3, que extrai essa medida a partir da raíz quadrada da soma do quadrado
das n componentes do vetor v:
q
(3)
kvk = v 1 2 + v 2 2 + · · · + v n 2
Neste exercício pede-se que o aluno construa um programa que recebe as coordenadas de um vetor
v ∈ R 3 , obtenha suas componentes via console, e calcule a norma do vetor correspondente exibindo
o resultado no terminal.*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float norma(int x, int y, int z);
float norma(int x, int y, int z){
	
	x = x*x;
	y = y*y;
	z = z*z;

	int soma;

	soma = x + y + z;

	float res;

	res = sqrt(soma);

	return(res);
}


int main(int argc, char** argv){

	int a, b, c;

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);

	float res;

	res = norma(a,b,c);

	printf("A norma do vetor cujas coordenadas são %d, %d e %d é %f\n", a, b, c, res); 
}