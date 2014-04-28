#ifndef __DRAWING_H__
#define __DRAWING_H__

//---------------------------- Drawing -----------------------------------
// It combines the files responsible for drawing objects and maps
//------------------------------------------------------------------------

// Included libraries

// Included files
#define _NO_OLDNAMES
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "drawing_maps.h"
#include "drawing_units.h"
#include "drawing_shots.h"
#include "drawing_destruction.h"
#include "maps_create.h"

void test_drawing(int map_layout [MAX_X][MAX_Y]);

#endif // __DRAWING_H__
