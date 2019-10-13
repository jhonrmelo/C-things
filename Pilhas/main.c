#include <stdlib.h>
#include <stdio.h>

#define INT_MIN -2147483648
typedef struct _No
{
    double dado;
    struct _No *prox;
} No;
typedef No *pNo;

typedef struct _Stack
{
    pNo topo;
} Stack;

typedef Stack *pStack;

pStack criarStack(void)
{
    pStack novo;
    novo = malloc(sizeof(Stack));
    novo->topo = NULL;
    return novo;
}

void push(pStack s, double x)
{
    pNo novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = s->topo;
    s->topo = novo;
    return;
}

double pop(pStack s)
{
    pNo topo = s->topo;
    double x;
    if (topo != NULL)
    {
        x = topo->dado;
        s->topo = s->topo->prox;
        free(topo);
    }
    else
    {
        x = INT_MIN;
    }

    return x;
}

int main()
{
    pStack pilha = criarStack();
    char exp[100];
    printf("Digite  expressao");
    gets(exp);
    double result;
    double value1;
    double value2;
    int iterador = 0;
    while (exp[iterador] != '\0')
    {
        if (exp[iterador] == '+' || exp[iterador] == '-' || exp[iterador] == '*' || exp[iterador] == '/')
        {
            if (exp[iterador] == '+')
            {
                value1 = pop(pilha);
                value2 = pop(pilha);
                result = value1 + value2;
                push(pilha, result);
            }
            else if (exp[iterador] == '-')
            {
                value1 = pop(pilha);
                value2 = pop(pilha);
                result = value2 - value1;
                push(pilha, result);
            }
            else if (exp[iterador] == '*')
            {
                value1 = pop(pilha);
                value2 = pop(pilha);
                result = value2 * value1;
                push(pilha, result);
            }
            else if (exp[iterador] == '/')
            {
                value1 = pop(pilha);
                value2 = pop(pilha);
                result = value2 / value1;
                push(pilha, result);
            }
        }
        else if (exp[iterador] != ' ')
        {           
            result = atof(&exp[iterador]);
            push(pilha, result);
        }
        iterador++;
    }
    result = pop(pilha);

    printf("Resultado : %.2f", result);
}
