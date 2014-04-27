#ifndef __SHOT_FORMULA_H__
#define __SHOT_FORMULA_H__

//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "shot_final_equation.h"
#include "shot_hit.h"
#include "matrix.h"
#include "drawing_destruction.h"
#include "drawing_shots.h"
#include "levels_level.h"

void playerShot(missile_data*);
void AIShoot(missile_data*, float, int);
float AIcheck(int, int, float, int, int, int);

#endif // __SHOT_FORMULA_H__
