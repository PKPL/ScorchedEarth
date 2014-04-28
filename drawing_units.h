#ifndef __DRAWING_UNITS_H__
#define __DRAWING_UNITS_H__

//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------
#include <math.h>
#include "maps_create.h" // including this library to have MAX_X, MAX_Y and time.h
#define PLAYER 10
#define ENEMY 20
#define DISTANCE 20 // minimum distance between player and enemy

typedef struct
{
    int x, y;
} tCoordinates;

void test_drawing_units(int mapLayout[MAX_X][MAX_Y]);
void drawing_units(int mapLayout[MAX_X][MAX_Y]);
tCoordinates position (int mapLayout[MAX_X][MAX_Y]);

#endif // __DRAWING_UNITS_H__
