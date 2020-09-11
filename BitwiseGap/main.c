#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMax(int number, int numberToCompare);

int main()
{

    int number = 0;
    scanf("%d", &number);
    int aux = 0;

    aux = number;

    //We are doing this to avoid the 0 trailing, i mean if we have 10010000000000000 our answer is 2 and the first zeros are useless
    while (aux > 0 && (aux & 1) == 0)
        aux >>= 1;

    //We can do 1 more time
    aux >>= 1;

    int max = 0;
    int zeros = 0;

    while (aux > 0)
    {
        if ((aux & 1) == 0)
        {
            zeros++;
        }
        else
        {
            max = getMax(max, zeros);
            zeros = 0;
        }
        aux >>= 1;
    }

    printf("%d", max);
}

int getMax(int number, int numberToCompare)
{
    if (number > numberToCompare)
        return number;

    return numberToCompare;
}