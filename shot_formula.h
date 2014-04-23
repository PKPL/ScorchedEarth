#ifndef __SHOT_FORMULA_H__
#define __SHOT_FORMULA_H__

//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include <stdio.h>
#include <stdlib.h>
#include "shot_final_equation.h"
#include "shot_hit.h"
#include "matrix.h"
#include "drawing_destruction.h"
#include "drawing_shots.h"

missile_data* playerShot(missile_data* /*second argument: float wind_speed*/);
missile_data* AIShoot(missile_data*, float);

#endif // __SHOT_FORMULA_H__
