#include <stdio.h>


void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

void moverBispo(int passosVerticais, int passosHorizontais) {
    if (passosVerticais == 0 || passosHorizontais == 0) return;

    for (int i = 0; i < 1; i++) { // movimento 
        for (int j = 0; j < 1; j++) { 
            printf("Cima Direita\n");
        }
    }

    moverBispo(passosVerticais - 1, passosHorizontais - 1);
}

//esquerda
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}


void moverCavalo() {
    printf("Movimento do Cavalo:\n");
    int movimentos = 1;

    for (int i = 0; i < movimentos; i++) {
        int subidas = 0;
        int deslocamentoFeito = 0;

        for (int j = 0; j < 3; j++) {
            if (subidas < 2) {
                printf("Cima\n");
                subidas++;
                continue;
            }

            if (!deslocamentoFeito) {
                printf("Direita\n");
                deslocamentoFeito = 1;
                break;
            }
        }
    }
}

int main() {
    printf("Movimento da Torre:\n");
    moverTorre(5);

    printf("\nMovimento do Bispo:\n");
    moverBispo(5, 5);

    printf("\nMovimento da Rainha:\n");
    moverRainha(8);

    printf("\n");
    moverCavalo();

    return 0;
}