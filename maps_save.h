#ifndef __MAPS_SAVE_H__
#define __MAPS_SAVE_H__

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

void save_map(int map_layout[MAX_X][MAX_Y]);
void create_folder(char folderName[]);

#endif // __MAPS_SAVE_H__
