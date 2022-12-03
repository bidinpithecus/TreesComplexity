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

void printColumnNamesinFile(FILE *fptr);
int gerarQuantidadeDeChavesAleatoria();
int *gerarConjuntoPiorCaso(int n);
int *gerarConjuntoCasoMedio(int n);