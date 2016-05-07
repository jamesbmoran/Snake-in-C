#include "snake.h"

int size = 25;
char board[25][25];
int gameNotOver = 1;

int main(){
  initialiseBoard();

  snake sMan = make_snake();

  while(gameNotOver){
    printBoard();
    Sleep(1000); // Sleep(1000) - Windows // sleep(1) - Linux and Mac
    moveSnake(&sMan);
  }
  return 0;
}

void initialiseBoard(){
  for(int y = 0; y < size; y++){
    for(int x = 0; x < size; x++){
      board[y][x] = '-';
    }
  }
}

void moveSnake(snake* s){
  switch(s->direction){
    case 0: moveNode(s, s->head->x, s->head->y+1); break;
    case 1: moveNode(s, s->head->x-1, s->head->y); break;
    case 2: moveNode(s, s->head->x+1, s->head->y); break;
    case 3: moveNode(s, s->head->x, s->head->y-1); break;
    default: printf("INVALID DIRECTION");
  }
}

void moveNode(snake* s, int x, int y){
  node* newTail = s->tail->next;
  delete_Node(s->tail);
  s->tail = newTail;

  node* newHead = new_node(x, y, s->head);
  s->head = newHead;
}

void printBoard(){
  system("cls"); // Clear Command Line - Windows
  printf("\033c"); // Clear terminal - Linux and Mac
  for(int y = 0; y < size; y++){
    printf("# ");
    for(int x = 0; x < size; x++){
      printf("%c ", board[y][x]);
    }
    printf("#\n");
  }
}

void putHead(int x, int y){
  board[y][x] = '@';
}

void putTail(int x, int y){
  board[y][x] = 'O';
}

void putBoard(int x, int y){
  board[y][x] = '-';
}
