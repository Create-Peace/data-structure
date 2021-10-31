#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LoopQueue
{
  int *data;
  int count;
  int length;
  int head;
  int tail;
} LoopQueue;

LoopQueue *initLoopQueue (int n) {
  LoopQueue *q = (LoopQueue *)malloc(sizeof(LoopQueue));
  q->data = (int *)malloc(sizeof(int) * n);
  q->head = 0;
  q->tail = 0;
  q->count = 0;
  q->length = n;
  return q;
}

int empty (LoopQueue *q) {
  return q->count == 0;
}

int front (LoopQueue *q) {
  return q->data[q->head];
}

int expand (LoopQueue *q) {
  int extSize = q->length;
  int *tmp;

  while (extSize) {
    tmp = (int *)malloc(sizeof(int) * (extSize + q->length));
    if (tmp != NULL) break;
    extSize >>= 1;
  }

  if (tmp == NULL) return 0;

  for (int i = q->head, j = 0; j < q->count; j++)
  {
    tmp[j] = q->data[(i + j) % q->length];
  }

  free(q->data);
  q->data = tmp;
  q->head = 0, q->tail = q->count;
  q->length += extSize;
  return 1;
}

int push (LoopQueue *q, int val) {
  if (q == NULL) return 0;
  if (q->count == q->length) {
    if (!expand(q)) return 0;
  }
  q->data[q->tail++] = val;
  if (q->tail == q->length) q->tail = 0;
  q->count += 1;
  return 1;
}

int pop (LoopQueue *q) {
  if (q == NULL) return 0;
  if (empty(q)) return 0;
  q->head += 1;
  if (q->head == q->length) q->head = 0;
  q->count -= 1;
  return 1;
}

void output (LoopQueue *q) {
  printf("Queue: [");
  for (int i = q->head, j = 0; j < q->count; j++)
  {
    printf("%d ", q->data[(i + j) % q->length]);
  }
  printf("]\n");
}




int main(int argc, char const *argv[])
{
  #define MAX_OP 30

  LoopQueue *q = initLoopQueue(10);

  for (int i = 0; i < MAX_OP; i++)
  {
    int op = rand() % 4;
    int val = rand() % 100;
    switch (op)
    {
    case 0:
    case 1:
    case 2:
      printf("push %d to Queue=%d", val, push(q, val));
      break;
    case 3:
      if (empty(q)) {
        printf("fail to pop a item\n");

      }
      printf("Success Pop a item from %d", front(q));
      pop(q);
      break;
    }
    output(q), printf("\n");
  }
  return 0;
}
