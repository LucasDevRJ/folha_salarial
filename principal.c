#include "principal.h"

void solicita_dados_funcionario() {
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
		scanf("%lf", &percentual_bonificacao);
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
}

int gera_matricula() {
	int segundos = time(0);
	srand(segundos);
	int numero_aleatorio = rand();
	matricula = numero_aleatorio % 99999;
	return matricula;
}

double calcula_valor_hora_trabalhada() {
	valor_hora = salario_base / MEDIA_HORAS_TRABALHADAS_MES;
	return valor_hora;
}

double calcula_total_hora_extra() {
	valor_hora_extra = calcula_valor_hora_trabalhada() + (calcula_valor_hora_trabalhada() * 0.50);
	total_hora_extra = quantidade_horas_extras * valor_hora_extra;
	return total_hora_extra;
}

double calcula_total_hora_noturna() {
	valor_hora_noturna = calcula_valor_hora_trabalhada() + (calcula_valor_hora_trabalhada() * 0.20);
	total_hora_noturna = quantidade_horas_noturnas * valor_hora_noturna;
	return total_hora_noturna;
}

double calcula_comissao() {
	valor_total_vendas = valor_venda * quantidade_vendida;
	comissao = valor_total_vendas * (percentual_comissao / 100.0);
	return comissao;
}

double calcula_custo_plano_saude() {
	custo_plano_saude = valor_plano_saude - 
	(valor_plano_saude * (percentual_plano_saude / 100.00));
	return custo_plano_saude;
}

double calcula_custo_vale_alimentacao() {
	custo_vale_alimentacao = valor_vale_alimentacao 
	- (valor_vale_alimentacao * (percentual_vale_alimentacao / 100.00));
	return custo_vale_alimentacao;
}

double calcula_bonificacao() {
	bonificacao = salario_base * (percentual_bonificacao / 100.0);
	return bonificacao;	
}

double calcula_salario_bruto() {
	salario_bruto = salario_base + calcula_total_hora_extra() + calcula_total_hora_noturna() 
	+ calcula_comissao() + calcula_bonificacao();
	return salario_bruto;
}

double calcula_desconto_vale_transporte() {
	percentual_vale_transporte = salario_bruto * 0.06;
	if (valor_gasto_vale_transporte > percentual_vale_transporte) {
		desconto_vale_transporte = percentual_vale_transporte;
	} else if (valor_gasto_vale_transporte < percentual_vale_transporte) {
		desconto_vale_transporte = valor_gasto_vale_transporte;
	}
	return desconto_vale_transporte;
}

double calcula_inss() {
	if (inss_calculado == 0) {

		if (calcula_salario_bruto() <= 1518.00 || calcula_salario_bruto() > 1518.00) {
			percentual_inss = 7.5 / 100;
			double maior_valor = calcula_salario_bruto() < 1518.00 ? calcula_salario_bruto() : 1518.00;
			valor_inss = maior_valor * percentual_inss; 
			valor_total_inss += valor_inss;
		} 

		if (calcula_salario_bruto() >= 1518.01) {
			percentual_inss = 9.0 / 100;
			double maior_valor = calcula_salario_bruto() < 2793.88 ? calcula_salario_bruto() : 2793.88;
			valor_inss = fabs((1518.01 - maior_valor)) * percentual_inss; 
			valor_total_inss += valor_inss;
		}

		if (calcula_salario_bruto() >= 2793.89) {
			percentual_inss = 12.0 / 100;
			double maior_valor = calcula_salario_bruto() < 4190.83 ? calcula_salario_bruto() : 4190.83;
			valor_inss = fabs((2793.89 - maior_valor)) * percentual_inss; 
			valor_total_inss += valor_inss;
		} 

		if (calcula_salario_bruto() >= 4190.84) {
			percentual_inss = 14.0 / 100;
			double maior_valor = calcula_salario_bruto() < 8157.41 ? calcula_salario_bruto() : 8157.41;
			valor_inss = fabs((4190.84 - maior_valor)) * percentual_inss;
			valor_total_inss += valor_inss;
		}

		if (calcula_salario_bruto() >= 8157.41)	{
			valor_total_inss = 951.63;
		}

		inss_calculado = 1;
		return valor_total_inss;
	}
	return valor_total_inss;
}

double calcula_irrf() {

	if (irrf_calculado == 0) {
		base_calculo_irrf = calcula_salario_bruto() - calcula_inss();
		
		if (base_calculo_irrf <= 2259.20) {
			percentual_irrf = 0.0;
			deducao_fixa = 0.0;

		} else if (base_calculo_irrf >= 2259.21 && base_calculo_irrf <= 2828.65) {
			percentual_irrf = 7.5 / 100;
			deducao_fixa = 169.44;

		} else if (base_calculo_irrf >= 2828.66 && base_calculo_irrf <= 3751.05) {
			percentual_irrf = 15.0 / 100;
			deducao_fixa = 381.44;

		} else if (base_calculo_irrf >= 3751.06 && base_calculo_irrf <= 4664.68) {
			percentual_irrf = 22.5 / 100;
			deducao_fixa = 662.77;

		} else {
			percentual_irrf = 27.5 / 100;
			deducao_fixa = 896.00;
		}

		valor_irrf = (base_calculo_irrf * percentual_irrf) - deducao_fixa;

		return valor_irrf;
	}

	return valor_irrf;
}

double calcula_total_descontos() {
	total_descontos = calcula_inss() + calcula_irrf() + calcula_desconto_vale_transporte() 
	+ calcula_custo_vale_alimentacao() + calcula_custo_plano_saude();
	return total_descontos;
}

double calcula_salario_liquido() {
	salario_liquido = calcula_salario_bruto() - calcula_total_descontos();
	return salario_liquido;
}

void exibe_folha_salarial() {
	printf("--------------------|FOLHA SALARIAL|--------------------\n");
	printf("Nome: %s\n", nome);
	printf("Cargo: %s\n", cargo);
	printf("Matricula: %d\n", gera_matricula());
	printf("Salario Base: R$ %.2lf\n", salario_base);
	printf("Horas Extras: R$ %.2lf\n", calcula_total_hora_extra());
	printf("Horas Noturnas: R$ %.2lf\n", calcula_total_hora_noturna());
	printf("Comissao: R$ %.2lf\n", calcula_comissao());
	printf("Bonificacao: R$ %.2lf\n", calcula_bonificacao());
	printf("Salario Bruto: R$ %.2lf\n", calcula_salario_bruto());
	printf("-------------------------\n");
	printf("INSS: R$ %.2lf\n", calcula_inss());
	printf("IRRF: R$ %.2lf\n", calcula_irrf());
	printf("Vale Transporte: R$ %.2lf\n", calcula_desconto_vale_transporte());
	printf("Vale-alimentacao: R$ %.2lf\n", calcula_custo_vale_alimentacao());
	printf("Plano de Saude: R$ %.2lf\n", calcula_custo_plano_saude());
	printf("Total de Descontos: R$ %.2lf\n", calcula_total_descontos());
	printf("-------------------------\n");
	printf("Salario Liquido: R$ %.2lf\n", calcula_salario_liquido());
	printf("--------------------------------------------------------\n");
}

int main() {
	solicita_dados_funcionario();
	exibe_folha_salarial();
}