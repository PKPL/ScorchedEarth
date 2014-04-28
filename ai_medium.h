#ifndef __AI_MEDIUM_H__
#define __AI_MEDIUM_H__

//---------------------------- AI Medium level ---------------------------
// AI for medium level
//------------------------------------------------------------------------


#include "maps_create.h"
#include "unit.h"
#include "shot.h"

void ai_medium(unit local_bot, int map_layout[MAX_X][MAX_Y]);
int min_power(unit from, int angle);
int max_power(unit from, int angle, int min_power_local);






#endif // __AI_MEDIUM_H__


