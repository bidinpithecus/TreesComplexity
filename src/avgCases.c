#include "avgCases.h"

void populateCsvAvgCaseAVL(char path[], char modes[]) {
	ArvoreAVL *a_avl;

	FILE *fptr = fopen(path, modes);

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	srand(time(NULL));
	for (int j = 0; j < numberOfExecutions; j += step) {
		a_avl = criarArvoreAVL();

		for (int i = 0; i < numberOfKeys; i++) {
			int key = randomNum(sizeLimit);
			adicionarAVL(a_avl, key);
			fprintf(fptr, "%d,%ld\n", key, counter);
			counter = 0;
		}
	}

	fclose(fptr);
	printf("AVL Avg Case generated, its data can be found at %s\n", path);  
}

void populateCsvAvgCaseBTree(char path[], char modes[], int order) {
	ArvoreB* arvoreB;

	FILE *fptr = fopen(path, modes);

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	srand(time(NULL));
	for (int j = 0; j < numberOfExecutions; j += step) {
		arvoreB = criaArvoreB(order);

		for (int i = 0; i < numberOfKeys; i++) {
			int key = randomNum(sizeLimit);
			adicionaChaveArvoreB(arvoreB, j);
			fprintf(fptr, "%d,%ld\n", key, counter);
			counter = 0;
		}
	}

	fclose(fptr);
	printf("B%d Avg Case generated, its data can be found at %s\n", order, path);  
}

void populateCsvAvgCaseRubroNegra(char path[], char modes[]) {
	ArvoreRubroNegra* a_rubro_negra;

	FILE* fptr = fopen(rubroNegraAvgCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	srand(time(NULL));
	for (int j = 0; j < numberOfExecutions; j += step) {
		a_rubro_negra = criarRubroNegra();

		for (int i = 0; i < numberOfKeys; i++) {
			int key = randomNum(sizeLimit);
			adicionarRubroNegra(a_rubro_negra, j);
			fprintf(fptr, "%d,%ld\n", key, counter);
			counter = 0;
		}
	}

	fclose(fptr);
	printf("Rubro Negra Avg Case generated, its data can be found at %s\n", rubroNegraAvgCasePath);

}
