//---------------------------- Maps --------------------------------------
// It combines the files responsible for managing maps
//------------------------------------------------------------------------

// Included files
#include "maps.h"

void test_maps(int map_layout [MAX_X][MAX_Y]) // function for agreagate testing
{
    printf("Maps test\n");

    //test_maps_save();
    //test_maps_load();
    test_maps_create(map_layout);
}
