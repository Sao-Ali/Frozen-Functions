#include "board.h"
#include "ui/ui.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {

    board_init();
    ui_draw_board();


    return 0;
}