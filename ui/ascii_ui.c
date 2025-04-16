#include <stdio.h>
#include "ui.h"
#include "../board.h"
void ui_init() {}

void print_board() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%s", board[i][j]);  
        }
        printf("\n");
    }
    printf("\n");
}


void ui_draw_board() {
    printf("  a b c d e f g h\n");
    for (int i = 8; i >= 1; i--) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf(". ");
        }
        printf("%d\n", i);
    }
    
}

void ui_show_message(const char* msg) {
    printf("%s\n", msg);
}

void ui_cleanup() {}


