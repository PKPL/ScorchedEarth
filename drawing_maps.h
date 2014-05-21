#ifndef __DRAWING_MAPS_H__
#define __DRAWING_MAPS_H__

//---------------------------- Draw maps ---------------------------------
// Drawing maps
//------------------------------------------------------------------------


#include "maps_create.h"
#include "defines.h"

void drawing_map (int map_layout [MAX_X][MAX_Y]);
void gotoxy(int x, int y);
void drawing_game_screen();
void information(int pl_pow, int pl_ang, char missile_name[]);
void falling(int map_layout[MAX_X][MAX_Y]);

#endif // __DRAWING_MAPS_H__
