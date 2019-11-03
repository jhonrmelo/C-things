#include <stdio.h>
#include <stdlib.h>

typedef struct _message
{
    int index;
    char strMessage[100];
} message;

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
}