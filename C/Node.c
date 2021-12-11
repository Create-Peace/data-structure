#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
  int data;
  struct Node * next;
} Node;


int main(int argc, char const *argv[])
{
   Node node = {
     0
   };
   Node node1 = {
     1,
     &node
   };
   Node *node2 = (Node *)malloc(sizeof(Node));
   node2->data = 2;
   node2->next = &node;
  
  printf("%d %d\n", node1.data, node1.next->data);
  
  return 0;
}
