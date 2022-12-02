#include <stdlib.h>
#include <stdio.h>

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct no_rubro_negra {
    struct no_rubro_negra* pai;
    struct no_rubro_negra* esquerda;
    struct no_rubro_negra* direita;
    Cor cor;
    int valor;
} NoRubroNegra;

typedef struct arvore_rubro_negra {
    struct no_rubro_negra* raiz;
    struct no_rubro_negra* nulo;
} ArvoreRubroNegra;

NoRubroNegra* criarNoRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, int, int * contador);
void balancearRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, int * contador);
void rotacionarEsquerdaRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, int * contador);
void rotacionarDireitaRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, int * contador);
ArvoreRubroNegra* criarRubroNegra();
int vaziaRubroNegra(ArvoreRubroNegra*, int * contador);
NoRubroNegra* adicionarRubroNegra(ArvoreRubroNegra*, int, int * contador);
NoRubroNegra* adicionarNoRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no, int valor, int * contador);
void percorrerProfundidadeInOrderRubroNegra(ArvoreRubroNegra * arvore, NoRubroNegra * no, void (*callback)(int), int * contador);