//---------------------------- MAIN --------------------------------------
// Main file of the project
//------------------------------------------------------------------------

// Included libraries
#include <stdio.h>
#include <stdlib.h>

// Included files
#include "maps.c"
#include "drawing.c"
#include "shot.c"
#include "ai.c"
#include "menu.c"
#include "levels.c"

int main()
{
    printf("Scorched Earth\n");

    //Tests
    test_ai();
    test_drawing();
    test_levels();
    test_maps();
    test_menu();
    test_shot();

    _getch();
    return 0;
}
