#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _elevator
{
    int floor;

} elevator;

typedef struct _MapFloor
{
    int FloorNumber;
    char FloorName[50];
} MapFloor;

typedef MapFloor *pMapFloor;

typedef elevator *pElevator;

char *GetFloor(MapFloor *, int floor);
void FillArray(MapFloor *);

int main(void)
{
    int RequestControl = 0;
    pElevator ElevatorA;
    pElevator ElevatorB;
    MapFloor ArrayMapFloor[3];
    FillArray(ArrayMapFloor);
     char Floor[2];

    do
    {
        printf("Digite os andares 01, 02, 10 ou 20");
        gets(Floor);
        printf("GotHere");
        char teste = Floor[0];
        int teste2 = atoi(Floor[0]);
        ElevatorA->floor = atoi(Floor[0]);
        ElevatorB->floor = atoi(Floor[1]);

        printf("O elevador A esta no %s \n ", GetFloor(ArrayMapFloor, ElevatorA->floor));
        printf("O elevador A esta no %s \n ", GetFloor(ArrayMapFloor, ElevatorB->floor));

        printf("Deseja Pedir Novamente? (0 = Sim, 1 = Não)");
        scanf("%d",&RequestControl);

    } while (RequestControl == 0);
}

void FillArray(pMapFloor mapFloor)
{
    strcpy(mapFloor[0].FloorName, "Terreo");
    mapFloor[0].FloorNumber = 0;
    strcpy(mapFloor[1].FloorName, "Primeiro");
    mapFloor[1].FloorNumber = 1;
    strcpy(mapFloor[2].FloorName, "Segundo");
    mapFloor[2].FloorNumber = 2;
}

char *GetFloor(pMapFloor mapFloor, int floor)
{
    for (int i = 0; i < 3; i++)
    {
        if (mapFloor[i].FloorNumber == floor)
        {
            return mapFloor[i].FloorName;
        }
    }
}
