#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#define MEDIA_HORAS_TRABALHADAS_MES 220

char nome[50], cargo[50], resposta_bonificacao;
int matricula, quantidade_horas_extras, quantidade_horas_noturnas, quantidade_vendida;
double salario_base, salario_bruto, salario_liquido, valor_hora, valor_hora_extra,
	total_hora_extra, valor_hora_noturna, total_hora_noturna, percentual_comissao,
	valor_venda, valor_total_vendas, comissao, bonificacao, percentual_bonificacao,
	percentual_inss, valor_inss, valor_total_inss, base_calculo_irrf, percentual_irrf,
	deducao_fixa, valor_irrf, valor_total_irrf, valor_gasto_vale_transporte,
	percentual_vale_transporte, desconto_vale_transporte, valor_vale_alimentacao,
	percentual_vale_alimentacao, custo_vale_alimentacao, percentual_desconto_vale_alimentacao,
	valor_plano_saude, percentual_plano_saude, custo_plano_saude, total_descontos;
int inss_calculado = 0, irrf_calculado = 0;

void solicita_dados_funcionario();
int gera_matricula();
double calcula_valor_hora_trabalhada();
double calcula_total_hora_extra();
double calcula_total_hora_noturna();
double calcula_comissao();
double calcula_custo_plano_saude();
double calcula_custo_vale_alimentacao();
double calcula_bonificacao();
double calcula_salario_bruto();
double calcula_desconto_vale_transporte();
double calcula_inss();
double calcula_irrf();
double calcula_total_descontos();
double calcula_salario_liquido();
void exibe_folha_salarial();