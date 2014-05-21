#ifndef __DRAWING_MAPS_H__
#define __DRAWING_MAPS_H__

//---------------------------- Draw maps ---------------------------------
// Drawing maps
//------------------------------------------------------------------------


#include "maps_create.h"
#include "defines.h"

void drawing_map (int map_layout [MAX_X][MAX_Y]);
void drawing_game_screen();
<<<<<<< HEAD
void information(int pl_pow, int pl_ang);
=======
void information(int pl_pow, int pl_ang, char missile_name[]);
>>>>>>> f6d33ecd487743a78c0fd14fda99c31d2bc4ed17
void falling(int map_layout[MAX_X][MAX_Y]);

#endif // __DRAWING_MAPS_H__
