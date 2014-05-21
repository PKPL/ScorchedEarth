#ifndef SAURON_CREATION_H
#define SAURON_CREATION_H

#include "defines.h"
#include "unit.h"
#include "sauron_shoot.h"
#define sauron_height 10
#define sauron_width 4;


void sauron_creation(int map_layout[MAX_X][MAX_Y], unit *bot);
void sauron_destruction (int map_layout[MAX_X][MAX_Y], unit *bot);
void constructor (int x, int y, int *pos, int number);

#endif // SAURON_CREATION_H
