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

void registrar_novo_aluno(char alunos[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO], int *total_alunos_ptr) {
	int ehTudoNumero = 1;
	int i;

	if ((*total_alunos_ptr) >= MAX_ALUNOS) {
		printf("\nCatálogo cheio! Não é possível registrar mais alunos.\n");
		return;
	}

	printf("Nome: ");
	fgets(alunos[(*total_alunos_ptr)][0], TAMANHO_CAMPO, stdin);

	printf("Matricula (apenas numeros): ");
	fgets(alunos[(*total_alunos_ptr)][1], TAMANHO_CAMPO, stdin);

	alunos[(*total_alunos_ptr)][0][strcspn(alunos[(*total_alunos_ptr)][0], "\n")] = 0;
	alunos[(*total_alunos_ptr)][1][strcspn(alunos[(*total_alunos_ptr)][1], "\n")] = 0;

	if (strlen(alunos[(*total_alunos_ptr)][1]) == 0) {
		ehTudoNumero = 0;
	}

	for (i = 0; alunos[(*total_alunos_ptr)][1][i] != '\0'; i++) {
		if (!isdigit(alunos[(*total_alunos_ptr)][1][i])) {
			ehTudoNumero = 0;
			break;
		}
	}

	if (ehTudoNumero == 0) {
		printf("\nERRO: Matricula invalida. Use apenas numeros e nao deixe o campo vazio.\n");
		printf("Cadastro cancelado.\n");
		return;
	}

	printf("\nUsuario inserido com sucesso.\n");
	(*total_alunos_ptr)++;
}

void listar_alunos_cadastrados(char alunos[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO], int *total_alunos_ptr) {
    int i;

    printf("\nAlunos cadastrados:\n");

    if ((*total_alunos_ptr) == 0) {
        printf("Nenhum aluno cadastrado ainda.\n");
        return;
    }

    for (i = 0; i < (*total_alunos_ptr); i++) {
        printf("- %s (%s)\n",                 
               alunos[i][0],          
               alunos[i][1]);        
    }
}

void remover_alunos_cadastrados(char alunos[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO], int *total_alunos_ptr) {
    
    char matricula_digitada[TAMANHO_CAMPO]; 
    int indice_encontrado = -1; 
    int i, j; 
    int ehTudoNumero = 1;

    if ((*total_alunos_ptr) == 0) {
        printf("Nenhum aluno cadastrado ainda.\n");
        return;
    }

    printf("\nInforme a matricula: ");
    fgets(matricula_digitada, TAMANHO_CAMPO, stdin);
    matricula_digitada[strcspn(matricula_digitada, "\n")] = 0; 
	
	if (strlen(matricula_digitada) == 0) {
		ehTudoNumero = 0;
	}

	for (i = 0; matricula_digitada[i] != '\0'; i++) {
		if (!isdigit(matricula_digitada[i])) {
			ehTudoNumero = 0;
			break;
		}
	}

	if (ehTudoNumero == 0) {
		printf("\nERRO: Matricula invalida. Use apenas numeros e nao deixe o campo vazio.\n");
		printf("Remocao cancelada.\n");
		return;
	}

    for (i = 0; i < (*total_alunos_ptr); i++) {
        
        if (strcmp(matricula_digitada, alunos[i][1]) == 0) {
            indice_encontrado = i; 
            break; 
        }
    }

    if (indice_encontrado != -1) {
        for (i = indice_encontrado; i < (*total_alunos_ptr) - 1; i++) {
            for (j = 0; j < CAMPOS; j++) {
                strcpy(alunos[i][j], alunos[i + 1][j]);
            }
        }
        (*total_alunos_ptr)--;
        
        printf("Usuario removido com sucesso.\n");

    } else {
        printf("Erro: Matricula nao encontrada.\n");
    }
}


int main() {
    int menu;
	char alunos[MAX_ALUNOS][CAMPOS][TAMANHO_CAMPO] = {0};
	int total_alunos_matriculados = 0;
	
	printf("Cadastro de Usuarios\n");
	printf("1. Inserir usuario (nome, matricula)\n");
	printf("2. Exibir usuarios cadastrados\n");
	printf("3. Remover usuario pela matricula\n");
	printf("4. Sair\n");
    do {   
        printf("Escolha uma opcao: ");

        scanf("%d", &menu);
        limpar_buffer();

        switch (menu) {
            case 1:
                registrar_novo_aluno(alunos, &total_alunos_matriculados);
                break;
            case 2:
                listar_alunos_cadastrados(alunos, &total_alunos_matriculados);
                break;
            case 3:
            	remover_alunos_cadastrados(alunos, &total_alunos_matriculados);
            	break;
            case 4:
                printf("\nEncerrando cadastro.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (menu != 4);

    return 0;
}
