#ifndef __DRAWING_SHOTS_H__
#define __DRAWING_SHOTS_H__

//---------------------------- Draw shots --------------------------------
// Drawing shots
//------------------------------------------------------------------------

#include "shot_final_equation.h"
#include "unit.h"
#include "defines.h"
#include "drawing_maps.h"

void create_arrow(int i, missile_data *m);
void drawing_shots (int i,int map_layout[MAX_X][MAX_Y], missile_data *m);

#endif // __DRAWING_SHOTS_H__
