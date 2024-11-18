#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
	double percentual_comissao;
	int quantidade_vendida;
	double valor_venda;
	double valor_total_vendas;
	double comissao;
	double bonificacao;
	double percentual_inss;
	double valor_inss;
	double valor_total_inss;

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

	printf("Digite o percentual de comissao: ");
	scanf("%lf", &percentual_comissao);

	printf("Digite a quantidade vendida: ");
	scanf("%d", &quantidade_vendida);

	for (int i = 0; i < quantidade_vendida; i++) {
		printf("Digite o valor da %d venda: ", i + 1);
		scanf("%lf", &valor_venda);
		valor_total_vendas += valor_venda;
	}
	
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

	percentual_comissao = percentual_comissao / 100;

	comissao = valor_total_vendas * percentual_comissao;

	bonificacao = salario_base * 0.10;

	salario_bruto = salario_base + total_hora_extra + total_hora_noturna + comissao + bonificacao;

	if (salario_bruto <= 1320.00 || salario_bruto > 1320.00) {
		percentual_inss = 7.5 / 100;
		valor_inss = 1320.00 * percentual_inss;
		printf("%.2lf\n", valor_inss); 
		valor_total_inss += valor_inss;
	} 

	if (salario_bruto >= 1320.01 || salario_bruto <= 2571.29) {
		percentual_inss = 9.0 / 100;
		valor_inss = fabs((1320.01 - 2571.29)) * percentual_inss; 
		printf("%.2lf\n", valor_inss); 
		valor_total_inss += valor_inss;
	}

	if (salario_bruto >= 2571.30 || salario_bruto <= 3856.94) {
		percentual_inss = 12.0 / 100;
		valor_inss = fabs((2571.30 - 3856.94)) * percentual_inss; 
		printf("%.2lf\n", valor_inss); 
		valor_total_inss += valor_inss;
	} 

	if (salario_bruto >= 3856.95 || salario_bruto <= 5000.00) {
		percentual_inss = 14.0 / 100;
		valor_inss = fabs((3856.95 - 5000.00)) * percentual_inss; 
		printf("%.2lf\n", valor_inss); 
		valor_total_inss += valor_inss;
	}

	printf("--------------------|FOLHA SALARIAL|--------------------\n");
	printf("Nome: %s\n", nome);
	printf("Cargo: %s\n", cargo);
	printf("Matricula: %d\n", matricula);
	printf("Salario Base: R$ %.2lf\n", salario_base);
	printf("Horas Extras: R$ %.2lf\n", total_hora_extra);
	printf("Horas Noturnas: R$ %.2lf\n", total_hora_noturna);
	printf("Comissao: R$ %.2lf\n", comissao);
	printf("Bonificacao: R$ %.2lf\n", bonificacao);
	printf("INSS: R$ %.2lf\n", valor_total_inss);
	printf("Salario Bruto: R$ %.2lf\n", salario_bruto);
	printf("--------------------------------------------------------\n");
}