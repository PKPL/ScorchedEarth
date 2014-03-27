/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO


Map creation done until further notice or revision.
Bug 2 identified by Pawel still to be fixed. Also the sky pillars randomly appearing.

*/

#include "maps_create.h"

void test_maps_create()
{
    int counterTimesUsedRandom = 0;
    int mapLayout[MAX_X][MAX_Y] = {{0}}; /*Matrix containing the map information initialized with value 0 everywhere*/
    /*Since the array is initialized with the value 0, which stands for empty in the map, we won't have to fill empty spots with value 0 when the map is created*/

    createPlainMap(mapLayout, &counterTimesUsedRandom);
    createMountainMap(mapLayout, &counterTimesUsedRandom);
}

void createMountainMap(int mapLayout[MAX_X][MAX_Y], int *counter)
{
    int x, y, number, finishedCreatingMap, isContinuation, numberAlternative, freeSpaceHeight;
    freeSpaceHeight = (1/4) / MAX_Y;
    finishedCreatingMap = 0;
    isContinuation = 0;

    /*For a mountain map*/
    int terrainDeformationStart, deformationWidth, deformationHeight, widthMedian, terrainUnitsBuilt, terrainUnitsUntilMedian, terrainUnitsToBuild, terrainUnitsAfterMedian;
    terrainUnitsBuilt = 0;
    newRndSeed(counter);
    number = rand() % (MAX_TERRAIN_INITIAL_HEIGHT_MOUNTAINS_MAP + 1); /*defines the initial terrain height*/

    do
    {
        newRndSeed(counter);
        terrainDeformationStart = rand() % (MAX_DISTANCE_UNTIL_DEFORMATION_START + 1); /*defines the max distance until a deformation appears*/
        /*This will loop for all the x coordinates at the same height, before the first deformation*/


        if (isContinuation == 1)
        {
            terrainUnitsToBuild = (terrainDeformationStart - 1);
            for (x = terrainUnitsBuilt; terrainUnitsToBuild > 0; x++)
            {
                for (y = 0; y < number; y++)
                {
                    mapLayout[x][y] = 1; /*This will create a surface after a deformation*/ /*number is the last height built on*/
                }
                terrainUnitsBuilt++;
                terrainUnitsToBuild--;
            }
        }
        else
        {
            for (x = 0; x < (terrainDeformationStart - 1); x++)
            {
                for (y = 0; y < number; y++)
                {
                    mapLayout[x][y] = 1; /*This will create the surface line before the first deformation*/
                }
                terrainUnitsBuilt++;
            }
        }

        do
        {
            newRndSeed(counter);
            deformationWidth = rand() % (MAX_WIDTH_DEFORMATION + 1); /*defines the max width for the deformation. This will have to be an odd number for this implementation version*/
        }
        while (deformationWidth % 2 == 0 && deformationWidth < 5); /*Ensures the deformation has at least the width of 5 units, and the deformation width is an odd number*/

        do
        {
            newRndSeed(counter);
            deformationHeight = rand() %(MAX_HEIGHT_DEFORMATION + 1); /*defines the max height for the deformation.*/
            /*For this implementation version, valleys may appear on a mountain, but valleys will never be forcefully created. This will change on a later revision*/
        }
        while (deformationHeight + number >= (MAX_Y - freeSpaceHeight) || deformationHeight < 2); /*We have hardcoded the minimum height to 2 to stop the [y] value from being 0 or -1*/

        /*The following code prevents the deformation width to go outside map bounds, and if a new width is to be defined, it ensures it's an odd number*/
        if (deformationWidth + terrainUnitsBuilt >= MAX_X && (MAX_X - terrainUnitsBuilt) % 2 != 0)
        {
            deformationWidth = (MAX_X - terrainUnitsBuilt);
            finishedCreatingMap = 1; /*No more space for deformations after the current one*/
        }
        else if (deformationWidth + terrainUnitsBuilt >= MAX_X && (MAX_X - terrainUnitsBuilt - 1) % 2 != 0)
        {
            deformationWidth = (MAX_X - terrainUnitsBuilt);
            finishedCreatingMap = 1; /*No more space for deformations after the current one*/
        }
        /*At this point we have found the width and height for the deformation*/
        /*We need to find the width's median now*/
        widthMedian = (deformationWidth/2) + 1; /*In this implementation version, the median of the width will have the highest height*/
        terrainUnitsUntilMedian = deformationWidth - widthMedian;
        terrainUnitsToBuild = terrainUnitsUntilMedian;
        terrainUnitsAfterMedian = terrainUnitsUntilMedian;

        for (x = terrainUnitsBuilt; terrainUnitsToBuild > 0; x++) /*This loop creates terrain deformation before reaching the mountain top. This can either create a mountain or a valley on a mountain.*/
        {

            newRndSeed(counter);
            number = rand() % (deformationHeight + 1); /*Gets a number from 0 to the max deformation height to be built.*/

            for (y = 0; y < number; y++)
            {
                mapLayout[x][y] = 1;
            }
            terrainUnitsBuilt++;
            terrainUnitsToBuild--;
        }

        /*Now we have reached the median width value, which will have the max height*/
        x = terrainUnitsBuilt; /*This step is only for us to know that x has the value of the units built, but this is not a necessary line as that is already the value x holds. This is just a reminder*/
        y = (deformationHeight - 1);
        mapLayout[x][y] = 1;
        terrainUnitsBuilt++;
        /*Now the median value already has terrain*/
        /*We need to assign terrain to the remaining values of the deformation width*/

        terrainUnitsToBuild = terrainUnitsAfterMedian;

        for (x = terrainUnitsBuilt; terrainUnitsToBuild > 0; x++) /*This loop creates terrain deformation after reaching the mountain top. This can either create a mountain or a valley on a mountain.*/
        {
            newRndSeed(counter);
            numberAlternative = rand() % (deformationHeight + 1);
            for (y = 0; y < numberAlternative; y++)
            {
                mapLayout[x][y] = 1;
                number = y;
            }
            terrainUnitsBuilt++;
            terrainUnitsToBuild--;
        }
        isContinuation = 1;
        /*This concludes the building of a deformation*/
    }
    while (finishedCreatingMap != 1);
}



void createPlainMap(int mapLayout[MAX_X][MAX_Y], int *counter)
{
    int x, y, number;

    /*For a Plain map*/
    newRndSeed(counter);
    number = rand() % (MAX_TERRAIN_HEIGHT_PLAINS_MAP + 1); /* 0 - MAX HEIGHT  -> need to put MAX HEIGHT +1*/
    /*This will loop for all the x coordinates*/
    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < number; y++)
        {
            mapLayout[x][y] = 1;  /*This will set everything under the surface height to be ground*/
        }
    }
    /*---End of plain map---*/

}

void newRndSeed(int *counter)
{
    int seed;
    seed = timeSeconds(counter);
    srand(seed);
}

int timeSeconds(int *counter)
{
    int seconds;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    (*counter)++;
    seconds = t->tm_sec;
    seconds += (*counter);
    return seconds;
}
