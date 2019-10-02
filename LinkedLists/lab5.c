#include <stdio.h>
#include <stdlib.h>

typedef struct _No {
    int dado;
    struct _No * prox;
} No;
typedef No * pNo;

pNo criarLista(void);
pNo adicionaElemento(pNo l, int elem);
pNo removeElemento(pNo l, int elem); 
void imprimeLista(pNo lista);        
void liberaLista(pNo lista);

pNo criarLista(void) {
    return NULL;
}

pNo adicionaElemento(pNo l, int elem) {
    pNo novo;
    novo = malloc(sizeof(No));
    novo->dado = elem;
    novo->prox = l;
    return novo;
}

void liberaLista(pNo lista) {
    if (lista != NULL) {
        liberaLista(lista->prox);
        free(lista);
    }
    return;
}
int main(void) {
    pNo lista;

   lista = criarLista();

    lista =  adicionaElemento(lista,9);
    lista = adicionaElemento(lista,15);
    lista = adicionaElemento(lista,83);

    imprimeLista(lista);

    lista = removeElemento(lista, 15);
    
    imprimeLista(lista);
    
    return 0;
}

pNo removeElemento(pNo l, int elem) {
    pNo prev = l;
    pNo Atual = l;
    
    if(Atual != NULL && Atual->dado == elem){
        
        l = Atual->prox;
        return l;
    }
    
    while(Atual != NULL && Atual->dado != elem){
        prev = Atual;
        Atual = Atual->prox;
    }

    
    if(prev->prox == NULL){
        printf("Não foi encontrado nenhum valor \n");
        return l;
    }
    
    prev->prox = Atual->prox;
    
    return l;

}


void imprimeLista(pNo lista) {
    pNo Atual = lista;

    while(Atual != NULL){
        if(Atual->prox == NULL){
        printf("%d/ \n", Atual->dado);         
        }
        else {
        printf("%d->", Atual->dado);            
        }

        Atual = Atual->prox;
    }
    
    return;
}
