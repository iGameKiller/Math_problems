//Nome: João Pedro Mendonça de Souza
//Matrícula: 0035330
//Curso: Ciência da Computação
//Exercício N° 9

/*Exercício 9 (derivada.c). Neste exercício deve-se escrever um programa em linguagem C que
receba como entrada a quantidade de monômios de um polinômio p(x), seus coeficientes e graus, e
que construa um novo polinômio p ′ (x) contendo a derivada do polinômio informado.
De posse do polinômio p ′ (x) o programa pergunta um valor de x para calcular o valor da derivada
no ponto x. Para isso deve-se avaliar o valor que p ′ (x) possui no valor x informado. Após calcular
e informar o resultado, o programa deverá perguntar ao usuário se deseja calcular p ′ (x) para um
7novo x; em caso positivo deverá repetir o processo questionando novo x e devolvendo ao usuário
p ′ (x). Dica: utilize a TAD definida no Exercício 8.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct monomio{
	float quociente;
	int grau;
	float resultado;
	int derivada_prim;
	int res_dev;
}Monomio;

int derivada(Monomio *ptr, int x, int num, int coef);
int derivada(Monomio *ptr, int x, int num, int coef){

	int dev;
	int op;

	for (int i = 0; i < num; i++){
		ptr[i].derivada_prim = ptr[i].quociente * ptr[i].grau;
		ptr[i].grau--;
	}

	for (int i = 0; i < num; i++){
		if(ptr[i].derivada_prim > 0){
			printf("+ %dx^%d ",ptr[i].derivada_prim,ptr[i].grau);
		}
		else if(ptr[i].derivada_prim < 0){
			printf("- %dx^%d ",ptr[i].derivada_prim,ptr[i].grau);
		}
	}

	printf("\n");

	printf("Deseja calcular um valor f'(x) ?\n");
	printf("1-Sim\t2-Não\n");
	scanf("%d",&op);

	if(op == 1){

		printf("Qual é o valor que deseja calcular ?\n");
		scanf("%d",&dev);

		for (int i = 0; i < num; i++){
			ptr[i].res_dev = ptr[i].derivada_prim * (pow(dev,ptr[i].grau));
		}

		for (int i = 0; i < num; i++){

			if(ptr[i].res_dev > 0){
				printf("+ %d ",ptr[i].res_dev);
			}
			else if(ptr[i].res_dev < 0){
				printf("- %d ",ptr[i].res_dev);
			}
			
		}
	}
	if(op == 2){
		return(0);
	}
	printf("\n");
}

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

	printf("Qual é o zero do polinômio ?\n");
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

	printf("O que deseja fazer ?\n");
	int op = 0;
	printf("1-Calcular f(x)\n");
	printf("2-Calcular derivada\n");
	printf("3-Encerrar\n");
	scanf("%d",&op);

	if(op == 1){
		printf("Qual x deseja calcular ?\n");		
		scanf("%d",&x);
		calcula(var,x,num,zero);
	}

	else if(op == 2){
		derivada(var,x,num,zero);
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
