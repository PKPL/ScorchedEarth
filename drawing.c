//---------------------------- Drawing -----------------------------------
// It combines the files responsible for drawing objects and maps
//------------------------------------------------------------------------

// Included libraries

// Included files
#include "drawing.h"


extern int map_layout [MAX_X][MAX_Y];


void test_drawing(int map_layout [MAX_X][MAX_Y]) // function for agreagte testing
{
    printf("Drawing test\n");
    test_drawing_map(map_layout);
    //test_drawing_units(map_layout);
    //test_drawing_destruction(map_layout);
}
