#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
char board[8][8][6];  
char whitePieces[9] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 'P'};
char blackPieces[9] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p'};
void board_init() {
    // Pieces: R, N, B, Q, K, B, N, R
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0){
                // First rank: white major pieces
                sprintf(board[i][j], "| %c |", whitePieces[j]);
            }
            else if (i == 1){
                // Second rank: pawns
                sprintf(board[i][j], "| %c |", whitePieces[8]);
            }
            else if (i == 6){
                // 7th rank: black pawns
                sprintf(board[i][j], "| %c |", blackPieces[8]);
            }
            else if (i ==7){
                //8th rank: black major pieces
                sprintf(board[i][j], "| %c |", blackPieces[j]);
            }
            else{
                //Empty squares 
                strcpy(board[i][j], "|   |");
            }
            
        }
    }
}

void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%s", board[i][j]);  
        }
        printf("\n");
    }
}

int main(void) {
    board_init();
    print_board();
    return 0;
}