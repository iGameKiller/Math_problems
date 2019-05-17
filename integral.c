//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 10

/*Exercício 10 (integral.c). Neste exercício deve-se escrever um programa em linguagem C que
receba como entrada a quantidade de monômios de um polinômio p(x), seus coeficientes e graus,
e que construa um novo polinômio P (x) contendo a primitiva (ou anti-derivada) do polinômio
informado (sem considerar a constante c) tal que P ′ (x) = p(x).
De posse do polinômio P (x) o programa pergunta os limites do intervalo de integração para a in-
Z b
p(x) dx, e efetua a diferença P (a) − P (b) que representa a área sobre a curva
tegral definida
a
 
do polinômio no intervalo a, b . Para efetuar a diferença, o polinômio P (x) necessita ser avaliado
para x = a, e para x = b informados. Dica: utilize a TAD definida no Exercício 8.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct monomio{
	float quociente;
	int grau;
	float resultado;
	float integral;
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

int integral(Monomio* var, int x, int num, int coef);
int integral(Monomio* var, int x, int num, int coef){

	for (int i = 0; i < num; i++){

		var[i].grau++;

		var[i].integral = var[i].quociente/var[i].grau+1;
	}

	for (int i = 0; i < num; i++){

		if (var[i].integral > 0){
			printf("+ %.2fx^%d",var[i].integral,var[i].grau);
		}
		else if(var[i].integral < 0){
			printf("- %.2fx^%d",var[i].integral,var[i].grau);
		}
		
	}

	printf("\n");
}

int insere(int num, Monomio* var);
int insere(int num, Monomio* var){

	int grade = num;
	int zero = 0;
	int x = 0;

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

	printf("1 -Deseja calcular uma f(x) ?\n");
	printf("2 - Deseja integrar o polinômio ?\n");
	printf("3 - Deseja encerrar ?\n");
	int op = 0;
	scanf("%d",&op);

	if(op == 1){
		printf("Qual x deseja calcular ?\n");
		
		scanf("%d",&x);
		calcula(var,x,num,zero);
	}
	else if(op == 2){
		integral(var,x,num,zero);
	}
	else if(op == 3){
		return(0);
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
