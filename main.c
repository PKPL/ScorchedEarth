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
#include <windows.h>

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.


int main()
{

wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
rHnd = GetStdHandle(STD_INPUT_HANDLE);

// Change the window title:
SetConsoleTitle("Scorched Earth");
// Set up the required window size:
SMALL_RECT windowSize = {0, 0, 100, 80};
SetConsoleWindowInfo(wHnd, 1, &windowSize);
// Change the console window size:
// Create a COORD to hold the buffer size:
COORD bufferSize = {100, 80};
SetConsoleScreenBufferSize(wHnd, bufferSize);



    level_struct selected_level;
    //system("mode 100, 80");
    int map_layout[MAX_X][MAX_Y] = {{0}}; /*Matrix containing the map information initialized with value 0 everywhere. It will work with [x][y] coordinates.*/
    /*Since the array is initialized with the value 0, which stands for empty in the map, we won't have to fill empty spots with value 0 when the map is created*/
    printf("Scorched Earth\n");
    //Tests
    printf("\n-------------------------------------------------\n");
    printf("Testing functionality\n");
   // test_ai();
    //selected_level = test_levels();
    test_menu(map_layout);
   // test_maps(map_layout);
    //test_drawing(map_layout);
    //test_unit();
    //testShot();
    printf("\n-------------------------------------------------\n");
    _getch();
    return 0;
}



