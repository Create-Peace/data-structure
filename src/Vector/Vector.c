#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Vector {
  int * data;
  int size, length;
} Vector;

Vector * init (int n) {
  Vector * v = (Vector *)malloc(sizeof(Vector));

  v->data = (int *)malloc(sizeof(int) * n);
  v->size = n;
  v->length = 0;

  return v;

}

int expand (Vector *v) {
  int ext_size = v->size;
  int *p;

  while(ext_size) {
    p = (int *)(realloc(v->data, sizeof(int) * (v->size + ext_size)));
    if (p != NULL) break;
    ext_size >>= 1;
  }
  if (p == NULL) return 0;
  v->data = p;
  v->size += ext_size;
  return 1;

  v->data = (int *)realloc(v->data, sizeof(int) * (v->size * 2));
  v->size <<= 2;
  return 1;
}


int insert (Vector *v, int index, int val) {
  if (v == NULL) return 0;
  if (v->length == v->size) {
    if(!expand(v)) return 0;
    printf(GREEN("success to expand! the size = %d\n"), v->size);
  }
  if (index < 0 || index > v->length) return 0;

  for (int i = v->length; i > index ; i --) {
    v->data[i] = v->data[i - 1];
  }

  v->data[index] = val;
  v->length += 1;

  return 1;
}

int erase (Vector *v, int index) {
  if (v == NULL) return 0;
  if (index< 0 || index >= v->length) return 0;
  for (int i = index + 1; i < v->length; i++) {
    v->data[i - 1] = v->data[i];
  }

  v->length -= 1;
  return 1;
}

void clear (Vector *v) {
  if (v == NULL) return;
  free(v->data);
  free(v);
  return;

}

void output (Vector *v) {

  if (v == NULL) return;
  printf("Vector: [");
  for (int i = 0; i < v->length; i++)
  {
    i && printf(" ");
    printf("%d", v->data[i]);
  }
  printf("]\n");
  return;
}



int main () {
  srand(time(0));
  #define MAX_OP 20
  #define SPACE_SIZE 1
  Vector *v = init(SPACE_SIZE);
for (int i = 0; i < MAX_OP; i++) {
  int op = rand() % 4;
  int index = rand() % (v->length + 3) - 1;

  switch (op)
  {
    case 0:
    case 1:
    case 2: {
      int val = rand() % 100;
      printf("insert %d at %d to Vector = %d\n",val, index, insert(v, index, val));
      break;
    }
    case 3: {
      printf("erase item at %d from Vector = %d\n", index, erase(v, index));
      break;
    }
  }
  output(v), printf("\n");
}

  #undef MAX_OP
  return 0;
}