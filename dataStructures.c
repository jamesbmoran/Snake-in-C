#include "snake.h"

extern int size;

node* new_node(int x, int y, node* next){
  node* n = malloc(sizeof(node));
  n->x = x;
  n->y = y;
  n->next = next;
  putTail(x,y);
  return n;
}

void delete_Node(node* n){
  putBoard(n->x,n->y);
  free(n);
}

snake make_snake(){
  snake s;
  s.direction = 0;
  s.xPos = size/2;
  s.yPos = size/2;
  node* head = new_node(size/2-2,size/2, NULL);
  node* middle = new_node(size/2-1,size/2, head);
  node* tail = new_node(size/2,size/2, middle);
  s.head = head;
  s.tail = tail;
  return s;
}
