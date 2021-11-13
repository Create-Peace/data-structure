#include <stdio.h>
#include <string.h>

typedef struct STU {
  char name[20];
  int age;
  char sex;
  char num[20];
} STU;

void outputStuList(STU stu[5]) {
  STU stuMax = stu[0];

  for (int i = 0; i < 5; i++)
  {
    printf("stuMax %s \n", stuMax.name);
    if (strcmp(stuMax.num, stu[i].num)) {
      printf("stu[i] %s \n", stu[i].name);
      stuMax = stu[i];
    }
  }
  printf("学生姓名: %s 学生年龄: %d 学生性别: %c 学生学号: %s\n", stuMax.name, stuMax.age, stuMax.sex, stuMax.num);
  
}

int main(int argc, char const *argv[])
{
  STU stu[5] = {
    {
      "小红",
      14,
      'F',
      "Z1207031"
    },
    {
      "小明",
      18,
      'M',
      "Z1207035"
    },
    {
      "小花",
      13,
      'F',
      "Z1207022"
    },
    {
      "小北",
      13,
      'F',
      "Z1207022"
    },
    {
      "小七",
      13,
      'F',
      "Z1207022"
    }
  };

  outputStuList(stu);

  return 0;
}
