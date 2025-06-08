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

// Função para calcular a densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    return (pib * 1000000000) / populacao;
}

// Função para comparar atributos
void compararCartas(struct Carta c1, struct Carta c2, int opcao) {
    switch (opcao) {
        case 1:
            printf("População: %d vs %d\n", c1.populacao, c2.populacao);
            printf("Vencedora: %s\n", (c1.populacao > c2.populacao) ? c1.cidade : c2.cidade);
            break;
        case 2:
            printf("Área: %.2f km² vs %.2f km²\n", c1.area, c2.area);
            printf("Vencedora: %s\n", (c1.area > c2.area) ? c1.cidade : c2.cidade);
            break;
        case 3:
            printf("PIB: R$ %.2f bilhões vs R$ %.2f bilhões\n", c1.pib, c2.pib);
            printf("Vencedora: %s\n", (c1.pib > c2.pib) ? c1.cidade : c2.cidade);
            break;
        case 4: {
            float d1 = calcularDensidade(c1.populacao, c1.area);
            float d2 = calcularDensidade(c2.populacao, c2.area);
            printf("Densidade: %.2f hab/km² vs %.2f hab/km²\n", d1, d2);
            printf("Vencedora: %s\n", (d1 > d2) ? c1.cidade : c2.cidade);
            break;
        }
        case 5: {
            float p1 = calcularPibPerCapita(c1.pib, c1.populacao);
            float p2 = calcularPibPerCapita(c2.pib, c2.populacao);
            printf("PIB per capita: R$ %.2f vs R$ %.2f\n", p1, p2);
            printf("Vencedora: %s\n", (p1 > p2) ? c1.cidade : c2.cidade);
            break;
        }
        case 6:
            printf("Pontos turísticos: %d vs %d\n", c1.pontosTuristicos, c2.pontosTuristicos);
            printf("Vencedora: %s\n", (c1.pontosTuristicos > c2.pontosTuristicos) ? c1.cidade : c2.cidade);
            break;
        default:
            printf("Opção inválida.\n");
    }
}

int main() {
    struct Carta c1 = {"SP", "Sao Paulo", 101, 12300000, 72.1, 799.3, 120};
    struct Carta c2 = {"BA", "Salvador", 202, 2886698, 693.8, 67.6, 95};

    printf("Cartas cadastradas automaticamente.\n");

    int opcao;
    do {
        printf("\n======= MENU DE COMPARAÇÃO =======\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Densidade populacional\n");
        printf("5. PIB per capita\n");
        printf("6. Pontos turísticos\n");
        printf("0. Sair\n");
        printf("Escolha o atributo para comparar: ");
        scanf("%d", &opcao);

        if (opcao != 0) {
            compararCartas(c1, c2, opcao);
        }

    } while (opcao != 0);

    printf("Encerrando o programa.\n");
    return 0;
}
