#include <stdio.h>

// 通过指针改变数组的内容
void changeChar (char b[]) {
  printf("changeeStr:%s \n", b);
  b = "world";
  printf("changeeStr:%s \n", b);
}


int main(int argc, char const *argv[])
{
  char str[] = "Hello world fsdjflsjflsj";
  char str1[] = "Hello";
  char *p = str1;

  printf("%c \n", *(p + 1));
  printf("%lu\n", sizeof(str));

  char changingChar[10] = "hello";
  changeChar(changingChar);

  printf("%s\n", changingChar);
  return 0;
}