
### 重点记忆：

```C++
int insert (List *l, int index, int val) {
  if (l == NULL) return 0;
  if (index < 0 || index > l->length) return 0;
  Node *p = &(l->head), *node = getNewNode(val); 
  while (index--) p = p->next;
  node->next = p->next;
  p->next = node;
  l->length += 1;
  return 1;
}
```

### 重点理解reverse（原地反转）
```C++
  Node *p = l->header.next, *q;
  l->header.next = NULL;

  while (p != NULL) {
    q = p->next;
    p->next = l->head.next;
    l->head.next = p;
    p = q;
  }
```


- Node *p = &(l->head); => Node *p; p = &(l->head);

指针的声明 `int * p`; 
指针的赋值 `p = &x`;

指针中一定存放的地址，给指针赋值，其实就是给这个指针所指向的地址赋值。
