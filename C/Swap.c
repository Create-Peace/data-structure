#include<stdio.h>

void swap (int * a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

int main(int argc, char const *argv[])
{
  int a = 3, b = 5;
  swap(&a, &b);

  printf("a = %d, b = %d \n", a, b);

  return 0;
}
