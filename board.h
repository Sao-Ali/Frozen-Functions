#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 10
#define SQUARE_SIZE 6
extern char board[BOARD_SIZE][BOARD_SIZE][SQUARE_SIZE];

//Initialize Board
void board_init(void);

//Get piece at board location
char board_get(int row, int col);

//Set specific square to piece
void board_set(int row, int col, char piece);

#endif