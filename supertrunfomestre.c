#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[30];
    char cidade[30];
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

float calcularPibPerCapita(float pib, int populacao) {
    return (pib * 1000000000) / populacao;
}

void compararDoisAtributos(struct Carta c1, struct Carta c2, int atr1, int atr2) {
    int pontosC1 = 0, pontosC2 = 0;
    char nomeAtr1[40], nomeAtr2[40];

    // Comparação do primeiro atributo
    switch (atr1) {
        case 1: pontosC1 += (c1.populacao > c2.populacao) ? 1 : 0; pontosC2 += (c2.populacao > c1.populacao) ? 1 : 0; strcpy(nomeAtr1, "população"); break;
        case 2: pontosC1 += (c1.area > c2.area) ? 1 : 0; pontosC2 += (c2.area > c1.area) ? 1 : 0; strcpy(nomeAtr1, "área"); break;
        case 3: pontosC1 += (c1.pib > c2.pib) ? 1 : 0; pontosC2 += (c2.pib > c1.pib) ? 1 : 0; strcpy(nomeAtr1, "PIB"); break;
        case 4: pontosC1 += (calcularDensidade(c1.populacao, c1.area) > calcularDensidade(c2.populacao, c2.area)) ? 1 : 0;
                pontosC2 += (calcularDensidade(c2.populacao, c2.area) > calcularDensidade(c1.populacao, c1.area)) ? 1 : 0; strcpy(nomeAtr1, "densidade"); break;
        case 5: pontosC1 += (calcularPibPerCapita(c1.pib, c1.populacao) > calcularPibPerCapita(c2.pib, c2.populacao)) ? 1 : 0;
                pontosC2 += (calcularPibPerCapita(c2.pib, c2.populacao) > calcularPibPerCapita(c1.pib, c1.populacao)) ? 1 : 0; strcpy(nomeAtr1, "PIB per capita"); break;
        case 6: pontosC1 += (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 0; pontosC2 += (c2.pontosTuristicos > c1.pontosTuristicos) ? 1 : 0; strcpy(nomeAtr1, "pontos turísticos"); break;
        default: printf("Atributo 1 inválido.\n"); return;
    }

    // Comparação do segundo atributo
    switch (atr2) {
        case 1: pontosC1 += (c1.populacao > c2.populacao) ? 1 : 0; pontosC2 += (c2.populacao > c1.populacao) ? 1 : 0; strcpy(nomeAtr2, "população"); break;
        case 2: pontosC1 += (c1.area > c2.area) ? 1 : 0; pontosC2 += (c2.area > c1.area) ? 1 : 0; strcpy(nomeAtr2, "área"); break;
        case 3: pontosC1 += (c1.pib > c2.pib) ? 1 : 0; pontosC2 += (c2.pib > c1.pib) ? 1 : 0; strcpy(nomeAtr2, "PIB"); break;
        case 4: pontosC1 += (calcularDensidade(c1.populacao, c1.area) > calcularDensidade(c2.populacao, c2.area)) ? 1 : 0;
                pontosC2 += (calcularDensidade(c2.populacao, c2.area) > calcularDensidade(c1.populacao, c1.area)) ? 1 : 0; strcpy(nomeAtr2, "densidade"); break;
        case 5: pontosC1 += (calcularPibPerCapita(c1.pib, c1.populacao) > calcularPibPerCapita(c2.pib, c2.populacao)) ? 1 : 0;
                pontosC2 += (calcularPibPerCapita(c2.pib, c2.populacao) > calcularPibPerCapita(c1.pib, c1.populacao)) ? 1 : 0; strcpy(nomeAtr2, "PIB per capita"); break;
        case 6: pontosC1 += (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 0; pontosC2 += (c2.pontosTuristicos > c1.pontosTuristicos) ? 1 : 0; strcpy(nomeAtr2, "pontos turísticos"); break;
        default: printf("Atributo 2 inválido.\n"); return;
    }

    printf("\nResultado da comparação:\n");
    printf("%s venceu em %s e %s com %d ponto(s).\n", 
        (pontosC1 > pontosC2) ? c1.cidade : (pontosC2 > pontosC1) ? c2.cidade : "Empate",
        nomeAtr1, nomeAtr2,
        (pontosC1 > pontosC2) ? pontosC1 : (pontosC2 > pontosC1) ? pontosC2 : pontosC1);
}

int main() {
    struct Carta c1 = {"SP", "Sao Paulo", 101, 12300000, 72.1, 799.3, 120};
    struct Carta c2 = {"BA", "Salvador", 202, 2886698, 693.8, 67.6, 95};
    int opcao, atr1, atr2;

    do {
        printf("\n==== MENU MESTRE ====");
        printf("\n1 - Comparar dois atributos");
        printf("\n0 - Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nAtributos disponíveis:\n");
                printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade\n5 - PIB per capita\n6 - Pontos turísticos\n");
                printf("Escolha o primeiro atributo: ");
                scanf("%d", &atr1);
                printf("Escolha o segundo atributo: ");
                scanf("%d", &atr2);
                compararDoisAtributos(c1, c2, atr1, atr2);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
