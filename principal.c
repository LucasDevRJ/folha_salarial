#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char nome[50];
	char cargo[50];
	int matricula;
	double salario;
	int horas_extras;

	printf("Digite o nome completo do funcionario: ");
	fgets(nome, sizeof(nome), stdin);

	nome[strcspn(nome, "\n")] = '\0';

	printf("Digite o cargo: ");
	fgets(cargo, sizeof(cargo), stdin);

	cargo[strcspn(cargo, "\n")] = '\0';

	printf("Digite o salario: ");
	scanf("%d", &salario);

	printf("Digite a quantidade de horas extras exercidas: ");
	scanf("%d", &horas_extras);

	int segundos = time(0);
	srand(segundos);
	int numero_aleatorio = rand();
	matricula = numero_aleatorio % 99999;

	printf("----------|FOLHA SALARIAL|----------\n");
	printf("Nome: %s\n", nome);
	printf("Cargo: %s\n", cargo);
	printf("Matricula: %d\n", matricula);
	printf("Salario: %d\n", salario);
	printf("Horas extras: %d\n", horas_extras);
	printf("-----------------------------------\n");
}