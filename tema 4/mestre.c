#include <stdio.h>
#include <stdlib.h> 


#define TAM 10
#define TAM_HAB 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i < TAM)
            tabuleiro[linha][coluna + i] = 3;
    }
}

void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM)
            tabuleiro[linha + i][coluna] = 3;
    }
}

void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM && coluna + i < TAM)
            tabuleiro[linha + i][coluna + i] = 3;
    }
}

void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM && coluna - i >= 0)
            tabuleiro[linha + i][coluna - i] = 3;
    }
}
//revisar essa linha depois
void criarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (2 - i) && j <= (2 + i))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

//arrumar erro dps, anotar para nao esquecer
void criarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == 2 || j == 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(2 - i) + abs(2 - j) <= 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTabuleiro = origemLinha - 2 + i;
            int colunaTabuleiro = origemColuna - 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM &&
                matriz[i][j] == 1) {
                if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // agua 0 
    inicializarTabuleiro(tabuleiro);

  
    posicionarNavioHorizontal(tabuleiro, 1, 2);
    posicionarNavioVertical(tabuleiro, 3, 7);
    posicionarNavioDiagonalPrincipal(tabuleiro, 5, 1);
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 8);

    // --- habilidades
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);


    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 7, 4);
    aplicarHabilidade(tabuleiro, octaedro, 4, 6);

    // mostrando tabuleiro ..-
    exibirTabuleiro(tabuleiro);

    return 0;
}