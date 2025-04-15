#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char board[8][8][4];  // 8x8 grid of 3-character strings

void board_init() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            strcpy(board[i][j], "| |");  // copy string into each cell
        }
    }
}

void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%s", board[i][j]);  // print each cell
        }
        printf("\n");
    }
}

int main(void) {
    board_init();
    print_board();
    return 0;
}