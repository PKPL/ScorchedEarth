#ifndef __MENU_NEW_GAME_H__
#define __MENU_NEW_GAME_H__

//---------------------------- New game ----------------------------------
// Start new game
//------------------------------------------------------------------------

#include "maps_create.h"
#include "defines.h"
#include "armor.h"
#include "shot_final_equation.h"

//extern int screen_bufor [MAX_X][MAX_Y];

void game_loop(int map_layout [MAX_X][MAX_Y], bool game_loaded, bool map_loaded);
void drawing(int map_layout[MAX_X][MAX_Y], int player_angle);
void drawing_create(int i, int player_angle);
#endif // __MENU_NEW_GAME_H__
