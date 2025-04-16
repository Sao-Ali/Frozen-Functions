#include <stdio.h>
#include "ui.h"       // Assuming ui.h defines the functions declared here
#include "../board.h" // Assuming board.h is one directory up

// Forward declaration needed if board.h wasn't included or doesn't declare it
// extern char board[BOARD_SIZE][BOARD_SIZE][SQUARE_SIZE];

void ui_init() {
    // It's common practice to initialize the board when the UI starts
    board_init();
}

// Prints the raw state of the 'board' array including borders
void print_board() {
    // Iterate through all rows of the board array (0 to 9)
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Iterate through all columns (0 to 9)
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Print the string content of the cell
            printf("%s", board[i][j]);
            // Add a space between cells for slightly better readability if needed
            // printf(" ");
        }
        printf("\n"); // Newline after each row is complete
    }
    printf("\n"); // Extra newline for spacing after the board
}


// Draws a more standard visual representation using board_get()
void ui_draw_board() {
    printf("  a b c d e f g h\n"); // Top file letters
    for (int rank = 8; rank >= 1; rank--) { // Iterate standard chess ranks 8 down to 1
        printf("%d ", rank); // Print rank number (left side)
        for (int file = 1; file <= 8; file++) { // Iterate standard files 1 ('a') to 8 ('h')
            // Get the piece from the board array using standard chess coordinates
            char piece = board_get(rank, file); // Use board_get with current rank and file
            printf("%c ", piece); // Print the piece character ('r', 'P', '.')
        }
        printf("%d\n", rank); // Print rank number (right side)
    }
     printf("  a b c d e f g h\n"); // Bottom file letters
     printf("\n"); // Extra newline for spacing
}

void ui_show_message(const char* msg) {
    printf("%s\n", msg);
}

void ui_cleanup() {
    // Nothing needed here for this simple ASCII UI
}