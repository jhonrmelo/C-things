#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    int aux = 0;
    printf("Input the number:");
    scanf("%d", &number);

    number = abs(number);

    for (int i = 0; i < number; i)
    {
        i = i + 2;
        aux = i;
    }

    if (aux == number)
        printf("The number is even!");
    else
        printf("The number is odd!");
}