// board.h stub
#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8

extern char board[BOARD_SIZE][BOARD_SIZE];

// Initializes the board to the standard starting position
void board_init();

// Gets the piece at a given position
char board_get(int row, int col);

// Sets the piece at a given position
void board_set(int row, int col, char piece);

#endif
