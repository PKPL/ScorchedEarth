//---------------------------- Drawing -----------------------------------
// It combines the files responsible for drawing objects and maps
//------------------------------------------------------------------------

// Included libraries

// Included files
#include "drawing.h"

void test_drawing(int mapLayout [MAX_X][MAX_Y]) // function for agreagte testing
{
    printf("Drawing test\n");
    test_drawing_units(mapLayout);
    test_drawing_destruction(mapLayout);
}
