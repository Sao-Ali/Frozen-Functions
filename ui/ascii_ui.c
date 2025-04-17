#include <stdio.h>
#include "ui.h"       
#include "../board.h" 



void ui_init() {
    board_init();
}



void ui_draw_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%s", board[i][j]);
            // TODO: Add a space between cells for slightly better readability if needed
            // printf(" ");
        }
        printf("\n"); 
    }
    printf("\n"); 
}

void ui_show_message(const char* msg) {
    printf("%s\n", msg);
}

void ui_cleanup() {
    //TODO
}