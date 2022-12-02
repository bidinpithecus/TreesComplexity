#include <stdio.h>
#include "arvore_avl.h"
#include "arvore_rubro_negra.h"
#include "arvore_b.h"
#include "gerador.h"



void imprimeValorDoNo(int valor) {
    printf("%d ", valor);
}


int main() {

    // Teste AVL
    ArvoreAVL * a_avl;

    int contador;
    int quantidade_chaves[11] = {1, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

    printf("AVL Crescente:\n");
    for (int j = 0; j < 11; j++) {
        contador = 0;
        a_avl = criarArvoreAVL();
        for (int i = 1; i <= quantidade_chaves[j]; i++) {
            adicionarAVL(a_avl, i, &contador);
        }

        printf("%i", contador);
        printf("\n");
    }

    printf("AVL Aleatório:\n");
    for (int j = 0; j < 11; j++) {
        contador = 0;
        a_avl = criarArvoreAVL();

        int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

        for (int i = 0; i < quantidade_chaves[j]; i++) {
            adicionarAVL(a_avl, chaves_aleatorias[i], &contador);
        }
        printf("%i", contador);
        printf("\n");
    }


    // Teste Rubro Negra


    printf("Rubro-negra Crescente:\n");
    for (int j = 0; j < 11; j++) {
        contador = 0;
        ArvoreRubroNegra* a_rubro_negra = criarRubroNegra();
        for (int i = 1; i <= quantidade_chaves[j]; i++) {
            adicionarRubroNegra(a_rubro_negra, i, &contador);
        }
        printf("%i", contador);
        printf("\n");
    }

    printf("Rubro-negra Aleatório:\n");
    for (int j = 0; j < 11; j++) {
        contador = 0;
        ArvoreRubroNegra* a_rubro_negra = criarRubroNegra();

        int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

        for (int i = 0; i < quantidade_chaves[j]; i++) {
            adicionarRubroNegra(a_rubro_negra, chaves_aleatorias[i], &contador);
        }
        printf("%i", contador);
        printf("\n");
    }

    // Teste B-tree

    printf("B Crescente:\n");
    for (int j = 0; j < 11; j++) {
        contador = 0;
        ArvoreB* arvoreB = criaArvoreB(1, &contador);
        for (int i = 1; i <= quantidade_chaves[j]; i++) {
            adicionaChaveArvoreB(arvoreB, i, &contador);
        }
        printf("%i", contador);
        printf("\n");
    }

    printf("B Aleatório:\n");
    for (int j = 0; j < 11; j++) {
        contador = 0;
        ArvoreB* arvoreB = criaArvoreB(1, &contador);

        int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

        for (int i = 0; i < quantidade_chaves[j]; i++) {
            adicionaChaveArvoreB(arvoreB, chaves_aleatorias[i], &contador);
        }
        printf("%i", contador);
        printf("\n");
    }
}