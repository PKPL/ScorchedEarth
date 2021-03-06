#ifndef __MENU_HIGHSCORE_H__
#define __MENU_HIGHSCORE_H__

//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "defines.h"

typedef struct
{
    char nickname[20];
    int points;

} player_highscore;

extern player_highscore players[11];

void add_score (player_highscore players[11];);
void bubblesort(player_highscore players[11]);
void save_highscore (player_highscore players[11]);
void check_top_ten(player_highscore players[11]);
bool read_highscores();

#endif // __MENU_HIGHSCORE_H__

