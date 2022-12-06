#include "utils.h"
#include <stdlib.h>
#include <sys/types.h>

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

int numberOfKeys = 1000;
int numberOfExecutions = 2;
int sizeLimit = 100;

register_t counter = 0;

void printColumnNamesinFile(FILE *fptr) {
    fprintf(fptr, "chaves,operações\n");
}

int randomNum(int max) {
	return ((rand() % max) + 1);
}

void populateRandomArray(int array[], int size) {
	for (int j = 0; j < size; j++) {
		array[j] = randomNum(sizeLimit);
	}
}

void eliminateDuplicates(int array[], int *size) {
    printf("%d\n", *size);
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size; j++) {
            if(array[i] == array[j]) {
                for (int k = j; k < *size; k++) {
                    array[k] = array[k+1];
                }
                j--;
                *size -= 1;
            }
        }
        printf("%d\n", *size);
        array = realloc(array, *size);
    }
        printf("%d\n", *size);
}