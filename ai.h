#ifndef __AI_H__
#define __AI_H__

//---------------------------- Artificial Inteligence --------------------
// It combines the files responsible for artificial inteligence
//------------------------------------------------------------------------
// Polish team is working on this file
// Included libraries

// Included files
#include "levels_level.h"

#include "ai_controll.h"

#include <stdbool.h>
#include "defines.h"
#include<math.h>

float min_angle(unit local_bot);
int find_random(int min_ang, int max_ang);
bool raycast(unit from, int angle,  int map_layout[MAX_X][MAX_Y]);
void ai(unit local_bot, int map_layout[MAX_X][MAX_Y]);
int find_min_angle_fixed (int map_layout[MAX_X][MAX_Y], int Xturr,int Xtar, int Yturr);



#endif // __AI_H__
