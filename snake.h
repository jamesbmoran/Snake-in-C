#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <time.h>

// Defining Data Stuctures
typedef struct node {
  struct node* next;
  int x;
  int y;
} node;

typedef struct {
  int x;
  int y;
} food;

//Defining a snake
typedef struct {
  int direction;
  int xPos;
  int yPos;
  node* head;
  node* tail;
} snake;

// Getting input
void changeDirection(char input);

// Updating the snake
void moveSnake();
void moveNode(int x, int y);

food* new_food();


int checkPosition(int x, int y);
int checkSnakeCollision(int x, int y);

// Initalise and print board
void initialiseBoard();
void printBoard();

// Updating Board
void putHead(int x, int y);
void putTail(int x, int y);
void putBoard(int x, int y);
void putFood(int x, int y);

// Data structures methods
snake* make_snake();
node* new_node(int x, int y, node* next);
void delete_Node(node* n);
