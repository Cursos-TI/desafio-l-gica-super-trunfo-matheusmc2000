#include <stdio.h>
#include <string.h>

int main() {
    // -----------------------------
    // CARTAS PRÉ-CADASTRADAS
    // -----------------------------
    char nome1[30] = "Brasil";
    char nome2[30] = "Japão";

    int populacao1 = 214000000, populacao2 = 126000000;
    float area1 = 8516000.0, area2 = 377975.0;
    float pib1 = 2.3, pib2 = 5.0; // PIB em trilhões
    int pontosTuristicos1 = 12, pontosTuristicos2 = 25;

    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int atributo1, atributo2;
    float valorA1_carta1 = 0, valorA1_carta2 = 0;
    float valorA2_carta1 = 0, valorA2_carta2 = 0;
    float somaCarta1, somaCarta2;

    // -----------------------------
    // MENU 1 – Escolha do primeiro atributo
    // -----------------------------
    printf("=== SUPER TRUNFO FINAL ===\n\n");
    printf("Cartas:\n1. %s\n2. %s\n\n", nome1, nome2);

    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Validação básica
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 0;
    }

    // -----------------------------
    // MENU 2 – Escolha do segundo atributo (dinâmico)
    // -----------------------------
    printf("\nAgora escolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Impedir repetição
    if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
        printf("Atributo inválido ou repetido! Encerrando o programa.\n");
        return 0;
    }

    // -----------------------------
    // COMPARAÇÃO DOS DOIS ATRIBUTOS
    // -----------------------------
    printf("\n=== COMPARAÇÃO ENTRE %s E %s ===\n\n", nome1, nome2);

    for (int rodada = 1; rodada <= 2; rodada++) {
        int atributo = (rodada == 1) ? atributo1 : atributo2;

        switch (atributo) {
            case 1: // População
                printf("Atributo %d: População\n", rodada);
                printf("%s: %d\n", nome1, populacao1);
                printf("%s: %d\n", nome2, populacao2);
                if (rodada == 1) {
                    valorA1_carta1 = populacao1;
                    valorA1_carta2 = populacao2;
                } else {
                    valorA2_carta1 = populacao1;
                    valorA2_carta2 = populacao2;
                }
                printf("Vencedor parcial: %s\n\n",
                       (populacao1 > populacao2) ? nome1 :
                       (populacao2 > populacao1) ? nome2 : "Empate");
                break;

            case 2: // Área
                printf("Atributo %d: Área (km²)\n", rodada);
                printf("%s: %.2f\n", nome1, area1);
                printf("%s: %.2f\n", nome2, area2);
                if (rodada == 1) {
                    valorA1_carta1 = area1;
                    valorA1_carta2 = area2;
                } else {
                    valorA2_carta1 = area1;
                    valorA2_carta2 = area2;
                }
                printf("Vencedor parcial: %s\n\n",
                       (area1 > area2) ? nome1 :
                       (area2 > area1) ? nome2 : "Empate");
                break;

            case 3: // PIB
                printf("Atributo %d: PIB (trilhões USD)\n", rodada);
                printf("%s: %.2f\n", nome1, pib1);
                printf("%s: %.2f\n", nome2, pib2);
                if (rodada == 1) {
                    valorA1_carta1 = pib1;
                    valorA1_carta2 = pib2;
                } else {
                    valorA2_carta1 = pib1;
                    valorA2_carta2 = pib2;
                }
                printf("Vencedor parcial: %s\n\n",
                       (pib1 > pib2) ? nome1 :
                       (pib2 > pib1) ? nome2 : "Empate");
                break;

            case 4: // Pontos turísticos
                printf("Atributo %d: Pontos Turísticos\n", rodada);
                printf("%s: %d\n", nome1, pontosTuristicos1);
                printf("%s: %d\n", nome2, pontosTuristicos2);
                if (rodada == 1) {
                    valorA1_carta1 = pontosTuristicos1;
                    valorA1_carta2 = pontosTuristicos2;
                } else {
                    valorA2_carta1 = pontosTuristicos1;
                    valorA2_carta2 = pontosTuristicos2;
                }
                printf("Vencedor parcial: %s\n\n",
                       (pontosTuristicos1 > pontosTuristicos2) ? nome1 :
                       (pontosTuristicos2 > pontosTuristicos1) ? nome2 : "Empate");
                break;

            case 5: // Densidade demográfica (menor vence)
                printf("Atributo %d: Densidade Demográfica (hab/km²)\n", rodada);
                printf("%s: %.2f\n", nome1, densidade1);
                printf("%s: %.2f\n", nome2, densidade2);
                if (rodada == 1) {
                    valorA1_carta1 = densidade1;
                    valorA1_carta2 = densidade2;
                } else {
                    valorA2_carta1 = densidade1;
                    valorA2_carta2 = densidade2;
                }
                printf("Vencedor parcial: %s\n\n",
                       (densidade1 < densidade2) ? nome1 :
                       (densidade2 < densidade1) ? nome2 : "Empate");
                break;
        }
    }

    // -----------------------------
    // SOMA FINAL DOS ATRIBUTOS
    // -----------------------------
    somaCarta1 = valorA1_carta1 + valorA2_carta1;
    somaCarta2 = valorA1_carta2 + valorA2_carta2;

    printf("========================================\n");
    printf("Soma dos Atributos:\n");
    printf("%s: %.2f\n", nome1, somaCarta1);
    printf("%s: %.2f\n", nome2, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("\n🏆 Vencedor Final: %s!\n", nome1);
    } else if (somaCarta2 > somaCarta1) {
        printf("\n🏆 Vencedor Final: %s!\n", nome2);
    } else {
        printf("\n⚖️ Empate!\n");
    }

    printf("========================================\n");

    return 0;
}
