#include <stdlib.h>
#include <stdio.h>

typedef struct no_avl {
    struct no_avl* pai;
    struct no_avl* esquerda;
    struct no_avl* direita;
    int valor;
} No_AVL;

typedef struct arvore_avl {
    struct no_avl* raiz;
} ArvoreAVL;

ArvoreAVL* criarArvoreAVL();
No_AVL* adicionarNoAVL(No_AVL* no, int valor, int * contador);
No_AVL* adicionarAVL(ArvoreAVL* arvore, int valor, int * contador);
void balanceamentoAVL(ArvoreAVL* arvore, No_AVL* no, int * contador);
int alturaAVL(No_AVL* no, int * contador);
int fbAVL(No_AVL* no, int * contador);
No_AVL* rsd(ArvoreAVL* arvore, No_AVL* no, int * contador);
No_AVL* rse(ArvoreAVL* arvore, No_AVL* no, int * contador);
No_AVL* rdd(ArvoreAVL* arvore, No_AVL* no, int * contador);
No_AVL* rde(ArvoreAVL* arvore, No_AVL* no, int * contador);
void percorrerProfundidadeInOrderAVL(No_AVL* no, void (*callback)(int));

