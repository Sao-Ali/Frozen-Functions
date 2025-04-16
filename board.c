#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "board.h"
char whitePieces[9] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 'P'};
char blackPieces[9] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p'};
char letters[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
char board[BOARD_SIZE][BOARD_SIZE][SQUARE_SIZE];  
void board_init() {
    // Pieces: R, N, B, Q, K, B, N, R
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0){
                //TODO first row letters
                sprintf(board[i][j], " %c ", letters[j]);
            }
            else if (i == 1){
                // First rank: white major pieces
                sprintf(board[i][j], " %c ", whitePieces[j]);
            }
            else if (i == 2){
                // Second rank: pawns
                sprintf(board[i][j], " %c ", whitePieces[8]);
            }
            else if (i == 7){
                // 7th rank: black pawns
                sprintf(board[i][j], " %c ", blackPieces[8]);
            }
            else if (i ==8){
                //8th rank: black major pieces
                sprintf(board[i][j], " %c ", blackPieces[j]);
            }
            else if (i == 9){
                //TODO: BOTTOM ROW LETTERS
                sprintf(board[i][j], " %c ", letters[j]);
            }
            else{
                //Empty squares 
                strcpy(board[i][j], " . ");
            }
            
        }
    }
}




char board_get(int row, int col) {
    row--;
    col--;
    
    //Grab letter
    char piece = board[row][col][1];

    //Return '.' if we find empty square
    return isalpha(piece) ? piece : '.';
}
void board_set(int row, int col, char piece) {
    row --;
    col --;

    
    //Remove piece from current position
    for (int i = 0; i <=7; i++){
        for (int j = 0; j <= 7; j++){
            if (board_get(i+1,j+1) == piece){
                strcpy(board[i][j], "|   |");
            }
        }
    }

    //Put piece and NEW location
    sprintf(board[row][col], "| %c |", piece); 

}
