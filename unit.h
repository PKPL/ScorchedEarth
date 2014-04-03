#ifndef __UNIT_H__
#define __UNIT_H__

//---------------------------- Units -------------------------------------
// It combines the files responsible for units
//------------------------------------------------------------------------

// Included libraries

//Structs
typedef struct unit
{
int x;
int y;
int points;
}unit;

// Included files

void test_unit();
void unit_func();

unit player;
unit bot;

#endif // __UNIT_H__
