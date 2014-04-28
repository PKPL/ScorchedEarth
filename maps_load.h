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
#define MAX_NAME_FILE 50

void test_maps_load ();
void load_Map (int map_layout[MAX_X][MAX_Y]);
char optionUser (char *str);
void readString (char *str, int max);
void reading_from_File (int map_layout [MAX_X][MAX_Y]);

#endif // __MAPS_LOAD_H__
