// io.h stub
#ifndef IO_H
#define IO_H

#include <stdbool.h>

// Stores a move as from→to
typedef struct
{
    int from_row, from_col;
    int to_row, to_col;
} Move;

// Reads input and parses into a Move
bool io_get_move(Move *move);

#endif
