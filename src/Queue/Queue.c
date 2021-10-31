#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue
{
  int length;
  int *data;
  int head;
  int tail;
} Queue;

Queue *initQueue (int n) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->data = (int *)malloc(sizeof(int) * n);
  q->length = n;
  q->head = 0;
  q->tail = 0;
  return q;
}

void clear (Queue *q) {
  if (q == NULL) return;
  free(q->data);
  free(q);
  return;
}

int empty (Queue *q) {
  return q->head == q->tail;
}

int front (Queue *q) {
  return q->data[q->head];
}

int push(Queue *q, int val) {
  if (q == NULL) return 0;
  if (q->head == q->length) return 0;
  q->data[q->tail] = val;
  q->tail += 1;
  return 1;
}

int pop (Queue *q) {
  if (q == NULL) return 0;
  if (q->head == q->tail) return 0;
  q->head += 1;
  return 1;
}

void output (Queue *q) {
  printf("Queue: [");
  for (int i = q->head; i < q->tail; i++)
  {
    printf("%d ", q->data[i]);
  }
  printf("]\n");
}



int main(int argc, char const *argv[])
{
  #define MAX_OP 20

  Queue *q = initQueue(MAX_OP);

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
    default:
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
