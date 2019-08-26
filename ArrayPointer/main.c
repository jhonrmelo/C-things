#include <stdio.h>
#include <stdlib.h>


void min_max();
int main()
{
    int qtd = 0;
    printf("Digite a quantidade: ");
    scanf("%d", &qtd);
    int i = 0;
    int * array;
    array = (int*) malloc(sizeof(int)* qtd);
    for(i = 0; i < qtd; i++){
        printf("Digite o valor do array[%d]", i);
        scanf("%d", &array[i]);
    }
    int max = array[0];
    int min = array[0];
    min_max(array,&min,&max, qtd);
    printf("MIN: %d ; MAX : %d", min,max);

}

void min_max(int* array, int * min, int * max, int qtd){
  int i =0;

  for(i = 0; i <  qtd; i++){
        if(array[i] > *max){
            *max = array[i];
        }
        if(array[i] < *min){
            *min = array[i];
        }
  }
}
