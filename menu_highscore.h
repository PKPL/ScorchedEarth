#ifndef __MENU_HIGHSCORE_H__
#define __MENU_HIGHSCORE_H__

//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include <windows.h>
#include <time.h>
#include <stdio.h>

FILE *fp;
const int n= 10;
int inChar;

typedef struct player
{
    char nickname[20];
    int points;
};


struct  player players[11];
void bubblesort();
void add_score ();
void check_top_ten();
void highscore();

#endif // __MENU_HIGHSCORE_H__
