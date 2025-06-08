#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3];
    char nome[30];
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    int pontos;
};

void calcularIndicadores(struct Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
}

int main() {
    struct Carta c1 = {
        "SP",
        "SaoPaulo",
        101,
        12300000,
        72.1,
        799.3,
        120,
        0, 0, 0
    };

    struct Carta c2 = {
        "BA",
        "Salvador",
        202,
        2886698,
        693.8,
        67.6,
        95,
        0, 0, 0
    };

    calcularIndicadores(&c1);
    calcularIndicadores(&c2);

    // Exibição
    printf("========== CARTAS CADASTRADAS ==========\n");

    printf("\nCARTA 1:\n");
    printf("Estado: %s\n", c1.estado);
    printf("Cidade: %s\n", c1.nome);
    printf("Código: %d\n", c1.codigo);
    printf("População: %d\n", c1.populacao);
    printf("Área: %.1f km²\n", c1.area);
    printf("PIB: R$ %.1f bilhões\n", c1.pib);
    printf("Pontos turísticos: %d\n", c1.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c1.densidade);
    printf("PIB per capita: R$ %.2f\n", c1.pibPerCapita);

    printf("\nCARTA 2:\n");
    printf("Estado: %s\n", c2.estado);
    printf("Cidade: %s\n", c2.nome);
    printf("Código: %d\n", c2.codigo);
    printf("População: %d\n", c2.populacao);
    printf("Área: %.1f km²\n", c2.area);
    printf("PIB: R$ %.1f bilhões\n", c2.pib);
    printf("Pontos turísticos: %d\n", c2.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c2.densidade);
    printf("PIB per capita: R$ %.2f\n", c2.pibPerCapita);

    printf("\n➡️ Pronto para iniciar a comparação.\n");
char cidadeVencedora[30] = "";
char atributoNome[40] = "";
int empate = 0;
int atributo = 3;
switch (atributo) {
    case 1:
        strcpy(atributoNome, "população");
        if (c1.populacao > c2.populacao) strcpy(cidadeVencedora, c1.nome);
        else if (c2.populacao > c1.populacao) strcpy(cidadeVencedora, c2.nome);
        else empate = 1;
        break;
    case 2:
        strcpy(atributoNome, "área");
        if (c1.area > c2.area) strcpy(cidadeVencedora, c1.nome);
        else if (c2.area > c1.area) strcpy(cidadeVencedora, c2.nome);
        else empate = 1;
        break;
    case 3:
        strcpy(atributoNome, "PIB");
        if (c1.pib > c2.pib) strcpy(cidadeVencedora, c1.nome);
        else if (c2.pib > c1.pib) strcpy(cidadeVencedora, c2.nome);
        else empate = 1;
        break;
    case 4:
        strcpy(atributoNome, "pontos turísticos");
        if (c1.pontosTuristicos > c2.pontosTuristicos) strcpy(cidadeVencedora, c1.nome);
        else if (c2.pontosTuristicos > c1.pontosTuristicos) strcpy(cidadeVencedora, c2.nome);
        else empate = 1;
        break;
    case 5:
        strcpy(atributoNome, "densidade populacional");
        if (c1.densidade < c2.densidade) strcpy(cidadeVencedora, c1.nome);
        else if (c2.densidade < c1.densidade) strcpy(cidadeVencedora, c2.nome);
        else empate = 1;
        break;
    case 6:
        strcpy(atributoNome, "PIB per capita");
        if (c1.pibPerCapita > c2.pibPerCapita) strcpy(cidadeVencedora, c1.nome);
        else if (c2.pibPerCapita > c1.pibPerCapita) strcpy(cidadeVencedora, c2.nome);
        else empate = 1;
        break;
    default:
        printf("Código de atributo inválido.\n");
        return 1;
}

if (empate) {
    printf("\n⚖️ Empate na comparação por %s!\n", atributoNome);
} else {
    printf("\n🏆 A cidade vencedora é: %s (comparando %s)\n", cidadeVencedora, atributoNome);
}

    return 0;
}
