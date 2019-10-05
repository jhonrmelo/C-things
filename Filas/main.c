#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _pedido
{
    char nome[200];
    char prato[200];
    int senha;
} pedido;

typedef struct _No
{
    pedido dPedido;
    struct _No *prox;
} No;

typedef No *pNo;

typedef struct _Queue
{
    pNo ini, fim;
} Queue;

typedef Queue *pQueue;

void montaMenu();
void AdicionaPedido(pQueue, int);
void TiraPedido(pQueue);

void enqueue(pQueue f, pedido pPedido)
{
    pNo novo;
    novo = malloc(sizeof(No));
    novo->prox = NULL;
    novo->dPedido = pPedido;
    if (f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    return;
}

pQueue criarQueue(void)
{
    pQueue f;
    f = malloc(sizeof(Queue));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

pedido dequeue(pQueue f)
{
    pNo primeiro = f->ini;

    pedido toRemove;

    if (primeiro != NULL)
    {
        toRemove = primeiro->dPedido;
        f->ini = f->ini->prox;
        if (f->ini == NULL)
            f->fim = NULL;
        free(primeiro);
    }
    return toRemove;
}

int main()
{
    montaMenu();
}

void montaMenu()
{
    char Escolha;
    pQueue pFila = criarQueue();
    int SenhaInicial;

    printf("Digite a senha inicial ");
    scanf("%d", &SenhaInicial);

    do
    {
        printf("O que deseja fazer? \n");
        printf("Adicionar Pedido? (Digite a letra A) \n");
        printf("Chamar Proxima Senha? (Digite a letra P) \n");
        printf("Fechar o sistema? (Digite a letra X)");
        scanf("%c", &Escolha);

        switch (toupper(Escolha))
        {
        case 'A':
            AdicionaPedido(pFila, SenhaInicial);
            printf("Prato adicionado na fila de espera, voltando para o menu \n");
            SenhaInicial++;
            break;
        case 'P':
            TiraPedido(pFila);
            break;
        case 'X':
            exit(0);
            break;
        default:
            break;
        }
    } while (Escolha != 'X');
}

void AdicionaPedido(pQueue fila, int senha)
{

    pedido Pedido;

    printf("Digite o nome da pessoa \n");
    fflush(stdin);
    fgets(Pedido.nome, sizeof(Pedido.nome), stdin);

    printf("Digite o Prato da Pessoa \n");
    fflush(stdin);
    fgets(Pedido.prato, sizeof(Pedido.prato), stdin);

    Pedido.senha = senha;

    enqueue(fila, Pedido);
}

void TiraPedido(pQueue fila)
{

    pedido Pedido = dequeue(fila);

    printf("Senha chamada: %d \n", Pedido.senha);
    printf("Nome: %s", Pedido.nome);
    printf("Prato: %s \n", Pedido.prato);
}