#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _elevator
{
    int floor;
    int lastFloor;

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
int VerifyInsert(pElevator, pElevator);
int VerifyElevatorTransiction(pElevator, pElevator);

int main(void)
{
    int RequestControl = 0;

    pElevator ElevatorA;
    pElevator ElevatorB;

    ElevatorA = malloc(sizeof(elevator));
    ElevatorB = malloc(sizeof(elevator));

    ElevatorA->lastFloor = 0;
    ElevatorB->lastFloor = 0;

    MapFloor ArrayMapFloor[3];
    FillArray(ArrayMapFloor);
    char *Floor;
    Floor = (char *)malloc(sizeof(char) * 2);
    int value = 100;

    do
    {
        printf("Digite os andares 01, 02, 10 ou 20 \n");
        printf("Op%c%co: ", 135, 132);
        fflush(stdin);
        getline(&Floor, &value, stdin);
        ElevatorA->floor = Floor[0] - '0';
        ElevatorB->floor = Floor[1] - '0';

        if (VerifyInsert(ElevatorA, ElevatorB) == 1)
        {
            printf("Op%c%co n%Co permitida, tente novamente \n", 135, 132, 132);
        }
        else if (VerifyElevatorTransiction(ElevatorA, ElevatorB) == 1)
        {
            printf("N%co %c possivel executar duas transi%c%ces no elevador de uma vez, tente novamente \n", 132, 130, 135, 148);
        }
        else
        {
            printf("O elevador A esta no %s \n", GetFloor(ArrayMapFloor, ElevatorA->floor));
            printf("O elevador B esta no %s \n", GetFloor(ArrayMapFloor, ElevatorB->floor));
            ElevatorA->lastFloor = ElevatorA->floor;
            ElevatorB->lastFloor = ElevatorB->floor;
            printf("Deseja Pedir Novamente? (0 = Sim, 1 = N%co) \n", 132);
            printf("Op%c%co: ", 135, 132);
            scanf("%d", &RequestControl);
        }

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

int VerifyInsert(pElevator elavatorA, pElevator elavatorB)
{

    if (elavatorA->floor > 2 || elavatorB->floor > 2)
    {
        return 1;
    }
    return 0;
}

int VerifyElevatorTransiction(pElevator elevatorA, pElevator elevatorB)
{
    if (elevatorA->floor != elevatorA->lastFloor && elevatorB->floor != elevatorB->lastFloor)
    {
        return 1;
    }
    return 0;
}