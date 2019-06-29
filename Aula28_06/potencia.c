#include <stdio.h>
#include <stdlib.h>

int Potencia(int a, int n){
  if (n == 0) return 1;
  else return  a * Potencia(a, n-1);
}


int main(void) {
  int a;
  int n;

  scanf("%d", &a);
  scanf("%d", &n);
  printf("%d", Potencia(a,n));


  return 0;
}
