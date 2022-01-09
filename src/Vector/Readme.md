### 顺序表

1. 静态数组的方式
```c++
#define  MAXSIZE 100;
typedef struct {
  ElemType elem[MAXSIZE];
  int length;
} Vector;
```

2. 动态数组的方式
```c++
typedef struct {
  ElemType *elem;
  int length; // 顺序表中有效值的个数
  int size; // 顺序表的总长度
} Vector;

Vector * init (int n) {
  Vector v;
  v->elem = (ElemType *)malloc(sizeof(ElemType) * n);
  v->size = n;
  v->length = 0;
  return v;
}


```