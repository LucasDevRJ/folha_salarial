#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char nome[50];
	char cargo[50];
	int matricula;
	int media_horas_trabalhadas_mes = 220;
	int quantidade_horas_extras;
	double salario_base;
	double salario_bruto;
	double valor_hora;
	double valor_hora_extra;
	double total_hora_extra;

	printf("Digite o nome completo do funcionario: ");
	fgets(nome, sizeof(nome), stdin);

	nome[strcspn(nome, "\n")] = '\0';

	printf("Digite o cargo: ");
	fgets(cargo, sizeof(cargo), stdin);

	cargo[strcspn(cargo, "\n")] = '\0';

	printf("Digite o salario: ");
	scanf("%lf", &salario_base);

	printf("Digite a quantidade de horas extras exercidas: ");
	scanf("%d", &quantidade_horas_extras);

	int segundos = time(0);
	srand(segundos);
	int numero_aleatorio = rand();
	matricula = numero_aleatorio % 99999;

	valor_hora = salario_base / media_horas_trabalhadas_mes;
	valor_hora_extra = valor_hora + (valor_hora * 0.50);
	total_hora_extra = quantidade_horas_extras * valor_hora_extra;

	printf("--------------------|FOLHA SALARIAL|--------------------\n");
	printf("Nome: %s\n", nome);
	printf("Cargo: %s\n", cargo);
	printf("Matricula: %d\n", matricula);
	printf("Salario Base: %.2lf\n", salario_base);
	printf("Horas Extras: %.2lf\n", total_hora_extra);
	printf("--------------------------------------------------------\n");
}