#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore_b {
    int total;
    int* chaves;
    struct no_arvore_b** filhos;
    struct no_arvore_b* pai;
} NoArvoreB;

typedef struct arvoreB {
    NoArvoreB* raiz;
    int ordem;
} ArvoreB;

ArvoreB* criaArvoreB(int, int * contador);
NoArvoreB* criaNoArvoreB(ArvoreB*, int * contador);
void percorreArvoreB(NoArvoreB*, int * contador);
int pesquisaBinariaArvoreB(NoArvoreB*, int, int * contador);
int localizaChaveArvoreB(ArvoreB*, int, int * contador);
NoArvoreB* localizaNoArvoreB(ArvoreB*, int, int * contador);
void adicionaChaveNoArvoreB(NoArvoreB*, NoArvoreB*, int, int * contador);
int transbordoArvoreB(ArvoreB*, NoArvoreB*, int * contador);
NoArvoreB* divideNoArvoreB(ArvoreB*, NoArvoreB*, int * contador);
void adicionaChaveRecursivoArvoreB(ArvoreB*, NoArvoreB*, NoArvoreB*, int, int * contador);
void adicionaChaveArvoreB(ArvoreB*, int, int * contador);
