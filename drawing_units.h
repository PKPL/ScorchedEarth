#ifndef __DRAWING_UNITS_H__
#define __DRAWING_UNITS_H__

//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------
#include <math.h>
#include "maps_create.h" // including this library to have MAX_X, MAX_Y and time.h
#include "defines.h"

typedef struct
{
    int x, y;
} tCoordinates;

void test_drawing_units(int map_layout[MAX_X][MAX_Y]);
void drawing_units(int map_layout[MAX_X][MAX_Y]);
tCoordinates position (int map_layout[MAX_X][MAX_Y]);
void gotoxy(int x, int y);

#endif // __DRAWING_UNITS_H__
