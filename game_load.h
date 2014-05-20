#ifndef GAME_LOAD_H
#define GAME_LOAD_H
#include "defines.h"
#include "maps.h"
#include "levels_level.h"
#include "shot_final_equation.h"
#include "unit.h"

bool game_load (int map_layout[MAX_X][MAX_Y], level_struct *level, unit *player, unit *bot, float *wind_speed);
bool checker (int*, int);
#endif // GAME_LOAD_H
