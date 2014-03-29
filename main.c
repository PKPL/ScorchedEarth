//---------------------------- MAIN --------------------------------------
// Main file of the project
//------------------------------------------------------------------------

// Included libraries
#include <stdio.h>
#include <stdlib.h>

// Included files
#include "maps.h"
#include "drawing.h"
#include "shot.h"
#include "ai.h"
#include "menu.h"
#include "levels.h"
#include "unit.h"

int main()
{
    printf("Scorched Earth\n");

    //Tests
    printf("\n-------------------------------------------------\n");
    printf("Testing functionality\n");
    test_ai();
    test_drawing();
    test_levels();
    printf("\nThere is an occasional crash during the map testing,\nbut only if you are generating a mountain map.\nIf this happens just run the program again.\nWe couldn't find the source of this yet.\n\n");
    test_maps();
    test_menu();
    test_unit();
    test_shot();
    printf("\n-------------------------------------------------\n");

    _getch();
    return 0;
}
