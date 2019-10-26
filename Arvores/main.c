#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int dado;
    struct Node *esq, *dir;
} Node;
typedef Node *pNode;

pNode criarArvore(int x, pNode e, pNode d)
{
    pNode r = malloc(sizeof(Node));
    r->dado = x;
    r->esq = e;
    r->dir = d;
    return r;
}

pNode insereNodeEmABB(pNode raiz, int x)
{
    if (raiz == NULL)
        return criarArvore(x, NULL, NULL);

    else if (x < raiz->dado)
        raiz->esq = insereNodeEmABB(raiz->esq, x);

    else if (x > raiz->dado)
        raiz->dir = insereNodeEmABB(raiz->dir, x);

    return raiz;
}

void posOrdem(pNode raiz)
{
    if (raiz == NULL)
        return;

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d", raiz->dado);
}

void preOrdem(pNode raiz)
{
    if (raiz != NULL)
        printf("%d", raiz->dado);

    else
        return;

    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void inOrdem(pNode raiz)
{
    if (raiz == NULL)
        return;

    inOrdem(raiz->esq);
    printf("%d", raiz->dado);
    inOrdem(raiz->dir);
}

int main()
{
    pNode arvore = NULL;
    int number = 0;
    int WhileNumber = 1;
    printf("Digite os numeros (Digite um numero negativo para parar) \n");

    while (number >= 0)
    {
        printf("Numero %d: ", WhileNumber);
        scanf("%d", &number);
        if (number > 0)
            arvore = insereNodeEmABB(arvore, number);
        WhileNumber++;
    }
    printf("Pos Ordem: \n");
    posOrdem(arvore);
    printf("\n");
    printf("Pre Ordem: \n");
    preOrdem(arvore);
    printf("\n");
    printf("In Ordem: \n");
    inOrdem(arvore);
    printf("\n");
}
