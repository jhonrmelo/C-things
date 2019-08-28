#include <stdio.h>
#include <stdlib.h>


void avg_sum();
int main()
{
    int qtd = 0;
    printf("Digite a quantidade: ");
    scanf("%d", &qtd);
    int i = 0;
    double * array;
    array = (double*) malloc(sizeof(double)* qtd);

    for(i = 0; i < qtd; i++){
        printf("Digite o valor do array[%d]", i);
        scanf("%lf", &array[i]);
    }

    double avg = 0.0;
    double sum = 0.0;
    avg_sum(array,&avg,&sum, qtd);

    printf("Media: %.2lf , Soma: %.0lf", avg,sum );

}

void avg_sum(double* array, double *avg, double *sum, int qtd){
  int i =0;

  for(i = 0; i <  qtd; i++){
    *sum = *sum + array[i];
  }

  *avg = *sum/qtd;
}
