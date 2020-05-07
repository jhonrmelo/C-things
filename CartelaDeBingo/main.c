#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int containsNumber(int *numbersUsed, int numberToVerify);
int getUnusedNumber(int *numbersUsed);

int main()
{
    int cartelaBingo[5][5];

    int *numbersUsed;
    numbersUsed = malloc(sizeof(int) * 25);

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int numberToUse = getUnusedNumber(numbersUsed);
            numbersUsed[i * j] = numberToUse;
            cartelaBingo[i][j] = numberToUse;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", cartelaBingo[i][j]);
        }
        printf("\n");
    }
}

int containsNumber(int *numbersUsed, int numberToVerify)
{
    for (int i = 0; i < 25; i++)
    {
        if (numbersUsed[i] == numberToVerify)
            return 1;
    }
    return 0;
}

int getUnusedNumber(int *numbersUsed)
{

    int randomNumber = rand() % 100;

    if (containsNumber(numbersUsed, randomNumber) == 1)
        getUnusedNumber(numbersUsed);

    return randomNumber;    
}