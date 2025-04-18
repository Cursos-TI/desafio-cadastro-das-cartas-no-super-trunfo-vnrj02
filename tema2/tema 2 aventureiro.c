#include <stdio.h>

int main() {
    // Dados da Carta 1
    char pais1[] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1868000.0; 
    int pontos1 = 25;
    float densidade1 = populacao1 / area1;

    // Dados da Carta 2
    char pais2[] = "Canadá";
    int populacao2 = 38000000;
    float area2 = 9984670.0;
    float pib2 = 1990000.0; 
    int pontos2 = 18;
    float densidade2 = populacao2 / area2;

    int opcao;

    // menu
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE PAÍSES ===\n\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=== Comparação entre %s e %s ===\n\n", pais1, pais2);

   
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", pais1, populacao1);
            printf("%s: %d habitantes\n", pais2, populacao2);

            if (populacao1 > populacao2) {
                printf("\nResultado: %s venceu!\n", pais1);
            } else if (populacao2 > populacao1) {
                printf("\nResultado: %s venceu!\n", pais2);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", pais1, area1);
            printf("%s: %.2f km²\n", pais2, area2);

            if (area1 > area2) {
                printf("\nResultado: %s venceu!\n", pais1);
            } else if (area2 > area1) {
                printf("\nResultado: %s venceu!\n", pais2);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f bilhões\n", pais1, pib1);
            printf("%s: R$ %.2f bilhões\n", pais2, pib2);

            if (pib1 > pib2) {
                printf("\nResultado: %s venceu!\n", pais1);
            } else if (pib2 > pib1) {
                printf("\nResultado: %s venceu!\n", pais2);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos turísticos\n", pais1, pontos1);
            printf("%s: %d pontos turísticos\n", pais2, pontos2);

            if (pontos1 > pontos2) {
                printf("\nResultado: %s venceu!\n", pais1);
            } else if (pontos2 > pontos1) {
                printf("\nResultado: %s venceu!\n", pais2);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", pais1, densidade1);
            printf("%s: %.2f hab/km²\n", pais2, densidade2);

        
            if (densidade1 < densidade2) {
                printf("\nResultado: %s venceu!\n", pais1);
            } else if (densidade2 < densidade1) {
                printf("\nResultado: %s venceu!\n", pais2);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
            break;
    }

    return 0;
}
