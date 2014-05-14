#ifndef __MENU_HIGHSCORE_H__
#define __MENU_HIGHSCORE_H__

//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include "defines.h"

typedef struct
{
    char nickname[20];
    int points;
} player_highscore;


player_highscore players[11];
void bubblesort();
void add_score ();
void check_top_ten();
void highscore();

#endif // __MENU_HIGHSCORE_H__
