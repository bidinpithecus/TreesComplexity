#include "arvore_b.h"

ArvoreB* criaArvoreB(int ordem, int * contador) {
    ArvoreB* a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;
    a->raiz = criaNoArvoreB(a, contador);

    return a;
}

NoArvoreB* criaNoArvoreB(ArvoreB* arvore, int * contador) {
    int max = arvore->ordem * 2;
    NoArvoreB* no = malloc(sizeof(NoArvoreB));

    no->pai = NULL;

    no->chaves = malloc(sizeof(int) * (max + 1));
    no->filhos = malloc(sizeof(NoArvoreB) * (max + 2));
    no->total = 0;

    (*contador) += 1;
    for (int i = 0; i < max + 2; i++) {
        (*contador) += 1;
        no->filhos[i] = NULL;
    }

    return no;
}

void percorreArvoreB(NoArvoreB* no, int * contador) {
    (*contador) += 1;
    if (no != NULL) {
        (*contador) += 1;
        for (int i = 0; i < no->total; i++){
            (*contador) += 1;
            percorreArvoreB(no->filhos[i], contador); //visita o filho a esquerda

            printf("%d ",no->chaves[i]);
        }

        percorreArvoreB(no->filhos[no->total], contador); //visita ultimo filho (direita)
    }
}

int pesquisaBinariaArvoreB(NoArvoreB* no, int chave, int * contador) {
    int inicio = 0, fim = no->total - 1, meio;

    while (inicio <= fim) {
        (*contador) += 1;

        meio = (inicio + fim) / 2;

        (*contador) += 1;
        if (no->chaves[meio] == chave) {
            return meio; //encontrou
        } else {
            (*contador) += 1;
            if (no->chaves[meio] > chave) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
    }
    return inicio; //não encontrou
}

int localizaChaveArvoreB(ArvoreB* arvore, int chave, int * contador) {
    NoArvoreB *no = arvore->raiz;

    while (no != NULL) {
        int i = pesquisaBinariaArvoreB(no, chave, contador);

        if (i < no->total && no->chaves[i] == chave) {
            return 1; //encontrou
        } else {
            no = no->filhos[i];
        }
    }

    return 0; //não encontrou
}

NoArvoreB* localizaNoArvoreB(ArvoreB* arvore, int chave, int * contador) {
    NoArvoreB *no = arvore->raiz;

    while (no != NULL) {
        (*contador) += 1;
        int i = pesquisaBinariaArvoreB(no, chave, contador);

        (*contador) += 1;
        if (no->filhos[i] == NULL)
            return no; //encontrou nó
        else
            no = no->filhos[i];
    }

    return NULL; //não encontrou nenhum nó
}

void adicionaChaveNoArvoreB(NoArvoreB* no, NoArvoreB* novo, int chave, int * contador) {
    int i = pesquisaBinariaArvoreB(no, chave, contador);
    (*contador) += 1;
    for (int j = no->total - 1; j >= i; j--) {
        (*contador) += 1;
        (*contador) += 1;
        no->chaves[j + 1] = no->chaves[j];
        (*contador) += 1;
        no->filhos[j + 2] = no->filhos[j + 1];
    }

    (*contador) += 1;
    no->chaves[i] = chave;
    (*contador) += 1;
    no->filhos[i + 1] = novo;

    no->total++;
}

int transbordoArvoreB(ArvoreB* arvore, NoArvoreB* no, int * contador) {
    (*contador) += 1;
    return no->total > arvore->ordem * 2;
}

NoArvoreB* divideNoArvoreB(ArvoreB* arvore, NoArvoreB* no, int * contador) {
    int meio = no->total / 2;
    NoArvoreB* novo = criaNoArvoreB(arvore, contador);
    (*contador) += 1;
    novo->pai = no->pai;
    (*contador) += 1;
    for (int i = meio + 1; i < no->total; i++) {
        (*contador) += 1;
        (*contador) += 1;
        novo->filhos[novo->total] = no->filhos[i];
        (*contador) += 1;
        novo->chaves[novo->total] = no->chaves[i];
        (*contador) += 1;
        if (novo->filhos[novo->total] != NULL) {
            (*contador) += 1;
            novo->filhos[novo->total]->pai = novo;
        }

        novo->total++;
    }

    (*contador) += 1;
    novo->filhos[novo->total] = no->filhos[no->total];
    (*contador) += 1;
    if (novo->filhos[novo->total] != NULL) {
        (*contador) += 1;
        novo->filhos[novo->total]->pai = novo;
    }
    (*contador) += 1;
    no->total = meio;
    return novo;
}

void adicionaChaveRecursivoArvoreB(ArvoreB* arvore, NoArvoreB* no, NoArvoreB* novo, int chave, int * contador) {

    adicionaChaveNoArvoreB(no, novo, chave, contador);

    (*contador) += 1;
    if (transbordoArvoreB(arvore, no, contador)) {
        int promovido = no->chaves[arvore->ordem];
        novo = divideNoArvoreB(arvore, no, contador);

        (*contador) += 1;
        if (no->pai == NULL) {

            NoArvoreB* pai = criaNoArvoreB(arvore, contador);
            (*contador) += 1;
            pai->filhos[0] = no;
            adicionaChaveNoArvoreB(pai, novo, promovido, contador);

            (*contador) += 1;
            no->pai = pai;
            (*contador) += 1;
            novo->pai = pai;
            (*contador) += 1;
            arvore->raiz = pai;
        } else
            adicionaChaveRecursivoArvoreB(arvore, no->pai, novo, promovido, contador);
    }
}

void adicionaChaveArvoreB(ArvoreB* arvore, int chave, int * contador) {
    NoArvoreB* no = localizaNoArvoreB(arvore, chave, contador);

    adicionaChaveRecursivoArvoreB(arvore, no, NULL, chave, contador);
}