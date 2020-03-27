#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawGraph(int x, int y);

int main()
{
    int x1, x2, y1, y2, deltaX, deltaY, steps, incX, incY;

    printf("Digite x1");
    scanf("%d", &x1);
    printf("Digite x2");
    scanf("%d", &x1);
    printf("Digite y1");
    scanf("%d", &y1);
    printf("Digite y2");
    scanf("%d", &y2);

    deltaX = x2 - x1;
    deltaY = y2 - y1;

    if (abs(deltaX) > abs(deltaY))
        steps = deltaX;
    else
        steps = deltaY;

    incX = deltaX / steps;
    incY = deltaY / steps;

    for (int i = 0; i < steps; i++)
    {
        x1 = round(x1 + incX);
        y1 = round(y1 + incY);
        drawGraph(x1, y1);
    }
}
void drawGraph(int x, int y)
{
    //Insere x e y na matriz, formando a reta
}
