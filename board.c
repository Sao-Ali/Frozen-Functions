#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "board.h"

char whitePieces[9] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 'P'}; // Uppercase White
char blackPieces[9] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p'}; // Lowercase Black
char letters[9] = {'\0','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; 
char board[BOARD_SIZE][BOARD_SIZE][SQUARE_SIZE];

void board_init() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) { 

   
            if (i > 0 && i < 9 && (j == 0 || j == 9)) {
                int rank_num = 9 - i; 
                sprintf(board[i][j], " %c ", '0' + rank_num);
            }
            else if ((i == 0 || i == 9) && (j > 0 && j < 9)) {
                 sprintf(board[i][j], " %c ", letters[j]);
            }
             else if ((i == 0 || i == 9) && (j == 0 || j == 9)) {
                 strcpy(board[i][j], "   "); 
             }


            else if (i == 8 && (j > 0 && j < 9)) {
                sprintf(board[i][j], " %c ", blackPieces[j-1]);
            }
            else if (i == 7 && (j > 0 && j < 9)) {
                 sprintf(board[i][j], " %c ", blackPieces[8]); 
            }
            else if (i == 2 && (j > 0 && j < 9)) {
                 sprintf(board[i][j], " %c ", whitePieces[8]); 
            }
            else if (i == 1 && (j > 0 && j < 9)) {
                sprintf(board[i][j], " %c ", whitePieces[j-1]);
            }
            else if (i > 2 && i < 7 && (j > 0 && j < 9)) {
                strcpy(board[i][j], " . ");
            }
            else if (i > 0 && i < 9 && j > 0 && j < 9) {
                 strcpy(board[i][j], " . "); // Default to empty
            }
        }
    }
}



char board_get(int row, int col) {
    if (row < 1 || row > 8 || col < 1 || col > 8) {
        return '\0'; 
    }

    int i = 9 - row; 
    int j = col; 

    if (i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE) {
        return '\0'; 
    }

    if (SQUARE_SIZE >= 3) {
        char piece_char = board[i][j][1];
        return isalpha(piece_char) ? piece_char : '.';
    } else {
        return '?'; 
    }
}

void board_set(int row, int col, char piece) {
     if (row < 1 || row > 8 || col < 1 || col > 8) {
        return; 
    }
    int i_target = 9 - row; 
    int j_target = col;     

    if (i_target < 0 || i_target >= BOARD_SIZE || j_target < 0 || j_target >= BOARD_SIZE) {
        return; 
    }

    if (piece == '.') { 
        strcpy(board[i_target][j_target], " . ");
    } else {
        sprintf(board[i_target][j_target], " %c ", piece);
    }
}