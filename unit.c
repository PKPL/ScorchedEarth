//---------------------------- Units -------------------------------------
// It combines the files responsible for units
//------------------------------------------------------------------------

// Included files
#include "unit.h"

unit player;
unit bot;


void test_unit() // function for agreagate testing
{
    printf("Unit test\n");
}

void unit_func()
{
    //Setting hp and points
    player.points = 0;
    player.hp = 100;

    bot.points = 0;
    bot.hp = 100;
}
