#include <stdio.h>

struct MinMax{
  int min,max;
};

struct MinMax minMax( int array[],  int inicio, int fim)
{
    struct MinMax resultado, esquerda, direita;
    int meio;

    if(inicio == fim)
    {
      resultado.min = array[fim];
      resultado.max = array[fim];
      return resultado;
    }

    if(fim  == inicio + 1)
    {
      if(array[inicio] > array[fim])
      {
        resultado.min = array[fim];
        resultado.max = array[inicio];
      }else
      {
        resultado.min = array[inicio];
        resultado.max = array[fim];
      }

      return resultado;
    }

    meio = (inicio + fim) / 2;
    esquerda = minMax(array, inicio, meio);
    direita = minMax(array, meio + 1, fim);

    if(esquerda.min < direita.min) resultado.min = esquerda.min;
    else resultado.min = direita.min;

    if(esquerda.max > direita.max) resultado.max = esquerda.max;
    else resultado.max = direita.max;

    return resultado;
}

int main(void)
{
  int tam; 
  struct MinMax resultado;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam);

  int vetor[tam];

  printf("Digite os números: ");
  for(int i = 0; i < tam; i++)
  {
    scanf("%d", &vetor[i]);
  }

  resultado = minMax(vetor, 0, tam -1);

  printf("Maior: %d\n", resultado.max);
  printf("Menor: %d", resultado.min);
  
  
  return 0;
}