#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
// Defining Data Stuctures
typedef struct node {
  struct node* next;
  int x;
  int y;
} node;

//Defining a snake
typedef struct {
  int direction;
  int xPos;
  int yPos;
  node* head;
  node* tail;
} snake;

//
void moveSnake(snake* s);
void moveNode(snake* s, int x, int y);

// Initalise and print board
void initialiseBoard();
void printBoard();

// Updating Board
void putHead(int x, int y);
void putTail(int x, int y);
void putBoard(int x, int y);

// Data structures methods
snake make_snake();
node* new_node(int x, int y, node* next);
void delete_Node(node* n);
