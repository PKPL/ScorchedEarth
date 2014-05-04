#ifndef __SHOT_H__
#define __SHOT_H__

//---------------------------- Shot --------------------------------------
// It combines the files responsible for calculating the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include <stdio.h>
#include "shot_formula.h"
#include "matrix.h"
#include "shot_final_equation.h"
#include "maps_create.h"

#define PLAYER 10
#define ENEMY 20

void testShot(int, int, int, int, int, int map_layout[MAX_X][MAX_Y]); // function for agreagate testing

#endif // __SHOT_H__
