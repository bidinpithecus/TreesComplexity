#include "arvore_avl.h"

ArvoreAVL* criarArvoreAVL() {
    ArvoreAVL *arvore = malloc(sizeof(ArvoreAVL));
    arvore->raiz = NULL;

    return arvore;
}

No_AVL* adicionarNoAVL(No_AVL* no, int valor, int * contador) {
    (*contador) += 1;
    if (valor > no->valor) {
        (*contador) += 1;
        if (no->direita == NULL) {
            No_AVL* novo = malloc(sizeof(No_AVL));
            novo->valor = valor;
            (*contador) += 1;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;

            (*contador) += 1;
            no->direita = novo;

            return novo;
        } else {
            return adicionarNoAVL(no->direita, valor, contador);
        }
    } else {
        (*contador) += 1;
        if (no->esquerda == NULL) {
            No_AVL* novo = malloc(sizeof(No_AVL));
            novo->valor = valor;
            (*contador) += 1;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;

            (*contador) += 1;
            no->esquerda = novo;

            return novo;
        } else {
            return adicionarNoAVL(no->esquerda, valor, contador);
        }
    }
}

No_AVL* adicionarAVL(ArvoreAVL* arvore, int valor, int * contador) {
    (*contador) += 1;
    if (arvore->raiz == NULL) {
        No_AVL* novo = malloc(sizeof(No_AVL));
        novo->valor = valor;
        novo->pai = NULL;
        novo->direita = NULL;
        novo->esquerda = NULL;
        (*contador) += 1;
        arvore->raiz = novo;
        return novo;
    } else {
        No_AVL* no = adicionarNoAVL(arvore->raiz, valor, contador);
        balanceamentoAVL(arvore, no, contador);

        return no;
    }
}

void balanceamentoAVL(ArvoreAVL* arvore, No_AVL* no, int * contador) {
    while (no != NULL) {
        (*contador) += 1;
        int fator = fbAVL(no, contador);
        (*contador) += 1;
        if (fator > 1) { // árvore mais pesada para esquerda
            // rotação para a direita (++)
            (*contador) += 1;
            if (fbAVL(no->esquerda, contador) > 0) {
                // printf("RSD(%d)\n",no->valor);
                rsd(arvore, no, contador); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                // printf("RDD(%d)\n",no->valor);
                rdd(arvore, no, contador); //rotação dupla a direita, pois o FB do filho tem sinal diferente (+-)
            }
        } else if (fator < -1) { // árvore mais pesada para a direita
            // rotação para a esquerda (--)
            (*contador) += 2;
            if (fbAVL(no->direita, contador) < 0) {
               // printf("RSE(%d)\n", no->valor);
                rse(arvore, no, contador); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                // printf("RDE(%d)\n", no->valor);
                rde(arvore, no, contador); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente (-+)
            }
        } else {
            (*contador) += 1;
        }

        no = no->pai;
    }
}

int alturaAVL(No_AVL* no, int * contador){
//    // TODO: resolver segmentation fault
//    (*contador) += 1;
//    if (no == NULL) {
//        return -1;
//    }

    int esquerda = 0, direita = 0;

    (*contador) += 1;
    if (no->esquerda != NULL) {
        esquerda = alturaAVL(no->esquerda, contador) + 1;
    }

    (*contador) += 1;
    if (no->direita != NULL) {
        direita = alturaAVL(no->direita, contador) + 1;
    }

    (*contador) += 1;
    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

// Quando o FB resultar em um valor diferente de 0, -1 ou 1, deverá ser realizada uma das operações de balanceamentoAVL
int fbAVL(No_AVL* no, int * contador) {
//    (*contador) += 1;
//    // TODO: Resolver segmentation fault
//    if (no == NULL) {
//        return 0;
//    }

    int esquerda = 0,direita = 0;

    (*contador) += 1;
    if (no->esquerda != NULL) {
        esquerda = alturaAVL(no->esquerda, contador) + 1;
    }

    (*contador) += 1;
    if (no->direita != NULL) {
        direita = alturaAVL(no->direita, contador) + 1;
    }

    return esquerda - direita;
}

// Operações de balanceamentoAVL:
// Rotação simples à esquerda(--): FB desbalanceado negativo, nó à direita com FB negativo
No_AVL* rse(ArvoreAVL* arvore, No_AVL* no, int * contador) {

    No_AVL* pai = no->pai;
    No_AVL* direita = no->direita;

    (*contador) += 1;
    no->direita = direita->esquerda;
    (*contador) += 1;
    no->pai = direita;

    (*contador) += 1;
    direita->esquerda = no;
    (*contador) += 1;
    direita->pai = pai;

    (*contador) += 1;
    if (no->direita != NULL)
        no->direita->pai = no;

    (*contador) += 1;
    if (pai == NULL) {
        (*contador) += 1;
        arvore->raiz = direita;
    } else {
        (*contador) += 1;
        if (pai->esquerda == no) {
            (*contador) += 1;
            pai->esquerda = direita;
        } else {
            (*contador) += 1;
            pai->direita = direita;
        }
    }

    return direita;
}

// Rotação simples à direita(++): FB desbalanceado positivo, nó à esquerda com FB positivo
No_AVL* rsd(ArvoreAVL* arvore, No_AVL* no, int * contador) {
    No_AVL* pai = no->pai;
    No_AVL* esquerda = no->esquerda;

    (*contador) += 1;
    no->esquerda = esquerda->direita;
    (*contador) += 1;
    no->pai = esquerda;

    (*contador) += 1;
    esquerda->direita = no;
    (*contador) += 1;
    esquerda->pai = pai;

    (*contador) += 1;
    if (no->esquerda != NULL) {
        (*contador) += 1;
        no->esquerda->pai = no;
    }

    (*contador) += 1;
    if (pai == NULL) {
        (*contador) += 1;
        arvore->raiz = esquerda;
    } else if (pai->esquerda == no) {
            (*contador) += 2;
            pai->esquerda = esquerda;
        } else {
            (*contador) += 2;
            pai->direita = esquerda;
        }

    return esquerda;
}

// Rotação dupla à esquerda(-+): FB desbalanceado negativo, nó à direita com FB positivo
No_AVL* rde(ArvoreAVL* arvore, No_AVL* no, int * contador) {
    (*contador) += 1;
    no->direita = rsd(arvore, no->direita, contador);
    return rse(arvore, no, contador);
}

// Rotação simples à direita(+-): FB desbalanceado positivo, nó à esquerda com FB negativo
No_AVL* rdd(ArvoreAVL* arvore, No_AVL* no, int * contador) {
    (*contador) += 1;
    no->esquerda = rse(arvore, no->esquerda, contador);
    return rsd(arvore, no, contador);
}

void percorrerProfundidadeInOrderAVL(No_AVL* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrderAVL(no->esquerda, callback);
        callback(no->valor);
        percorrerProfundidadeInOrderAVL(no->direita, callback);
    }
}
