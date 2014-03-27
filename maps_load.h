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
#include <stdbool.h> // includes the bool variable types, that is best when we just want true or false, 0 or 1 for the value, and takes less for RAM.
#include <string.h>
#define MAX_NAME_FILE 50

char optionUser (char *str);
void readString (char *str, int max);
int readingfromFile ();
int map_load();

#endif // __MAPS_LOAD_H__
