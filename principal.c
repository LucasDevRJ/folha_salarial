#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main() {
	char nome[50];
	char cargo[50];
	int matricula;
	double salario_base;
	double salario_bruto;
	double salario_liquido;
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
	char resposta_bonificacao;
	double bonificacao;
	double percentual_bonificacao;
	double percentual_inss;
	double valor_inss;
	double valor_total_inss;
	double base_calculo_irrf;
	double percentual_irrf;
	double deducao_fixa;
	double valor_irrf;
	double valor_total_irrf;
	double valor_gasto_vale_transporte;
	double percentual_vale_transporte;
	double desconto_vale_transporte;
	double valor_vale_alimentacao;
	double percentual_vale_alimentacao;
	double custo_vale_alimentacao;
	double percentual_desconto_vale_alimentacao;
	double valor_plano_saude;
	double percentual_plano_saude;
	double custo_plano_saude;
	double total_descontos;

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

	printf("Digite a quantidade vendida: ");
	scanf("%d", &quantidade_vendida);

	if (quantidade_vendida > 0) {
		printf("Digite o valor unitario de cada venda: ");
		scanf("%lf", &valor_venda);

		printf("Digite o percentual de comissao: ");
		scanf("%lf", &percentual_comissao);
	}

	printf("S - Sim\n");
	printf("Qualquer tecla - Nao\n");
	printf("Cumpriu metas?\n");
	printf("Digite S ou Qualquer tecla: ");
	scanf("%s", &resposta_bonificacao);

	resposta_bonificacao = toupper(resposta_bonificacao);

	if (resposta_bonificacao == 'S') {
		printf("Digite o percentual da bonificacao: ");
		scanf("%lf", &percentual_comissao);
		bonificacao = salario_base * (percentual_bonificacao / 100.0);
	}

	printf("Digite o custo mensal com o vale transporte: R$ ");
	scanf("%lf", &valor_gasto_vale_transporte);

	printf("Digite o valor do vale-alimentacao: R$ ");
	scanf("%lf", &valor_vale_alimentacao);

	if (valor_vale_alimentacao > 0) {
		printf("Digite o percentual do vale-alimentacao pago pela empresa: ");
		scanf("%lf", &percentual_vale_alimentacao);
	}

	printf("Digite o valor do plano de saude: R$ ");
	scanf("%lf", &valor_plano_saude);

	if (valor_plano_saude > 0) {
		printf("Digite o percentual do plano de saude pago pela empresa: ");
		scanf("%lf", &percentual_plano_saude);
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

	valor_total_vendas = valor_venda * quantidade_vendida;
	comissao = valor_total_vendas * percentual_comissao;

	custo_plano_saude = valor_plano_saude - (valor_plano_saude * (percentual_plano_saude / 100.00));

	custo_vale_alimentacao = valor_vale_alimentacao - (valor_vale_alimentacao * (percentual_vale_alimentacao / 100.00));
	
	salario_bruto = salario_base + total_hora_extra + total_hora_noturna + comissao + bonificacao;

	if (salario_bruto <= 1320.00 || salario_bruto > 1320.00) {
		percentual_inss = 7.5 / 100;
		double maior_valor = salario_bruto < 1320.00 ? salario_bruto : 1320.00;
		valor_inss = maior_valor * percentual_inss; 
		//printf("Percentual INSS: %lf\n", percentual_inss);
		printf("INSS Faixa 1 R$ %.2lf\n", valor_inss);
		valor_total_inss += valor_inss;
	} 

	if (salario_bruto >= 1320.01) {
		percentual_inss = 9.0 / 100;
		//printf("Percentual INSS: %lf\n", percentual_inss);
		double maior_valor = salario_bruto < 2571.29 ? salario_bruto : 2571.29;
		valor_inss = fabs((1320.01 - maior_valor)) * percentual_inss; 
		//valor_inss = round(valor_inss * 100) / 100;
		//valor_inss = floor(valor_inss * casas_decimais) / casas_decimais;
		printf("INSS Faixa 2 R$ %.2lf\n", valor_inss);
		valor_total_inss += valor_inss;
	}

	if (salario_bruto >= 2571.30) {
		percentual_inss = 12.0 / 100;
		//printf("Percentual INSS: %lf\n", percentual_inss);
		double maior_valor = salario_bruto < 3856.94 ? salario_bruto : 3856.94;
		valor_inss = fabs((2571.29 - maior_valor)) * percentual_inss; 
		//valor_inss = floor(valor_inss * casas_decimais) / casas_decimais;
		printf("INSS Faixa 3 R$ %.2lf\n", valor_inss);
		valor_total_inss += valor_inss;
	} 

	if (salario_bruto >= 3856.95) {
		percentual_inss = 14.0 / 100;
		//printf("Percentual INSS: %lf\n", percentual_inss);
		double maior_valor = salario_bruto < 4257.57 ? salario_bruto : 4257.57;
		valor_inss = fabs((3856.95 - maior_valor)) * percentual_inss; 
		//valor_inss = floor(valor_inss * casas_decimais) / casas_decimais;
		printf("INSS Faixa 4 R$ %.2lf\n", valor_inss);
		valor_total_inss += valor_inss;
	}

	//valor_total_inss = round(valor)

	base_calculo_irrf = salario_bruto - valor_total_inss;
	printf("Base de calculo IRRF: R$ %.2lf\n", base_calculo_irrf);

	if (base_calculo_irrf <= 2112.00) {
		percentual_irrf = 0.0;
		deducao_fixa = 0.0;
	}

	if (base_calculo_irrf >= 2112.01) {
		percentual_irrf = 7.5 / 100;
		double maior_valor = base_calculo_irrf < 2826.65 ? base_calculo_irrf : 2826.65;
		valor_irrf = fabs((2112.01 - maior_valor)) * percentual_irrf; 
		if (maior_valor < base_calculo_irrf) {
			deducao_fixa = 142.80;
		}
		printf("IRRF Faixa 2 R$ %.2lf\n", valor_irrf);
		valor_total_irrf += valor_irrf;
		printf("Valor total IRRF: %.2lf\n", valor_total_irrf);
	}

	if (base_calculo_irrf >= 2826.66) {
		percentual_irrf = 15.0 / 100;
		double maior_valor = base_calculo_irrf < 3751.05 ? base_calculo_irrf : 3751.05;
		valor_irrf = fabs((2826.66 - maior_valor)) * percentual_irrf; 
		if (maior_valor < base_calculo_irrf) {
			deducao_fixa = 354.80;
		}
		printf("IRRF Faixa 3 R$ %.2lf\n", valor_irrf);
		valor_total_irrf += valor_irrf;
		printf("Valor total IRRF: %.2lf\n", valor_total_irrf);

	}

	if (base_calculo_irrf >= 3751.06) {
		percentual_irrf = 22.5 / 100;
		double maior_valor = base_calculo_irrf < 4664.68 ? base_calculo_irrf : 4664.68;
		valor_irrf = fabs((3751.06 - maior_valor)) * percentual_irrf; 
		if (maior_valor < base_calculo_irrf) {
			deducao_fixa = 636.13;
		}
		printf("IRRF Faixa 4 R$ %.2lf\n", valor_irrf);
		valor_total_irrf += valor_irrf;
		printf("Valor total IRRF: %.2lf\n", valor_total_irrf);
	}

	if (base_calculo_irrf > 4664.68) {
		percentual_irrf = 27.5 / 100;
		double maior_valor = base_calculo_irrf > 4664.68 ? base_calculo_irrf : 4664.68;
		valor_irrf = fabs((4664.68 - maior_valor)) * percentual_irrf; 
		printf("IRRF Faixa 5 R$ %.2lf\n", valor_irrf);
		valor_total_irrf += valor_irrf;
		printf("VALOR TOTAL IRRF: %.2lf \n", valor_total_irrf);
		deducao_fixa = 869.36;
		printf("Valor total IRRF: %.2lf\n", valor_total_irrf);
	}

	//valor_total_irrf -= deducao_fixa;


	percentual_vale_transporte = salario_bruto * 0.06;
	if (valor_gasto_vale_transporte > percentual_vale_transporte) {
		desconto_vale_transporte = percentual_vale_transporte;
		printf("Desconto do VT: %.2lf\n", desconto_vale_transporte);
	} else if (valor_gasto_vale_transporte < percentual_vale_transporte) {
		desconto_vale_transporte = valor_gasto_vale_transporte;
	}

	//percentual_desconto_vale_alimentacao = valor_vale_alimentacao * 0.10;

	total_descontos = valor_total_inss + valor_total_irrf + desconto_vale_transporte 
	+ custo_vale_alimentacao + custo_plano_saude;

	salario_liquido = salario_bruto - total_descontos;

	printf("--------------------|FOLHA SALARIAL|--------------------\n");
	printf("Nome: %s\n", nome);
	printf("Cargo: %s\n", cargo);
	printf("Matricula: %d\n", matricula);
	printf("Salario Base: R$ %.2lf\n", salario_base);
	printf("Horas Extras: R$ %.2lf\n", total_hora_extra);
	printf("Horas Noturnas: R$ %.2lf\n", total_hora_noturna);
	printf("Comissao: R$ %.2lf\n", comissao);
	printf("Bonificacao: R$ %.2lf\n", bonificacao);
	printf("Salario Bruto: R$ %.2lf\n", salario_bruto);
	printf("-------------------------\n");
	printf("INSS: R$ %.2lf\n", valor_total_inss);
	if (valor_total_irrf > 0) {
		printf("IRRF: R$ %.2lf\n", valor_total_irrf);
	} else {
		printf("IRRF: isento\n");
	}
	printf("Vale Transporte: R$ %.2lf\n", desconto_vale_transporte);
	printf("Vale-alimentacao: R$ %.2lf\n", custo_vale_alimentacao);
	printf("Plano de Saude: R$ %.2lf\n", custo_plano_saude);
	printf("Total de Descontos: R$ %.2lf\n", total_descontos);
	printf("-------------------------\n");
	printf("Salario Liquido: R$ %.2lf\n", salario_liquido);
	printf("--------------------------------------------------------\n");
}