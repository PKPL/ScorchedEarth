#ifndef GAME_LOAD_H
#define GAME_LOAD_H
#include "defines.h"
#include "maps.h"
#include "levels_level.h"
#include "shot_final_equation.h"
#include "unit.h"

bool game_load (int map_layout[MAX_X][MAX_Y], level_struct *level, unit *player, unit *bot, missile_data *missile_type, float *wind_speed, bool *playerTurn);
bool checker (int*, int);
#endif // GAME_LOAD_H
