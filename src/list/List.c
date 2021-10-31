#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct List
{
  Node head; // 虚拟头节点
  int length;
} List;

Node *getNewNode (int);
List *initList ();
void clearNode (Node *);
// void clear(List *);
void clearList (List *);
int insert (List *, int, int);
int erase (List *, int);


Node *getNewNode (int val) {
   Node *p = (Node *)malloc(sizeof(Node));
   p->data = val;
   p->next = NULL;
   return p;
}

List *initList () {
  List *l = (List *)malloc(sizeof(List));
  l->head.next = NULL;
  l->length = 0;
  return l;
}

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

int erase (List *l, int index) {
  if (l == NULL) return 0;
  if (index < 0 || index > l->length) return 0;
  Node *p = &(l->head), *q;
  while(index--) p = p->next;
  q = p->next;
  p->next = q->next;
  clearNode(q);
  l->length -= 1;
  return 1;
}

void clearNode (Node *node) {
  if (node == NULL) return;
  free(node);
  return;
}

void clearList(List *l) {
  if (l == NULL) return;
  Node *p = l->head.next, *q;
  while (p != NULL) {
    q = p->next;
    clearNode(p);
    p = q;
  }
  free(l);
  return;
}

/* void clear(List *l) {
    if (l == NULL) return ;
    Node *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clearNode(p);
        p = q;
    }
    free(l);
    return ;
} */

void output(List *l) {
  if (l == NULL) return;
  printf("list(%d): ", l->length);
  for (Node *p = l->head.next; p != NULL; p = p->next)
  {
    printf("%d->", p->data);
  }
  printf("NULL\n");
  return;
}


int main()
{
  srand(time(0));
  #define MAX_OP 20

  List *l = initList();

  for (int i = 0; i < MAX_OP; i++)
  {
    int op = rand() % 4;
    int val = rand() % 100;
    int index = rand() % (l->length + 3) - 1;
    switch (op)
    {
    case 0:
    case 1:
    case 2:
      printf("insert %d at %d to list = %d\n", val, index, insert(l, index, val));
      break;
    
    default:
      printf("erase a item at %d from list = %d\n", index, erase(l, index));
      break;
    }
     output(l), printf("\n");
  }
  clearList(l);
  #undef MAX_OP
  return 0;
}