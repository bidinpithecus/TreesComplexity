#include "utils.h"

char avlWorstCasePath[] = "data/worstCaseAVL.csv";
char b1WorstCasePath[] = "data/worstCaseB1.csv";
char b5WorstCasePath[] = "data/worstCaseB5.csv";
char b10WorstCasePath[] = "data/worstCaseB10.csv";
char rubroNegraWorstCasePath[] = "data/worstCaseRubroNegra.csv";

char avlAvgCasePath[] = "data/avgCaseAVL.csv";
char b1AvgCasePath[] = "data/avgCaseB1.csv";
char b5AvgCasePath[] = "data/avgCaseB5.csv";
char b10AvgCasePath[] = "data/avgCaseB10.csv";
char rubroNegraAvgCasePath[] = "data/avgCaseRubroNegra.csv";

void printColumnNamesinFile(FILE *fptr) {
    fprintf(fptr, "chaves,operações\n");
}

int gerarQuantidadeDeChavesAleatoria() {
    return 1 + rand() % 1000;
}

int * gerarConjuntoPiorCaso(int n) {
    // Pior caso são ordenados de forma crescente ou decrescente
    // aloca vetor dinamicamente
    int * conjunto = malloc(n * sizeof(int));

    // randomiza se será crescente ou decrescente
    int crescente_ou_decrescente = rand() % 2;

    // gera os valores ordenados

    if (crescente_ou_decrescente == 0) {
        for (int i = 0; i < n; i++) {
            conjunto[i] = i;
        }

    } else {
        int num = n;
        for (int i = 0; i < n; i++) {
            conjunto[i] = num;
            num--;
        }
    }

    // Teste impressão:
    for (int i = 0; i < n; i++) {
        printf("%i ", conjunto[i]);
    }
    return conjunto;
}

int * gerarConjuntoCasoMedio(int n) {
    // Caso médio: números aleatórios
    // Aloca vetor dinamicamente
    int *conjunto = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int numero_contido_no_conjunto = 0;
        int numero;
        do {
            numero = rand() % n;
            numero_contido_no_conjunto = 0;
            for (int j = 0; j < i; j++) {
                if (numero == conjunto[j]) {
                    numero_contido_no_conjunto = 1;
                    break;
                }
            }
        } while (numero_contido_no_conjunto);
        conjunto[i] = numero;
    }

    return conjunto;
}