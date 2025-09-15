#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_PILHA 2
#define TAMANHO_CAMPO 50

void limpar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void registrar_operacao(char operacoes[TAMANHO_PILHA][TAMANHO_CAMPO], int *topo_ptr) {
	if ((*topo_ptr) >= TAMANHO_PILHA - 1) {
		printf("\nImpossivel registrar, limite ja atingido.\n");
	return;
	}
	(*topo_ptr)++;
	printf("Descricao: ");
	fgets(operacoes[(*topo_ptr)], TAMANHO_CAMPO, stdin);
	operacoes[(*topo_ptr)][strcspn(operacoes[(*topo_ptr)], "\n")] = 0;
	printf("\nOperacao registrada.\n");
}

void remover_operacao(char operacoes[TAMANHO_PILHA][TAMANHO_CAMPO], int *topo_ptr) {
	if ((*topo_ptr) == -1) {
		printf("\nPilha vazia! Nao ha nada para remover.\n");
		return;
	}
	char operacao_removida[TAMANHO_CAMPO];
	strcpy(operacao_removida, operacoes[*topo_ptr]);
	(*topo_ptr)--;
	printf("Ultima operacao desfeita: %s\n", operacao_removida);
}

void listar_operacoes(char operacoes[TAMANHO_PILHA][TAMANHO_CAMPO], int *topo_ptr) {
	int i;
	if ((*topo_ptr) == -1) {
		printf("\nA pilha esta vazia. Nao ha operacoes registradas.\n");
		return;
	}
	printf("Operacoes (ordem cronologica):\n");
	for (i = (*topo_ptr); i >= 0; i--) {
		printf("%d) %s\n", i + 1, operacoes[i]);
	}
}

int main() {
int menu;
char operacoes[TAMANHO_PILHA][TAMANHO_CAMPO] = {0};
int topo = -1; 

	printf("\nHistorico de operacoes\n");
	printf("1. Registrar nova operacao (descricao)\n");
	printf("2. Desfazer ultima operacao\n");
	printf("3. Listar operacoes registradas\n");
	printf("4. Sair\n");

do {
	printf("Escolha uma opcao: ");

	scanf("%d", &menu);
	limpar_buffer();

		switch (menu) {
			case 1:
				registrar_operacao(operacoes, &topo);
				break;
			case 2:
				remover_operacao(operacoes, &topo);
				break;
			case 3:
				listar_operacoes(operacoes, &topo);
				break;
			case 4:
				printf("\nEncerrando o historico.\n");
				break;
			default:
				printf("\nOpcao invalida. Tente novamente.\n");
		}
	}while (menu != 4);
	return 0;
}
