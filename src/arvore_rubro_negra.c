#include "arvore_rubro_negra.h"

ArvoreRubroNegra* criarRubroNegra(int * contador) {
    ArvoreRubroNegra *arvore = malloc(sizeof(ArvoreRubroNegra));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = criarNoRubroNegra(arvore, NULL, 0, contador);
    arvore->nulo->cor = Preto;

    return arvore;
}

int vaziaRubroNegra(ArvoreRubroNegra* arvore, int * contador) {
    return arvore->raiz == NULL;
}

NoRubroNegra* criarNoRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* pai, int valor, int * contador) {
    NoRubroNegra* no = malloc(sizeof(NoRubroNegra));

    no->pai = pai;
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;

    return no;
}

NoRubroNegra* adicionarNoRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no, int valor, int * contador) {
    (*contador) += 1;
    if (valor > no->valor) {
        (*contador) += 1;
        if (no->direita == arvore->nulo) {
            (*contador) += 1;
            no->direita = criarNoRubroNegra(arvore, no, valor, contador);
            no->direita->cor = Vermelho;

            return no->direita;
        } else {
            return adicionarNoRubroNegra(arvore, no->direita, valor, contador);
        }
    } else {
        (*contador) += 1;
        if (no->esquerda == arvore->nulo) {
            (*contador) += 1;
            no->esquerda = criarNoRubroNegra(arvore, no, valor, contador);
            no->esquerda->cor = Vermelho;

            return no->esquerda;
        } else {
            return adicionarNoRubroNegra(arvore, no->esquerda, valor, contador);
        }
    }
}

NoRubroNegra* adicionarRubroNegra(ArvoreRubroNegra* arvore, int valor, int * contador) {
    (*contador) += 1;
    if (vaziaRubroNegra(arvore, contador)) {
        (*contador) += 1;
        arvore->raiz = criarNoRubroNegra(arvore, arvore->nulo, valor, contador);
        (*contador) += 1;
        arvore->raiz->cor = Preto;

        return arvore->raiz;
    } else {
        NoRubroNegra* no = adicionarNoRubroNegra(arvore, arvore->raiz, valor, contador);
        balancearRubroNegra(arvore, no, contador);

        return no;
    }
}

void percorrerProfundidadeInOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int)) {
    if (no != arvore->nulo) {


        percorrerProfundidadeInOrder(arvore, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePreOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePreOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePosOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (callback)(int)) {
    if (no != arvore->nulo) {
        percorrerProfundidadePosOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePosOrder(arvore, no->direita,callback);
        callback(no->valor);
    }
}

void balancearRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no, int * contador) {
    while (no->pai->cor == Vermelho) {
        // TODO: contador+=2
        if (no->pai == no->pai->pai->esquerda) {
            NoRubroNegra *tio = no->pai->pai->direita;

            (*contador) += 1;
            if (tio->cor == Vermelho) {
                (*contador) += 1;
                tio->cor = Preto; //Caso 1
                (*contador) += 1;
                no->pai->cor = Preto;
                (*contador) += 1;
                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                (*contador) += 1;
                if (no == no->pai->direita) {
                    no = no->pai; //Caso 2
                    rotacionarEsquerdaRubroNegra(arvore, no, contador); //Caso 2
                } else {
                    (*contador) += 1;
                    no->pai->cor = Preto;
                    (*contador) += 1;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireitaRubroNegra(arvore, no->pai->pai, contador); //Caso 3
                }
            }
        } else {
            NoRubroNegra *tio = no->pai->pai->esquerda;

            (*contador) += 1;
            if (tio->cor == Vermelho) {
                (*contador) += 1;
                tio->cor = Preto; //Caso 1
                (*contador) += 1;
                no->pai->cor = Preto;

                (*contador) += 1;
                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                (*contador) += 1;
                if (no == no->pai->esquerda) {
                    no = no->pai; //Caso 2
                    rotacionarDireitaRubroNegra(arvore, no, contador); //Caso 2
                } else {
                    (*contador) += 1;
                    no->pai->cor = Preto;
                    (*contador) += 1;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerdaRubroNegra(arvore, no->pai->pai, contador); //Caso 3
                }
            }
        }
    }
    (*contador) += 1;
    arvore->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotacionarEsquerdaRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no, int * contador) {
    NoRubroNegra* direita = no->direita;
    (*contador) += 1;
    no->direita = direita->esquerda;

    (*contador) += 1;
    if (direita->esquerda != arvore->nulo) {
        (*contador) += 1;
        direita->esquerda->pai = no;
    }

    (*contador) += 1;
    direita->pai = no->pai;

    (*contador) += 1;
    if (no->pai == arvore->nulo) {
        (*contador) += 1;
        arvore->raiz = direita;
    } else if (no == no->pai->esquerda) {
        (*contador) += 1;
        no->pai->esquerda = direita;
    } else {
        (*contador) += 1;
        no->pai->direita = direita;
    }

    (*contador) += 1;
    direita->esquerda = no;
    (*contador) += 1;
    no->pai = direita;
}

void rotacionarDireitaRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no, int * contador) {
    NoRubroNegra* esquerda = no->esquerda;
    (*contador) += 1;
    no->esquerda = esquerda->direita;

    (*contador) += 1;
    if (esquerda->direita != arvore->nulo) {
        (*contador) += 1;
        esquerda->direita->pai = no;
    }

    (*contador) += 1;
    esquerda->pai = no->pai;

    (*contador) += 1;
    if (no->pai == arvore->nulo) {
        (*contador) += 1;
        arvore->raiz = esquerda;
    } else if (no == no->pai->esquerda) {
        (*contador) += 1;
        no->pai->esquerda = esquerda;
    } else {
        (*contador) += 1;
        no->pai->direita = esquerda;
    }

    (*contador) += 1;
    esquerda->direita = no;
    (*contador) += 1;
    no->pai = esquerda;
}

void percorrerProfundidadeInOrderRubroNegra(ArvoreRubroNegra * arvore, NoRubroNegra * no, void (*callback)(int), int * contador) {
    if (no != arvore->nulo) {


        percorrerProfundidadeInOrder(arvore, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita,callback);
    }
}