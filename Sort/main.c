#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _message
{
    int index;
    char strMessage[8];
} message;

typedef message *pMessage;

void sort(pMessage, int);
void changePlace(pMessage array, int j, int nextJ);

int main(void)
{
    message ArrayMessage[100];
    int number = 1;
    int auxIterador = 0;
    while (number > 0)
    {
        scanf("%d", &number);
        if (number > 0)
        {
            ArrayMessage[auxIterador].index = number;
            gets(ArrayMessage[auxIterador].strMessage);
            auxIterador++;
        }
    }
    sort(ArrayMessage, auxIterador);
    for (int i = 0; i < auxIterador; i++)
    {
        printf("%s", ArrayMessage[i].strMessage);
    }
}

void sort(pMessage arrayMessage, int size)
{
    int i, j;
    for (i = 0; i <= size - 1; i++)
    {
        for (j = 0; j <= size - i - 1; j++)
        {
            if (arrayMessage[j].index > arrayMessage[j + 1].index)
            {
               changePlace(arrayMessage, j, j+1);
            }
        }
    }
}

void changePlace(pMessage array, int j, int nextJ)
{
    message temp = array[j];
    array[j] = array[j + 1];
    array[j + 1] = temp;
}
