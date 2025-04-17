// io.c stub
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.h"

static int file_to_col(char file) {
    //Assuming file is column

    //TODO: Check if file is invalid int 
    return (int)file;
    

}

static int rank_to_row(char rank) {
    //TODO: Check if rank is invalid int

    //Rank is row

    return (int)rank;

}

bool io_get_move(Move* move) {
    

}
