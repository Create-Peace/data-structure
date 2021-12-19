#include <stdio.h>

int main(int argc, char const *argv[])
{
  char ch = 108;

  ch = ch & 24;

  printf("%d \n", ch);
  return 0;
}
