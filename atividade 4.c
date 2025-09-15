#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 2   
#define CAMPOS 2        
#define TAMANHO_CAMPO 50

void limpar_buffer() {
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void registrar_nova_pendencia(char pendencias[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO], int *total_pendencias_ptr) {
	int i;

	if ((*total_pendencias_ptr) >= MAX_ALUNOS) {
		printf("\nCatálogo cheio! Não é possível registrar mais pendencias.\n");
		return;
	}

	printf("Nome: ");
	fgets(pendencias[(*total_pendencias_ptr)][0], TAMANHO_CAMPO, stdin);

	printf("Titulo do livro: ");
	fgets(pendencias[(*total_pendencias_ptr)][1], TAMANHO_CAMPO, stdin);

	pendencias[(*total_pendencias_ptr)][0][strcspn(pendencias[(*total_pendencias_ptr)][0], "\n")] = 0;
	pendencias[(*total_pendencias_ptr)][1][strcspn(pendencias[(*total_pendencias_ptr)][1], "\n")] = 0;

	printf("\nRegistro efetuado.\n");
	(*total_pendencias_ptr)++;
}

void remover_registro(char pendencias[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO], int *total_pendencias_ptr) {
    int i, j; 
    
    char nome_removido[TAMANHO_CAMPO];
    char titulo_removido[TAMANHO_CAMPO];

    if ((*total_pendencias_ptr) == 0) {
        printf("\nFila vazia. Nao ha mais nenhuma pendencia.\n");
        return;
    }

    strcpy(nome_removido, pendencias[0][0]);
    strcpy(titulo_removido, pendencias[0][1]);

    for (i = 0; i < (*total_pendencias_ptr) - 1; i++) {
        for (j = 0; j < CAMPOS; j++) {
            strcpy(pendencias[i][j], pendencias[i + 1][j]);
        }
    }

    (*total_pendencias_ptr)--;
    printf("Chamando: %s | \"%s\"\n",nome_removido, titulo_removido);
}


void listar_pendencias(char pendencias[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO], int *total_pendencias_ptr) {
    int i;

    if ((*total_pendencias_ptr) == 0) {
        printf("Nenhuna pendencia cadastrada.\n");
        return;
    } 
	
	printf("\nPendencias:\n");
    for (i = 0; i < (*total_pendencias_ptr); i++) {
    	printf("%d) %s | \"%s\"\n", i + 1, pendencias[i][0], pendencias[i][1]);
	}
}



int main() {
    int menu;
	char pendencias[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO] = {0};
	int total_pendencias_cadastradas = 0;
	
	printf("Balcao de emprestimos\n");
	printf("1. Registrar chegada (nome, titulo do livro)\n");
	printf("2. Chamar proximo para atendimento\n");
	printf("3. Exibir pendencias de atendimento\n");
	printf("4. Sair\n");
    do {   
        printf("Escolha uma opcao: ");

        scanf("%d", &menu);
        limpar_buffer();

        switch (menu) {
            case 1:
                registrar_nova_pendencia(pendencias, &total_pendencias_cadastradas);
                break;
            case 2:
                remover_registro(pendencias, &total_pendencias_cadastradas);
                break;
            case 3:
            	listar_pendencias(pendencias, &total_pendencias_cadastradas);
            	break;
            case 4:
                printf("\nEncerrando o atendimento.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (menu != 4);

    return 0;
}
