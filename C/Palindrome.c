#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
  
  char str[100] = {0}, *p = str, *q;

  gets(p);

  q = p + strlen(str) - 1;

  while(p != q) {
    if (*p == *q) {
      p++, q--;
    } else {
      break;
    }
  }

  if (p < q) {
    printf("该字符串不是回文的！\n");
  } else {
    printf("这是一个回文串！\n");
  }


  return 0;
}
