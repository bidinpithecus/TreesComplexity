#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"
#include "arvore_rubro_negra.h"
#include "arvore_b.h"
#include "utils.h"

int main2(void) {
	int test = 10;
	int *vector = malloc(sizeof(int) * test);
	vector[0] = 57;
	vector[1] = 12;
	vector[2] = 89;
	vector[3] = 32;
	vector[4] = 62;
	vector[5] = 12;
	vector[6] = 89;
	vector[7] = 67;
	vector[8] = 75;
	vector[9] = 35;

	for (int i = 0; i < test; i++) {
		printf("%d, ", vector[i]);
	}
	printf("\n");
	
	eliminateDuplicates(vector, &test);

	for (int i = 0; i < test; i++) {
		printf("%d, ", vector[i]);
	}
	printf("\n");
	
	return 0;
}

int main() {
	int contador;
	int quantidade_chaves[] = {1, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

	// AVL Worst Case
	ArvoreAVL *a_avl;

	FILE *fptr = fopen(avlWorstCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	a_avl = criarArvoreAVL();
	for (int j = 0; j < numberOfKeys; j++) {
		adicionarAVL(a_avl, j);
		fprintf(fptr, "%d,%ld\n", j, counter);
		counter = 0;
	}

	fclose(fptr);
	printf("AVL Worst Case generated, its data can be found at %s\n", avlWorstCasePath);

	// AVL Average case
	fptr = fopen(avlAvgCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < numberOfExecutions; j++) {
		counter = 0;
		a_avl = criarArvoreAVL();
		int arrSize = randomNum(numberOfKeys);
		int *array = malloc(sizeof(int) * arrSize);
		populateRandomArray(array, arrSize);
		eliminateDuplicates(array, &arrSize);

		for (int i = 0; i < arrSize; i++) {
			adicionarAVL(a_avl, array[i]);
			fprintf(fptr, "%d,%ld\n", array[i], counter);
			counter = 0;
		}
	}
	fclose(fptr);
	printf("AVL Average Case generated, its data can be found at %s\n", avlAvgCasePath);
	return 0;

	// Rubro Negra Worst case
	ArvoreRubroNegra* a_rubro_negra;

	fptr = fopen(rubroNegraWorstCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		a_rubro_negra = criarRubroNegra();
		for (int i = 1; i <= quantidade_chaves[j]; i++) {
			adicionarRubroNegra(a_rubro_negra, i, &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("Rubro Negra Worst Case generated, its data can be found at %s\n", rubroNegraWorstCasePath);

	// Rubro Negra Average case
	fptr = fopen(rubroNegraAvgCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		ArvoreRubroNegra* a_rubro_negra = criarRubroNegra();

		int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

		for (int i = 0; i < quantidade_chaves[j]; i++) {
			adicionarRubroNegra(a_rubro_negra, chaves_aleatorias[i], &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("Rubro Negra Average Case generated, its data can be found at %s\n", rubroNegraAvgCasePath);


	ArvoreB* arvoreB;
	// Arvore B1 Worst case

	fptr = fopen(b1WorstCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		arvoreB = criaArvoreB(1, &contador);
		for (int i = 1; i <= quantidade_chaves[j]; i++) {
			adicionaChaveArvoreB(arvoreB, i, &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("B1 Worst Case generated, its data can be found at %s\n", b1WorstCasePath);
	
	// Arvore B1 Average case
	fptr = fopen(b1AvgCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		arvoreB = criaArvoreB(1, &contador);

		int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

		for (int i = 0; i < quantidade_chaves[j]; i++) {
			adicionaChaveArvoreB(arvoreB, chaves_aleatorias[i], &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("B1 Average Case generated, its data can be found at %s\n", b1AvgCasePath);
	
	// Arvore B5 Worst case

	fptr = fopen(b5WorstCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		arvoreB = criaArvoreB(5, &contador);
		for (int i = 1; i <= quantidade_chaves[j]; i++) {
			adicionaChaveArvoreB(arvoreB, i, &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("B5 Worst Case generated, its data can be found at %s\n", b5WorstCasePath);
	
	// B5 Average case
	fptr = fopen(b5AvgCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		arvoreB = criaArvoreB(5, &contador);

		int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

		for (int i = 0; i < quantidade_chaves[j]; i++) {
			adicionaChaveArvoreB(arvoreB, chaves_aleatorias[i], &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("B5 Average Case generated, its data can be found at %s\n", b5AvgCasePath);

	// Arvore B10 Worst case

	fptr = fopen(b10WorstCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		arvoreB = criaArvoreB(10, &contador);
		for (int i = 1; i <= quantidade_chaves[j]; i++) {
			adicionaChaveArvoreB(arvoreB, i, &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("B10 Worst Case generated, its data can be found at %s\n", b10WorstCasePath);
	
	// B10 Average case
	fptr = fopen(b10AvgCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	for (int j = 0; j < sizeof(quantidade_chaves) / sizeof(quantidade_chaves[0]); j++) {
		contador = 0;
		arvoreB = criaArvoreB(10, &contador);

		int * chaves_aleatorias = gerarConjuntoCasoMedio(quantidade_chaves[j]);

		for (int i = 0; i < quantidade_chaves[j]; i++) {
			adicionaChaveArvoreB(arvoreB, chaves_aleatorias[i], &contador);
		}
		fprintf(fptr, "%d,%d\n", quantidade_chaves[j], contador);
	}
	fclose(fptr);
	printf("B10 Average Case generated, its data can be found at %s\n", b10AvgCasePath);
	
}