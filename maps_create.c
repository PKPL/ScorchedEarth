/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO


Map creation done until further notice or revision.

Currently all difficulty levels generate the map the same way, and the code is not optimised yet.

*/

#include "maps_create.h"

void test_maps_create(int map_layout [MAX_X][MAX_Y])
{
    create_mountain_map(map_layout);
}

void create_mountain_map(int map_layout[MAX_X][MAX_Y])
{
    int x, y, number, finished_creating_map, is_continuation, number_alternative, free_space_height, will_have_to_create_compensation_unit;
    int counter = 0;
    free_space_height = (1/4) / MAX_Y;
    finished_creating_map = 0;
    will_have_to_create_compensation_unit = 0;
    is_continuation = 0;

    /*For a mountain map*/
    int terrain_deformation_start, height_offset_high, height_offset_low, deformation_width, deformation_height, widthMedian, terrain_units_built, terrain_units_until_median, terrain_units_to_build, terrainUnitsAfterMedian;
    terrain_units_built = 0;
    height_offset_high = 0;
    height_offset_low = 0;
    new_rnd_seed(&counter);
    number = rand() % (MAX_TERRAIN_INITIAL_HEIGHT_MOUNTAINS_MAP - free_space_height + 1); /*defines the initial terrain height*/

    do
    {
        new_rnd_seed(&counter);
        terrain_deformation_start = rand() % (MAX_DISTANCE_UNTIL_DEFORMATION_START + 1); /*defines the max distance until a deformation appears*/
        /*This will loop for all the x coordinates at the same height, before the first deformation*/


        if (is_continuation == 1)
        {
            terrain_units_to_build = (terrain_deformation_start - 1);
            if (terrain_units_built + terrain_units_to_build > MAX_X)
            {
                terrain_units_to_build = (MAX_X - terrain_units_built);
            }
            for (x = terrain_units_built; terrain_units_to_build > 0; x++)
            {
                for (y = 0; y < number; y++)
                {
                    map_layout[x][y] = 1; /*This will create a surface after a deformation*/ /*number is the last height built on*/
                }
                terrain_units_built++;
                terrain_units_to_build--;
            }
        }
        else
        {
            for (x = 0; x < (terrain_deformation_start - 1); x++)
            {
                for (y = 0; y < number; y++)
                {
                    map_layout[x][y] = 1; /*This will create the surface line before the first deformation*/
                }
                terrain_units_built++;
            }
        }

        do
        {
            new_rnd_seed(&counter);
            deformation_width = rand() % (MAX_WIDTH_DEFORMATION + 1); /*defines the max width for the deformation. This will have to be an odd number for this implementation version*/
        }
        while (deformation_width % 2 == 0 || deformation_width < 5); /*Ensures the deformation has at least the width of 5 units, and the deformation width is an odd number*/

        do
        {
            new_rnd_seed(&counter);
            deformation_height = rand() %(MAX_HEIGHT_DEFORMATION + 1); /*defines the max height for the deformation.*/
            /*For this implementation version, valleys may appear on a mountain, but valleys will never be forcefully created. This will change on a later revision*/
        }
        while (deformation_height + number >= (MAX_Y - free_space_height) || deformation_height < 2); /*We have hardcoded the minimum height to 2 to stop the [y] value from being 0 or -1*/

        height_offset_high = deformation_height + HEIGHT_OFFSET;
        height_offset_low = deformation_height - HEIGHT_OFFSET;

        /*The following code prevents the deformation width to go outside map bounds, and if a new width is to be defined, it ensures it's an odd number*/
        if (deformation_width + terrain_units_built >= MAX_X && (MAX_X - terrain_units_built) % 2 != 0)
        {
            deformation_width = (MAX_X - terrain_units_built);
            finished_creating_map = 1; /*No more space for deformations after the current one*/
        }
        else if (deformation_width + terrain_units_built >= MAX_X && (MAX_X - terrain_units_built - 1) % 2 != 0 && (MAX_X - terrain_units_built - 1) != -1)
        {
            deformation_width = (MAX_X - terrain_units_built - 1); /*Now we have to build one unit in a straight line*/
            will_have_to_create_compensation_unit = 1;
            finished_creating_map = 1; /*No more space for deformations after the current one*/
        }
        else if (deformation_width + terrain_units_built >= MAX_X && (MAX_X - terrain_units_built - 1) % 2 != 0 && (MAX_X - terrain_units_built - 1) == -1)
        {
            deformation_width = 0;
            finished_creating_map = 1;
        }
        /*At this point we have found the width and height for the deformation*/
        /*We need to find the width's median now*/
        if (deformation_width != 0)
        {
            widthMedian = (deformation_width/2) + 1; /*In this implementation version, the median of the width will have the highest height*/
        }
        else
        {
            widthMedian = 0;
        }
        terrain_units_until_median = deformation_width - widthMedian;
        terrain_units_to_build = terrain_units_until_median;
        terrainUnitsAfterMedian = terrain_units_until_median;

        for (x = terrain_units_built; terrain_units_to_build > 0; x++) /*This loop creates terrain deformation before reaching the mountain top. This can either create a mountain or a valley on a mountain.*/
        {

            do
            {
                new_rnd_seed(&counter);
                number = rand() % (height_offset_high + 1); /*Gets a number from 0 to the max deformation height + the height_offset_high to be built.*/
            }
            while (number < height_offset_low || number > height_offset_high || number == 0);

            for (y = 0; y < number; y++)
            {
                map_layout[x][y] = 1;
            }
            terrain_units_built++;
            terrain_units_to_build--;
        }

        /*Now we have reached the median width value, which will have the max height*/
        x = terrain_units_built; /*This step is only for us to know that x has the value of the units built, but this is not a necessary line as that is already the value x holds. This is just a reminder*/

        for (y = 0; y < deformation_height; y++)
        {
            map_layout[x][y] = 1;
        }
        terrain_units_built++;
        /*Now the median value already has terrain*/
        /*We need to assign terrain to the remaining values of the deformation width*/

        terrain_units_to_build = terrainUnitsAfterMedian;

        for (x = terrain_units_built; terrain_units_to_build > 0; x++) /*This loop creates terrain deformation after reaching the mountain top. This can either create a mountain or a valley on a mountain.*/
        {
            do
            {
                new_rnd_seed(&counter);
                number_alternative = rand() % (height_offset_high + 1); /*Gets a number from 0 to the max deformation height + the height_offset_high to be built.*/
            }
            while (number_alternative < height_offset_low || number_alternative > height_offset_high || number_alternative == 0);

            for (y = 0; y < number_alternative; y++)
            {
                map_layout[x][y] = 1;
            }
            number = y + 1;
            terrain_units_built++;
            terrain_units_to_build--;
        }
        if (will_have_to_create_compensation_unit == 1)
        {
            for (x = (MAX_X - 1); x < MAX_X; x++)
            {
                for (y = 0; y < number; y++)
                {
                    map_layout[x][y] = 1; /*Draws the last x unit of the map if the last deformation didn't include the last x position*/
                }
            }
        }
        is_continuation = 1;
        /*This concludes the building of a deformation*/
    }
    while (finished_creating_map != 1);
}


void new_rnd_seed(int *counter)
{
    struct timeval t1;
    gettimeofday(&t1, NULL);
    (*counter)++;
    srand((t1.tv_usec * t1.tv_sec) + (*counter));
}
