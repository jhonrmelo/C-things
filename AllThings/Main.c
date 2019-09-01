#include <stdio.h>
#include <stdlib.h>

//Criação da struct pessoa
typedef struct _pessoa
{
    char Nome[50];
    int Idade;
    char Endereco[200];
    char CPF[20];
    char Numero[100];
    double Salario;

} pessoa;
typedef struct _linkedlist
{
    int value;
    struct _linkedlist *pLigacao;
} linkedList;

//Criação da struct valores
typedef struct _valores
{
    double Media;
    double Min;
    double Max;
    double Soma;
} valores;

void ReadAndPrintStruct();
void PointerWithStructAndDynamicAllocation();
void CalculaValores();
void LinkedList();
void DisplayLinkedList();
void menu();

int main()
{
    menu();
}

void menu()
{
    int Option = 0;
    printf("Ol%c, esse %c um projeto onde vou tentar colocar todas as materias do Semestre, o que deseja aprender?", 160, 130);
    printf("\n0 - Cria%c%co e uso de struct", 135, 198);
    printf("\n1 - Uso de Ponteiros");
    printf("\n2- Uso de Lista Encadeada");

    printf("\nEscolha: ");
    scanf("%d", &Option);
    switch (Option)
    {
    case 0:
        ReadAndPrintStruct();
        break;
    case 1:
        PointerWithStructAndDynamicAllocation();
        break;
    case 2:
        LinkedList();
        break;
    default:
        break;
    }
}

//Metodo que cria, lê e printa na tela dados de uma struct
void ReadAndPrintStruct()
{
    //Declaração da struct
    pessoa sPessoa;

    //Leitura do nome da pessoa, é usado o fgets para ler strings com espaço
    printf("Digite o nome da pessoa \n");
    fflush(stdin);
    fgets(sPessoa.Nome, sizeof(sPessoa.Nome), stdin);

    //Leitura da idade da pessoa
    printf("Legal! o nome digitado foi %s, agora digite a idade dela: \n", sPessoa.Nome);
    scanf("%d", &sPessoa.Idade);

    //Leitura do endereço da pessoa, também é usado o fgets
    printf("Ok, agora vamos para o endere%co: ", 135);
    fflush(stdin);
    fgets(sPessoa.Endereco, sizeof(sPessoa.Endereco), stdin);

    //Leitura do cpf
    printf("Agora o cpf: \n");
    fflush(stdin);
    fgets(sPessoa.CPF, sizeof(sPessoa.CPF), stdin);

    //Leitura do numero
    printf("O numero de telefone por favor, use esse padr%co: (DD) + 9 + NUMERO: \n", 198);
    scanf("%s", &sPessoa.Numero);

    //Leitura do salário
    printf("Ultimo registro, digite o sal%crio da pessoa:  \n", 160);
    scanf("%lf", &sPessoa.Salario);
    //Daqui pra baixo apenas é exibido os dados digitados
    printf("Ok, o que voc%c digitou foi : \n", 136);

    printf("Nome : %s \n", sPessoa.Nome);

    printf("Idade: %d \n", sPessoa.Idade);

    printf("Endereco: %s\n", sPessoa.Endereco);

    printf("CPF: %d \n", sPessoa.CPF);

    printf("Telefone: %s\n", sPessoa.Numero);

    printf("Salario: %0.lf \n", sPessoa.Salario);

    //Chama o menu principal de novo
    menu();
}

//Nesse metodo é usado alocação dinamica, ponteiros, struct e mudança de dados por referência
void PointerWithStructAndDynamicAllocation()
{
    //Instancia a struct valores no metodo
    valores _valores;

    //Cria um ponteiro da struct valores
    valores *pValores = &_valores;

    int qtd, i;
    double *NumbersArray;

    printf("Digite a quantidade de numeros para fazermos as contas \n ");
    scanf("%d", &qtd);

    //Alocação dinamica do vetor
    NumbersArray = (double *)malloc(sizeof(double) * qtd);

    for (i = 0; i < qtd; i++)
    {
        printf("Digite o numero que ocupar%c a posicao %d \n ", 160, i);
        scanf("%lf", &NumbersArray[i]);
    }
    //Chama o metodo para calcular os valores lidos passando o ponteiro da struct
    CalculaValores(pValores, NumbersArray, qtd);

    //Mostra os valores na tela
    printf("Soma :  %1.lf \n", _valores.Soma);
    printf("Media : %1.lf \n", _valores.Media);
    printf("Minimo: %1.lf \n", _valores.Min);
    printf("Maximo: %1.lf \n", _valores.Max);

    menu();
}
//Metodo que utiliza encadeamento de ponteiros para criar uma lista e percorrer todos
void LinkedList()
{
    //Declaração das variaveis
    linkedList *list1 = NULL;
    linkedList *list2 = NULL;
    linkedList *list3 = NULL;

    //Definição de valores e alocação de memória
    list1 = (linkedList *)malloc(sizeof(linkedList *));
    list1->value = 10;

    list2 = (linkedList *)malloc(sizeof(linkedList *));
    list2->value = 20;

    list3 = (linkedList *)malloc(sizeof(linkedList *));
    list3->value = 30;

    //Criação das ligações entre ponteiros
    list1->pLigacao = list2;
    list2->pLigacao = list3;
    list3->pLigacao = NULL;

    //Metodo para percorrer a lista de ponteiros
    DisplayLinkedList(list1);
}

void DisplayLinkedList(linkedList *_linkedlist)
{
    do
    {
        printf("%d \n", _linkedlist->value);
        _linkedlist = _linkedlist->pLigacao;
    } while (_linkedlist != NULL);

    printf("Todos os valores foram mostrados");
}

//Metodos para calcular os valores e colocar na struct
void CalculaValores(valores *pValores, double *array, int qtd)
{
    int i = 0;

    pValores->Max = array[0];
    pValores->Min = array[0];
    pValores->Soma = 0;

    for (i = 0; i < qtd; i++)
    {
        if (pValores->Max < array[i])
        {
            pValores->Max = array[i];
        }
        if (pValores->Min > array[i])
        {
            pValores->Min = array[i];
        }
        pValores->Soma = pValores->Soma + array[i];
    }

    pValores->Media = pValores->Soma / qtd;
}
