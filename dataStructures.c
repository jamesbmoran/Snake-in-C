#include "snake.h"

extern int size;
extern snake* s;

node* new_node(int x, int y, node* next){
  node* n = malloc(sizeof(node));
  n->x = x;
  n->y = y;
  n->next = next;
  putHead(x,y);
  return n;
}

void delete_Node(node* n){
  putBoard(n->x,n->y);
  free(n);
}

food* new_food(){
  food* f = malloc(sizeof(food));
  int positionNotFound = 1;
  int x;
  int y;
  while(positionNotFound){
    srand(time(NULL));
    x = rand()%size;
    y = rand()%size;
    if(checkSnakeCollision(x,y)){
      positionNotFound = 0;
    }
  }
  f->x = x;
  f->y = y;
  putFood(x, y);
  return f;
}

void delete_food(food* f){
  free(f);
}

snake* make_snake(){
  snake* s = malloc(sizeof(snake));
  s->direction = 2;
  s->xPos = size/2;
  s->yPos = size/2;
  node* head = new_node(size/2,size/2, NULL);
  node* middle = new_node(size/2-1,size/2, head);
  putTail(size/2-1,size/2);
  node* tail = new_node(size/2-2,size/2, middle);
  putTail(size/2-2,size/2);
  s->head = head;
  s->tail = tail;
  return s;
}
