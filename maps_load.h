#ifndef __MAPS_LOAD_H__
#define __MAPS_LOAD_H__

//---------------------------- Load Maps ---------------------------------
// Loading maps
//------------------------------------------------------------------------
/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO
*/

// stdilib.h and stdio.h already included in maps_create.c
#include <stdio.h>
#include <stdlib.h>
#include "maps_create.h"
#include <stdbool.h> // includes the bool variable types, that is best when we just want true or false, 0 or 1 for the value, and takes less for RAM.
#include <string.h>
#include "defines.h"
#include <ctype.h>
#include <dirent.h>

char option_User (char *str);
bool load_Map (int map_layout[MAX_X][MAX_Y]);
void read_String (char *str, int max);
void list_dir(void);

#endif // __MAPS_LOAD_H__
