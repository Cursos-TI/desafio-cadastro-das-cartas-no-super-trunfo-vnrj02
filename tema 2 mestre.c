#include <stdio.h>

int main() {
 //dados das cartas salvando
    char pais1[] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1868000.0; 
    int pontos1 = 25;
    float densidade1 = populacao1 / area1;

    char pais2[] = "Canadá";
    int populacao2 = 38000000;
    float area2 = 9984670.0;
    float pib2 = 1990000.0;
    int pontos2 = 18;
    float densidade2 = populacao2 / area2;

    int escolha1, escolha2;
    float valor1_carta1 = 0, valor2_carta1 = 0;
    float valor1_carta2 = 0, valor2_carta2 = 0;
    float soma1 = 0, soma2 = 0;

   
    printf("=== SUPER TRUNFO: COMPARAÇÃO COM DOIS ATRIBUTOS ===\n\n");
    printf("Atributos disponíveis:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (MENOR vence)\n");

    printf("\nEscolha o primeiro atributo (1-5): ");
    scanf("%d", &escolha1);

    if (escolha1 < 1 || escolha1 > 5) {
        printf("Opção inválida para o primeiro atributo.\n");
        return 1;
    }
//menu 
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("%d - População\n", i); break;
                case 2: printf("%d - Área\n", i); break;
                case 3: printf("%d - PIB\n", i); break;
                case 4: printf("%d - Pontos Turísticos\n", i); break;
                case 5: printf("%d - Densidade Demográfica\n", i); break;
            }
        }
    }

    printf("Escolha: ");
    scanf("%d", &escolha2);
//escolhas
    
    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Opção inválida para o segundo atributo.\n");
    
        return 1;
    }


    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? escolha1 : escolha2;

        float v1, v2;
        switch (atributo) {
            case 1:
                v1 = populacao1;
                v2 = populacao2;
                break;
            case 2:
                v1 = area1;
                v2 = area2;
                break;
            case 3:
                v1 = pib1;
                v2 = pib2;
                break;
            case 4:
                v1 = pontos1;
                v2 = pontos2;
                break;
            case 5:
                v1 = densidade1;
                v2 = densidade2;
                break;
            default:
                printf("Erro interno.\n");
                return 1;
        }

        printf("\nAtributo %d: ", i);
        switch (atributo) {
            case 1: printf("População\n"); break;
            case 2: printf("Área\n"); break;
            case 3: printf("PIB\n"); break;
            case 4: printf("Pontos Turísticos\n"); break;
            case 5: printf("Densidade Demográfica\n"); break;
        }

        // valores (anotacoes)
        printf("%s: %.2f\n", pais1, v1);
        printf("%s: %.2f\n", pais2, v2);

       
        if (atributo == 5) {
            soma1 += (v1 < v2) ? 1 : 0;
            soma2 += (v2 < v1) ? 1 : 0;
        } else {
            soma1 += (v1 > v2) ? 1 : 0;
            soma2 += (v2 > v1) ? 1 : 0;
        }
    }

  
    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s - Pontos: %.0f\n", pais1, soma1);
    printf("%s - Pontos: %.0f\n", pais2, soma2);

    
    printf("\nResultado: %s\n",
           (soma1 > soma2) ? pais1 :
           (soma2 > soma1) ? pais2 :
           " FOI Empate! INFELIZMENTE");

    return 0;
}
