#include <stdio.h>


int main(int argc, char const *argv[])
{
  char str[] = "Hello";
  char str1[] = "Hello";

  char *p = str1;


  printf("%c \n", *(p + 1));
  return 0;
}