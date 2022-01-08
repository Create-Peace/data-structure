#include<iostream>
#include<cstring>
// 通过指针改变数组的内容
// 为什么不能改变呢？
void changeChar (char b[]) {
  printf("changeeStr:%s \n", b);
  strcpy(b, "world");
  printf("changeeStr:%s \n", b);
}

void changeValue (int *p) {
  *p = 123;
}


int main(int argc, char const *argv[])
{

  char changingChar[10] = "hello";
  changeChar(changingChar);

  int i = 1;
  changeValue(&i);

  printf("%d \n", i);

  printf("%s\n", changingChar);
  return 0;
}