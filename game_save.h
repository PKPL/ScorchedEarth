#ifndef GAME_SAVE_H
#define GAME_SAVE_H

/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include <stdio.h>
#include <stdlib.h>
#include "maps_create.h"
#include "defines.h"
#include "shot_final_equation.h"
#include "unit.h"

void save_game(int map_layout[MAX_X][MAX_Y], level_struct level, unit player, unit bot, float wind);

#endif // GAME_SAVE_H
