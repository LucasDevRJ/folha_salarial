#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char nome[50];
	char cargo[50];
	int matricula;
	double salario_base;
	double salario_bruto;
	double valor_hora;
	int media_horas_trabalhadas_mes = 220;
	int quantidade_horas_extras;
	double valor_hora_extra;
	double total_hora_extra;
	int quantidade_horas_noturnas;
	double valor_hora_noturna;
	double total_hora_noturna;

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

	printf("Digite a quantidade de horas noturnas exercidas: ");
	scanf("%d", &quantidade_horas_noturnas);

	//Lógica para gerar números aleatorios para a matrícula do funcionário
	int segundos = time(0);
	srand(segundos);
	int numero_aleatorio = rand();
	matricula = numero_aleatorio % 99999;

	valor_hora = salario_base / media_horas_trabalhadas_mes;

	valor_hora_extra = valor_hora + (valor_hora * 0.50);
	total_hora_extra = quantidade_horas_extras * valor_hora_extra;

	valor_hora_noturna = valor_hora + (valor_hora * 0.20);
	total_hora_noturna = quantidade_horas_noturnas * valor_hora_noturna;

	salario_bruto = salario_base + total_hora_extra + total_hora_noturna;

	printf("--------------------|FOLHA SALARIAL|--------------------\n");
	printf("Nome: %s\n", nome);
	printf("Cargo: %s\n", cargo);
	printf("Matricula: %d\n", matricula);
	printf("Salario Base: R$ %.2lf\n", salario_base);
	printf("Horas Extras: R$ %.2lf\n", total_hora_extra);
	printf("Horas Noturnas: R$ %.2lf\n", total_hora_noturna);
	printf("Salario Bruto: R$ %.2lf\n", salario_bruto);
	printf("--------------------------------------------------------\n");
}