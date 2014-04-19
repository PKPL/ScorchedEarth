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
    level_struct selected_level;
    //system("mode 100, 80");
    int map_layout[MAX_X][MAX_Y] = {{0}}; /*Matrix containing the map information initialized with value 0 everywhere. It will work with [x][y] coordinates.*/
    /*Since the array is initialized with the value 0, which stands for empty in the map, we won't have to fill empty spots with value 0 when the map is created*/
    printf("Scorched Earth\n");
    //Tests
    printf("\n-------------------------------------------------\n");
    printf("Testing functionality\n");
    test_ai();
    //selected_level = test_levels();
    printf("\nThere is an occasional crash during the map testing,\nbut only if you are generating a mountain map.\nIf this happens just run the program again.\nWe couldn't find the source of this yet.\n\n");
    test_menu();
    test_maps(map_layout);
    test_drawing(map_layout);
    test_unit();
    testShot();
    printf("\n-------------------------------------------------\n");
    _getch();
    return 0;
}



