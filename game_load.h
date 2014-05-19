#ifndef GAME_LOAD_H
#define GAME_LOAD_H
#include "defines.h"
#include "maps.h"
#include "levels_level.h"
#include "shot_final_equation.h"

bool game_load (int[MAX_X][MAX_Y], level_struct*, missile_data*, float*, bool*);
bool checker (int*, int);
#endif // GAME_LOAD_H
