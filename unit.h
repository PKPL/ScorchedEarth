#ifndef __UNIT_H__
#define __UNIT_H__

//---------------------------- Units -------------------------------------
// It combines the files responsible for units
//------------------------------------------------------------------------

// Included libraries
#include "defines.h"

//Structs
typedef struct unit
{
int x;
int y;
int points;
int hp;
}unit;

// Included files

void test_unit();
void unit_func();

extern unit player;
extern unit bot;

#endif // __UNIT_H__
