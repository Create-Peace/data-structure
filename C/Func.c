#include<stdio.h>

void func (int n) {
  int i = n / 10;

  if (i) {
    func(i);
  }
  putchar(n % 10 + '0');
}


int main(int argc, char const *argv[])
{
  int n;
  while(~scanf("%d", &n)) {
    printf("func");
    func(n);

    printf("\n");

  }
  return 0;
}
