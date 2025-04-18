#include <stdio.h>

int main() {
    // d1
    char estado1[] = "RJ";
    char nome1[] = "CAMPO GRANDE";
    int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 700000.0;
    int pontos1 = 15;

    float densidade1 = populacao1 / area1;
    float pib_per_capita1 = pib1 / populacao1;
//salvando dados das cartas
    char estado2[] = "RJ";
    char nome2[] = "Rio de Janeiro";
    int populacao2 = 6718903;
    float area2 = 1182.30;
    float pib2 = 413000.0;
    int pontos2 = 12;

    float densidade2 = populacao2 / area2;
    float pib_per_capita2 = pib2 / populacao2;

  //resultado
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d habitantes | Pontos turísticos: %d\n", nome1, estado1, populacao1, pontos1);
    printf("Carta 2 - %s (%s): %d habitantes | Pontos turísticos: %d\n", nome2, estado2, populacao2, pontos2);


    if (populacao1 > populacao2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}