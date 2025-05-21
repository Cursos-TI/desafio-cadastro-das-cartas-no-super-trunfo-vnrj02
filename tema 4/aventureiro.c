#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

   
    int linH = 0, colH = 1; 
    int linV = 4, colV = 6; 
    int linD1 = 6, colD1 = 0; 
    int linD2 = 2, colD2 = 9; 

    int i, sobreposicao;

    // horizonta
    if (colH + NAVIO <= TAM) {
        sobreposicao = 0;
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linH][colH + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < NAVIO; i++) {
                tabuleiro[linH][colH + i] = 3;
            }
        }
    }

    // vertical
    if (linV + NAVIO <= TAM) {
        sobreposicao = 0;
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linV + i][colV] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < NAVIO; i++) {
                tabuleiro[linV + i][colV] = 3;
            }
        }
    }

    // ---principal 
    if (linD1 + NAVIO <= TAM && colD1 + NAVIO <= TAM) {
        sobreposicao = 0;
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linD1 + i][colD1 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < NAVIO; i++) {
                tabuleiro[linD1 + i][colD1 + i] = 3;
            }
        }
    }

    // diagonal
    if (linD2 + NAVIO <= TAM && colD2 - NAVIO + 1 >= 0) {
        sobreposicao = 0;
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linD2 + i][colD2 - i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < NAVIO; i++) {
                tabuleiro[linD2 + i][colD2 - i] = 3;
            }
        }
    }

    //exibindo o tabuleiro 
    printf("Tabuleiro Batalha Naval:\n\n");
    for (i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}