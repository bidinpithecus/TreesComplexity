#include <stdio.h>
#include <stdlib.h>

extern char avlWorstCasePath[];
extern char b1WorstCasePath[];
extern char b5WorstCasePath[];
extern char b10WorstCasePath[];
extern char rubroNegraWorstCasePath[];

extern char avlAvgCasePath[];
extern char b1AvgCasePath[];
extern char b5AvgCasePath[];
extern char b10AvgCasePath[];
extern char rubroNegraAvgCasePath[];

extern int numberOfKeys;
extern int numberOfExecutions;
extern int sizeLimit;

extern register_t counter;

void printColumnNamesinFile(FILE *fptr);
int gerarQuantidadeDeChavesAleatoria();
int *gerarConjuntoCasoMedio(int n);
int randomNum(int max);
void populateRandomArray(int array[], int size);
void eliminateDuplicates(int array[], int *size);