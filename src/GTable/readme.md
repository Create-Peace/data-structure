### 广义表 Generalized table


- 广义表，又称列表，也是一种线性存储结构。

**强调一下，除非广义表为空表，否则广义表一定具有表头和表尾，且广义表的表尾一定是一个广义表**

```C++
typedef enum {ATOM, LIST} ElemTag; /* ATOM=0，表示原子；LIST=1，表示子表*/
typedef struct GLNode
{
ElemTag tag; /*标志位tag用来区别原子结点和表结点*/
union {
  AtomType atom; /*原子结点的值域atom*/
  struct { struct GLNode * hp, *tp;} htp; /*表结点的指针域htp， 包括表头指针域hp和表尾指针域tp*/
  } atom_htp; /* atom_htp 是原子结点的值域atom和表结点的指针域htp的联合体域*/
} *GList；
```