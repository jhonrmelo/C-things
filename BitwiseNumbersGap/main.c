#include <stdio.h>
#include <stdlib.h>

int betterSolution(int x, int y);
int getMostSignificantBitPosition(int x);

int main()
{
    int number1;
    int number2;

    printf("Put the first number");
    scanf("%d", &number1);

    printf("Put the second number");
    scanf("%d", &number2);

    betterSolution(number1, number2);
    
    // int gap = 0;
    // gap = number1;

    // for (int i = number1; i < number2; i++)
    // {
    //     gap = gap & i + 1;
    // }

    // printf("%d", gap);
}

int betterSolution(int x, int y)
{
    int number = 0;

    while (x && y)
    {
        int msbPosX = getMostSignificantBitPosition(x);
        int msbPosY = getMostSignificantBitPosition(x);
        if (msbPosX != msbPosY)
        {
            break;
        }
        int msbValue = (1 << msbPosX);
        number = number + msbValue;

        x = x - msbValue;
        y = y - msbValue;
    }

    printf("%d", number);
}

int getMostSignificantBitPosition(int x)
{
    int msbPosition = -1;

    while (x)
    {
        x = x >> 1;
        msbPosition++;
    }
    return msbPosition;
}