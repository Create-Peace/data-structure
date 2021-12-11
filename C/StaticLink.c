#include <stdio.h>
#define MAX_SIZE 20

typedef struct
{
  int data; // 静态链表节点的数据
  int cur; // 静态链表的游标
} component;

/*
备用链表
*/
void reverseArray(component *array) {
  for (int i = 0; i < MAX_SIZE; i++)
  {
    array[i].cur = i + 1;
  }
  array[MAX_SIZE - 1].cur = 0;
}

/* 
提取分配空间
若备用链表为非空，则返回分配的节点下标，否则返回0(当分配最后一个节点时，该节点的游标值为0)
 */

int mallocArr (component *array) {
  int i = array[0].cur;
  printf("mallocArr: %d\n", i);
  if (array[0].cur) {
    array[0].cur = array[i].cur;
  } 
  return i;
}
/* 初始化静态链表 */
int initArr(component *array) {
  int tempBody = 0, body = 0;

  int i = 0;

  reverseArray(array);

  body = mallocArr(array);

  printf("initArr: %d\n", body);

  // 建立首元节点
  array[body].data = 1;
  array[body].cur = 0;

  // 声明一个变量，把它当指针使，指向链表的最后一个节点，当前和首元节点重合
  tempBody = body;

  for ( i = 2; i < 4; i++)
  {
    int j = mallocArr(array); // 从备用链表中拿出空间的分量
    array[j].data = i; // 初始化新得到的节点
    array[tempBody].cur = j; // 将新得到的节点链接到数据链表的尾部
    tempBody = j; // 将指向链表最后一个节点的指针后移
  }

  array[tempBody].cur = 0; // 新的链表最后一个节点的指针设置为0
  return body;
}

void displayArr(component *array, int body) {
  int tempBody = body; // tempBody 准备做遍历使用

  while (array[tempBody].cur)
  {
    printf("%d, %d\n", array[tempBody].data, array[tempBody].cur);
    tempBody = array[tempBody].cur;
  }

  printf("displayArr tempBody: %d, %d \n", array[tempBody].data, array[tempBody].cur);
  
}

//向链表中插入数据，body表示链表的头结点在数组中的位置，add表示插入元素的位置，num表示要插入的数据
void insertArr(component * array, int body, int add, int num) {
    int tempBody = body;//tempBody做遍历结构体数组使用
    printf("insertArr1: %d\n", tempBody);
    int i = 0, insert = 0;
    //找到要插入位置的上一个结点在数组中的位置
    for (i = 1; i < add; i++) {
        tempBody = array[tempBody].cur;
    }
    printf("insertArr2: %d\n", tempBody);

    insert = mallocArr(array);//申请空间，准备插入

    printf("insertArr2: %d\n", insert);
    array[insert].data = num;
    array[insert].cur = array[tempBody].cur;//新插入结点的游标等于其直接前驱结点的游标
    array[tempBody].cur = insert;//直接前驱结点的游标等于新插入结点所在数组中的下标
}

//删除结点函数，num表示被删除结点中数据域存放的数据，函数返回新数据链表的表头位置
int deletArr(component * array, int body, int num) {
    int tempBody = body;
    int del = 0;
    int newbody = 0;
    //找到被删除结点的位置
    while (array[tempBody].data != num) {
        tempBody = array[tempBody].cur;
        //当tempBody为0时，表示链表遍历结束，说明链表中没有存储该数据的结点
        if (tempBody == 0) {
            printf("链表中没有此数据");
            return;
        }
    }
    //运行到此，证明有该结点
    del = tempBody;
    tempBody = body;
    //删除首元结点，需要特殊考虑
    if (del == body) {
        newbody = array[del].cur;
        freeArr(array, del);
        return newbody;
    }
    else
    {
        //找到该结点的上一个结点，做删除操作
        while (array[tempBody].cur != del) {
            tempBody = array[tempBody].cur;
        }
        //将被删除结点的游标直接给被删除结点的上一个结点
        array[tempBody].cur = array[del].cur;
        //回收被摘除节点的空间
        freeArr(array, del);
        return body;
    }  
}

//备用链表回收空间的函数，其中array为存储数据的数组，k表示未使用节点所在数组的下标
void freeArr(component * array, int k) {
    array[k].cur = array[0].cur;
    array[0].cur = k;
}



int main(int argc, char const *argv[])
{
  component array[MAX_SIZE];
  int body = initArr(array);
  printf("body: %d\n", body);
  printf("静态链表为：\n");
  displayArr(array, body);
  insertArr(array, body, 1, 6);
  displayArr(array, body);

  printf("%d, %d\n", array[1].data, array[1].cur);

  return 0;
}
