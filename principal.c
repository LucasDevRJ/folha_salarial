#include <stdio.h>
#include <string.h>

int main() {
	char nome[50];
	char cargo[50];
	char matricula[50];

	printf("Digite o nome completo do funcionario: ");
	fgets(nome, sizeof(nome), stdin);

	nome[strcspn(nome, "\n")] = '\0';

	printf("Digite o cargo do %s: ", nome);
	fgets(cargo, sizeof(cargo), stdin);

	cargo[strcspn(cargo, "\n")] = '\0';

	printf("Digite a matricula do %s: ", nome);
	fgets(matricula, sizeof(matricula), stdin);

	printf("%s\n", nome);
	printf("%s\n", cargo);
	printf("%s\n", matricula);
}