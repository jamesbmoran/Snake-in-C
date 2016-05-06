#include "snake.h"

int size = 25;
char board[25][25];
void moveSnake(snake s);

int main(){
  initialiseBoard();

  snake sMan = make_snake();
  printBoard();
  return 0;
}

void initialiseBoard(){
  for(int y = 0; y < size; y++){
    for(int x = 0; x < size; x++){
      board[y][x] = '-';
    }
  }
}

void moveSnake(snake s){
  switch(s.direction){
    case 0: printf("UP"); break;
    case 1: printf("LEFT"); break;
    case 2: printf("RIGHT"); break;
    case 3: printf("DOWN"); break;
    default: printf("INVALID DIRECTION");
  }
}

void printBoard(){
  printf("\033c");
  for(int y = 0; y < size; y++){
    printf("# ");
    for(int x = 0; x < size; x++){
      printf("%c", board[y][x]);
    }
    printf(" #\n");
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
