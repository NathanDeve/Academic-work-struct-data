#include <stdio.h>

#define estacao 6
#define fileira 6




void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void visualizar_mapa(int mapa[fileira][estacao]) {
	int i, j;
    printf("Mapa (L = livre, X = reservado): \n");
    for (i = 1; i < fileira; i++) {
    
        for (j = 1; j < estacao; j++) {
            if (mapa[i][j] == 0) {
                printf("L ");
            }else{
            	printf("X ");
			}
        }
        printf("\n");
    }
    printf("\n");
}

void Inserir_posicao(int mapa[fileira][estacao]){
	
	int i, j;
	int fileira_desejada;
	int estacao_desejada;

	printf("Informe a fileira(1-5): ");
	scanf("%d", &fileira_desejada);
	limpar_buffer();
	printf("Informe a estacao(1-5): ");
	scanf("%d", &estacao_desejada);
	limpar_buffer();
	
	if(fileira_desejada <= 0 || fileira_desejada >= fileira ||
	estacao_desejada <= 0 || estacao_desejada >= estacao){
		
		printf("\nERRO: Posicao invalida! Fora dos limites do mapa.\n");
        return;
	}
	
	if (mapa[fileira_desejada][estacao_desejada] == 0) {
        
        mapa[fileira_desejada][estacao_desejada] = 1;
        printf("\nReserva efetuada com sucesso.\n");
        
    } else {
        printf("\nPosicao ja reservada. Escolhe outra.\n");
    }
}


int main(){
	 int mapa[fileira][estacao] = {0};
	int menu = 1;
	printf("Reservas | Sala de Estudos \n1. Visualizar mapa de estacoes \n2. Reservar posicao (fileira, estacao)\n3. Sair");
	do{
		printf("\nEscolha uma opcao: ");
		scanf("%d", &menu);
		limpar_buffer();
		
		switch(menu){
			
			case 1:
			visualizar_mapa(mapa);
			break;
			case 2:
			Inserir_posicao(mapa);
			break;
			case 3:
			printf("Encerrrando reservas.");
			break;
		}
	}while(menu != 3);
	
	return 0;
}


