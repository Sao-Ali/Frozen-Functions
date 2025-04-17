#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "player.h"

//Current player, game starts on white
char currentPlayer = 'W';

char player_get_current(){
    return currentPlayer;
}
void player_switch(){
    if (currentPlayer == 'W'){
        currentPlayer = 'B';
    }
    else{
        currentPlayer = 'W';
    }
}