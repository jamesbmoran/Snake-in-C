#include "snake.h"

int size = 10;
char board[10][10];
int gameNotOver = 1;
snake* s;
food* f;

int main(){
  initialiseBoard();
  s = make_snake();
  f = new_food();

  char input;

  // Game Loop
  WINDOW *w = initscr();

  while(gameNotOver){
    printBoard();
    timeout(1000); // Updates every second or when user inputs button
    input = getch();
    changeDirection(input);
    moveSnake();
  }
  clear();
  printw("You Lose");
  sleep(1);
  endwin();
  printf("Game Over\n");
  return 0;
}

void changeDirection(char input){
  switch (input){
    // Checks input isnt towards the opposite direction
    case 'w': s->direction = (s->direction != 0) ? 3 : 0; break;
    case 's': s->direction = (s->direction != 3) ? 0 : 3; break;
    case 'a': s->direction = (s->direction != 2) ? 1 : 2; break;
    case 'd': s->direction = (s->direction != 1) ? 2 : 1; break;
  }
}

void initialiseBoard(){
  for(int y = 0; y < size; y++){
    for(int x = 0; x < size; x++){
      board[y][x] = '-';
    }
  }
}

void moveSnake(){
  switch(s->direction){
    case 0: moveNode(s->head->x, s->head->y+1); break;
    case 1: moveNode(s->head->x-1, s->head->y); break;
    case 2: moveNode(s->head->x+1, s->head->y); break;
    case 3: moveNode(s->head->x, s->head->y-1); break;
    default: printf("INVALID DIRECTION");
  }
}

void moveNode(int x, int y){
  if(checkPosition(x,y)){

    if(x == f->x && y == f->y){
      f = new_food();
    } else {
      node* newTail = s->tail->next;
      delete_Node(s->tail);
      s->tail = newTail;
    }

    putTail(s->head->x,s->head->y);
    node* newHead = new_node(x, y, NULL);
    s->head->next = newHead;
    s->head = newHead;

  }
  else{
    gameNotOver = 0;
  }
}

int checkPosition(int x, int y){
  // Checking it's within the bounds of the board
  if(x<0||y<0||x>=size||y>=size){
    return 0;
  }
  else {
    return checkSnakeCollision(x, y);
  }
}

int checkSnakeCollision(int x, int y){
  node tail = *(s->tail->next); // The next is so it doesn't fail on a tail which is about to move
  while(tail.next!=NULL){
    // Checking the position is not already taken
    if(tail.x == x && tail.y == y){
      return 0;
    }
    tail = *(tail.next);
  };
  return 1;
}

void printBoard(){
  clear();
  for(int y = 0; y < size; y++){;
    for(int x = 0; x < size; x++){
      printw("%c ", board[y][x]);
    }
    printw("\n");
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

void putFood(int x, int y){
  board[y][x] = 'X';
}
