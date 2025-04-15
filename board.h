#ifndef BOARD_H
#define BOARD_H


//Initialize Board
void board_init(void);
//Print Board
void print_board(void);

//Get piece at board location
char board_get(int row, int col);

#endif