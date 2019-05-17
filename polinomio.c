//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 8

/*Exercício 8 (polinomio.c). Escreva um programa em linguagem C que seja capaz de representar
uma TAD de um monômio, com coeficiente e grau do monômio. Considere que uma listagem de
monômios é um polinômio (por exemplo, p(x) = 2x 3 + 0.5x 2 − 3x + 2 é um polinômio formado pelos
monômios 2x 3 , 0.5x 2 , 3x 1 , 2x 0 ).
Uma sugestão de representação é usar uma struct para representar o monômio, e um vetor de
monômios para representar o polinômio além de outras variáveis de controle, como por exemplo, o
total de monômios do polinômio.
De posse da representação o programa deverá perguntar ao usuário quantos monômios deve-se usar,
e perguntar qual o coeficiente e grau de cada um. Em seguida o programa deverá perguntar ao
usuário se deseja avaliar o polinômio em questão (isto é, para um dado valor de x informado pelo
usuário, calcular o valor de p(x) correspondente). Após avaliar o programa deverá perguntar se
deseja avaliar outro valor de x, ou encerrar a execução do mesmo.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct monomio{
	float quociente;
	int grau;
	float resultado;
}Monomio;

void calcula(Monomio* var, int x, int num, int coef);
void calcula(Monomio* var, int x, int num, int coef){

	for (int i = 0; i < num; i++){
		var[i].resultado = var[i].quociente * (pow(x,var[i].grau));
	}

	for (int i = 0; i < num; i++){
		printf("%.1f ",var[i].resultado);
	}

	if(coef > 0){
		printf("+ %d",coef);
	}
	else{
		printf("%d",coef);
	}

	printf("\n");

}

void insere(int num, Monomio* var);
void insere(int num, Monomio* var){

	int grade = num;
	int zero = 0;

	for (int i = 0; i < num; i++){

		printf("Qual é o %d° quociente ?",i+1);
		scanf("%f",&var[i].quociente);

		var[i].grau = grade;
		grade--;
	}

	printf("Qual é o coeficiente angular do polinômio ?\n");
	scanf("%d",&zero);

	for (int i = 0; i < num; i++){
		printf("%.0fx^%d ",var[i].quociente,var[i].grau);
	}

	if(zero > 0){
		printf("+ %d\n",zero);
	}
	else{
		printf("%d\n",zero);
	}
	printf("\n");

	printf("Deseja calcula uma f(x) ?\n");
	int op = 0;
	printf("1-Sim\t2-Não\t");
	scanf("%d",&op);

	if(op == 1){
		printf("Qual x deseja calcular ?\n");
		int x = 0;
		scanf("%d",&x);
		calcula(var,x,num,zero);
	}
	if(op == 2){
		exit(0);
	}
}

void main(){

	int num = 0;
	int fun = 0;
	Monomio* vet;

	printf("Quantos monomios seu polinômio tem ?\n");
	scanf("%d",&num);

	vet = malloc(num * sizeof(Monomio));

	insere(num,vet);

	free(vet);

}
