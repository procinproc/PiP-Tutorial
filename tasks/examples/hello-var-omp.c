#include <stdio.h>
int x;
int main() {
  #pragma omp parallel
  printf( "Hello World (&x:%p)\n", &x );
  return 0;
}
