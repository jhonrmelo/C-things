#include <stdio.h>
#include <stdlib.h>

typedef struct _item
{
    int peso;
    int valor;

} item;

typedef item *pItem;

double MochilaFracionaria(pItem itens, int capacidade, int countItens);
void swap(pItem itens, int PosicaoA, int PosicaoB);
void SortItens(pItem itens, int count);

int main(void)
{
    int n = 0;
    int qtd = 0;
    pItem itens;

    printf("Digite a capacidade da mochila:");
    scanf("%d", &qtd);

    printf("Digite a quantidade de itens: ");
    scanf("%d", &n);

    itens = malloc((sizeof(item)) * n);

    for (int i = 0; i < n; i++)
    {
        item item;
        printf("Digite o peso do item %d:  ", i);
        scanf("%d", &item.peso);

        printf("Digite o valor do item %d:  ", i);
        scanf("%d", &item.valor);

        itens[i] = item;
    }
    double value = 0;
    value = MochilaFracionaria(itens, qtd, n);

    printf(" Valor maximo de itens: %.2f", value);
}

double MochilaFracionaria(pItem itens, int capacidade, int countItens)
{
    //Temos que arrumar os itens em ordem crescente
    SortItens(itens, countItens);
    int pesoAtual = 0;
    double value = 0.0;

    //Percorre todos os itens
    for (int i = 0; i < countItens; i++)
    {
        //Se ainda houver espaço na mochila, adiciona o item
        if (pesoAtual + itens[i].peso <= capacidade)
        {

            pesoAtual += itens[i].peso;
            value = value + itens[i].valor;
        }
        // Se não, faz o calculo para adicionar somente uma fração do ultimo item, baseado no peso restante da mochila
        else
        {
            int restante = capacidade - pesoAtual;
            value = value + (itens[i].valor * ((double)restante / (double)itens[i].peso));
            break;
        }
    }

    return value;
}

void SortItens(pItem itens, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; i++)
        {
            double DivisaoItem1 = itens[j].peso / itens[j].valor;
            double DivisaoItem2 = itens[j + 1].peso / itens[j + 1].valor;
            if (DivisaoItem1 > DivisaoItem2)
            {
                swap(itens, j, j + 1);
            }
        }
    }
}

void swap(pItem itens, int PosicaoA, int PosicaoB)
{
    item temp = itens[PosicaoB];
    itens[PosicaoB] = itens[PosicaoA];
    itens[PosicaoA] = temp;
}
