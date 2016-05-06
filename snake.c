#include "snake.h"

int size = 25;
char board[25][50];



int main(){
  initialiseBoard();

  snake sman = new_snake();
  printBoard();
  return 0;
}

void initialiseBoard(){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size*2; j++){
      board[i][j] = (j%2) ? '-' : ' ';
    }
  }
}

void printBoard(){
  for(int i = 0; i < size; i++){
    printf("#");
    for(int j = 0; j < size*2; j++){
      printf("%c", board[i][j]);
    }
    printf(" #\n");
  }
}

snake new_snake(){
  snake s;
  s.xPos = size/2;
  s.yPos = size/2;
  board[size/2][size] = '@';
  board[size/2-1][size] = 'O';
  board[size/2-2][size] = 'O';
  return s;
}
