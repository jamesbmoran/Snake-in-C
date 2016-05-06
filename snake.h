#include <stdio.h>


typedef struct {
  int xPos;
  int yPos;
} snake;

void initialiseBoard();
void printBoard();
snake new_snake();
