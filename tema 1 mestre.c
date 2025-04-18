#include <stdio.h>

typedef struct {
    char nome[50];
    char estado[50];
    int codigo;
    unsigned long int populacao;
    float area;
    unsigned long int pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcular_atributos(Carta *carta) {
    // Calcular a densidade populacional
    carta->densidade_populacional = carta->populacao / carta->area;

    // Calcular o PIB per capita
    if (carta->populacao > 0) {
        carta->pib_per_capita = (float)carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }

    // Calcular o Super Poder
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib +
                         carta->pontos_turisticos + carta->pib_per_capita +
                         (1.0 / carta->densidade_populacional);
}

void comparar_cartas(Carta carta1, Carta carta2) {
    printf("Comparando as cartas:\n");

    // Comparar população
    printf("População: Carta 1 vence? %d\n", carta1.populacao > carta2.populacao);
    
    // Comparar área
    printf("Área: Carta 1 vence? %d\n", carta1.area > carta2.area);
    
    // Comparar PIB
    printf("PIB: Carta 1 vence? %d\n", carta1.pib > carta2.pib);
    
    // Comparar pontos turísticos
    printf("Pontos Turísticos: Carta 1 vence? %d\n", carta1.pontos_turisticos > carta2.pontos_turisticos);
    
    // Comparar PIB per capita
    printf("PIB per Capita: Carta 1 vence? %d\n", carta1.pib_per_capita > carta2.pib_per_capita);
    
    // Comparar densidade populacional (menor vence)
    printf("Densidade Populacional: Carta 1 vence? %d\n", carta1.densidade_populacional < carta2.densidade_populacional);
    
    // Comparar Super Poder
    printf("Super Poder: Carta 1 vence? %d\n", carta1.super_poder > carta2.super_poder);
}

int main() {
    Carta carta1, carta2;

    // Entrada de dados para a Carta 1
    printf("Digite o nome da Carta 1: ");
    scanf("%s", carta1.nome);
    printf("Digite o estado da Carta 1: ");
    scanf("%s", carta1.estado);
    printf("Digite o código da Carta 1: ");
    scanf("%d", &carta1.codigo);
    printf("Digite a população da Carta 1: ");
    scanf("%lu", &carta1.populacao);
    printf("Digite a área da Carta 1: ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB da Carta 1: ");
    scanf("%lu", &carta1.pib);
    printf("Digite o número de pontos turísticos da Carta 1: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Entrada de dados para a Carta 2
    printf("\nDigite o nome da Carta 2: ");
    scanf("%s", carta2.nome);
    printf("Digite o estado da Carta 2: ");
    scanf("%s", carta2.estado);
    printf("Digite o código da Carta 2: ");
    scanf("%d", &carta2.codigo);
    printf("Digite a população da Carta 2: ");
    scanf("%lu", &carta2.populacao);
    printf("Digite a área da Carta 2: ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB da Carta 2: ");
    scanf("%lu", &carta2.pib);
    printf("Digite o número de pontos turísticos da Carta 2: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Calcular atributos para ambas as cartas
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // Comparar as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}
