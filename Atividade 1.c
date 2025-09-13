#include <stdio.h>
#include <string.h>


#define MAX_LIVROS 2   
#define CAMPOS 3        
#define TAMANHO_CAMPO 50

char livros[MAX_LIVROS][CAMPOS][TAMANHO_CAMPO];
int total_livros_registrados = 0;


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void registrar_novo_livro() {

    if (total_livros_registrados >= MAX_LIVROS) {
        printf("\nCatálogo cheio! Não é possível registrar mais livros.\n");
        return;
    }


    printf("Titulo: ");
    fgets(livros[total_livros_registrados][0], TAMANHO_CAMPO, stdin);

    printf("Autor: ");
    fgets(livros[total_livros_registrados][1], TAMANHO_CAMPO, stdin);

    printf("Ano: ");
    fgets(livros[total_livros_registrados][2], TAMANHO_CAMPO, stdin);


    livros[total_livros_registrados][0][strcspn(livros[total_livros_registrados][0], "\n")] = 0;
    livros[total_livros_registrados][1][strcspn(livros[total_livros_registrados][1], "\n")] = 0;
    livros[total_livros_registrados][2][strcspn(livros[total_livros_registrados][2], "\n")] = 0;
    
    printf("\nLivro registrado com sucesso.\n");


    total_livros_registrados++;
}


void listar_livros_cadastrados() {
    int i;

    printf("\nLivros cadastrados:\n");

    if (total_livros_registrados == 0) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    for (i = 0; i < total_livros_registrados; i++) {
        printf("%d) %s | %s | %s\n",
               i + 1,                 
               livros[i][0],          
               livros[i][1],          
               livros[i][2]);        
    }
}


int main() {
    int menu;


    do {
        printf("\nCatalogo Digital de Livros\n");
        printf("1. Registrar novo livro\n");
        printf("2. Listar livros cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &menu);
        limpar_buffer();

        switch (menu) {
            case 1:
                registrar_novo_livro();
                break;
            case 2:
                listar_livros_cadastrados();
                break;
            case 3:
                printf("\nEncerrando o catalogo.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (menu != 3);

    return 0;
}
