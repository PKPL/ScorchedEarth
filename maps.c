//---------------------------- Maps --------------------------------------
// It combines the files responsible for managing maps
//------------------------------------------------------------------------

// Included files
#include "maps.h"

extern int map_layout [MAX_X][MAX_Y];

void test_maps(int map_layout [MAX_X][MAX_Y]) // function for agreagate testing
{
    int x, y;
    bool checkInteger = true;
    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            if (map_layout[x][y] % 2 != 0 && map_layout[x][y] % 2 != 1) // is not integer
            {
                printf("Map generation error: Contents of array different than expected.\n");
                checkInteger = !checkInteger;
                break;
            }
        }
    }
}
