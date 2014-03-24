/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO


Changes done: Plain terrain generation done.

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_X 100
#define MAX_Y 100
#define MIN_X 0
#define MIN_Y 0
#define MAX_TERRAIN_HEIGHT_PLAINS_MAP 80
#define MAX_TERRAIN_INITIAL_HEIGHT_MOUNTAINS_MAP 90
#define MAX_DISTANCE_UNTIL_DEFORMATION_START 10
#define MAX_WIDTH_DEFORMATION 31
#define MAX_HEIGHT_DEFORMATION 95

typedef struct
{
    int x, y;
} tCoordinates;

void createMap(int mapLayout[MAX_X][MAX_Y], int *counter);
int timeSeconds(int *counter);
void newRndSeed(int *counter);

int main(void)
{
    int counterTimesUsedRandom = 0;
    int mapLayout[MAX_X][MAX_Y] = {{0}}; /*Matrix containing the map information initialized with value 0 everywhere*/
    /*Since the array is initialized with the value 0, which stands for empty in the map, we won't have to fill empty spots with value 0 when the map is created*/

    createMap(mapLayout, &counterTimesUsedRandom);

    return 0;
}

void createMap(int mapLayout[MAX_X][MAX_Y], int *counter)
{
    /*Asks which type of map the player wants, plains, mountains, etc*/
    int x,y, number;

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


    /*For a mountain map*/
    int terrainDeformationStart, deformationWidth, deformationHeight, widthMedian, terrainUnitsBuilt, terrainUnitsUntilMedian, terrainUnitsToBuild, terrainUnitsAfterMedian, lastHeight;
    terrainUnitsBuilt = 0;
    lastHeight = 1; /*This line is just to avoid a warning that this var may be used uninitialized, however the variable will always be given a value with this program's code*/
    newRndSeed(counter);
    number = rand() % (MAX_TERRAIN_INITIAL_HEIGHT_MOUNTAINS_MAP + 1); /*defines the initial terrain height*/
    /*Code for the deformation begins here, will have to be put into a function to repeat itself*/
    newRndSeed(counter);
    terrainDeformationStart = rand() % (MAX_DISTANCE_UNTIL_DEFORMATION_START + 1); /*defines the max distance until a deformation appears*/
    /*This will loop for all the x coordinates at the same height, before the first deformation*/
    for (x = 0; x < (terrainDeformationStart - 1); x++)
    {
        for (y = 0; y < number; y++)
        {
            mapLayout[x][y] = 1; /*This will create the surface line before the first deformation*/
        }
        terrainUnitsBuilt++;
    }

    do
    {
        newRndSeed(counter);
        deformationWidth = rand() % (MAX_WIDTH_DEFORMATION + 1); /*defines the max width for the deformation. This will have to be an odd number for this implementation version*/
    }
    while (deformationWidth % 2 == 0 && deformationWidth < 5); /*Ensures the deformation has at least the width of 5 units, and the deformation width is an odd number*/

    if ((terrainUnitsBuilt + deformationWidth) < MAX_X) /*If this is verified, we have enough space for another deformation*/
    {
        do
        {
            newRndSeed(counter);
            deformationHeight = rand() %(MAX_HEIGHT_DEFORMATION + 1); /*defines the max height for the deformation.*/
            /*For this implementation version, valleys may appear on a mountain, but valleys will never be forcefully created. This will change on a later revision*/
        }
        while (deformationHeight + number >= MAX_Y);

        /*The following code prevents the deformation width to go outside map bounds, and if a new width is to be defined, it ensures it's an odd number*/
        if (deformationWidth + number >= MAX_X && (MAX_X - number) % 2 != 0)
        {
            deformationWidth = MAX_X - number;
        }
        else if (deformationWidth + number >= MAX_X && (MAX_X - number - 1) % 2 != 0)
        {
            deformationWidth = MAX_X - number;
        }
        /*At this point we have found the width and height for the deformation*/
        /*We need to find the width's median now*/
        widthMedian = (deformationWidth/2) + 1; /*In this implementation version, the median of the width will have the highest height*/
        terrainUnitsUntilMedian = deformationWidth - widthMedian;
        terrainUnitsToBuild = terrainUnitsUntilMedian;
        terrainUnitsAfterMedian = terrainUnitsUntilMedian;

        for (x = terrainUnitsBuilt; terrainUnitsToBuild > 0; x++) /*This loop creates terrain deformation before reaching the mountain top. This can either create a mountain or a valley on a mountain.*/
        {
            do
            {
                newRndSeed(counter);
                number = rand() % (MAX_HEIGHT_DEFORMATION + 1);
            }
            while (number <= deformationHeight);
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

        terrainUnitsBuilt = terrainUnitsAfterMedian;
        terrainUnitsToBuild = terrainUnitsAfterMedian;

        for (x = terrainUnitsBuilt; terrainUnitsToBuild > 0; x++) /*This loop creates terrain deformation after reaching the mountain top. This can either create a mountain or a valley on a mountain.*/
        {
            do
            {
                newRndSeed(counter);
                number = rand() % (MAX_HEIGHT_DEFORMATION + 1);
            }
            while (number <= deformationHeight);
            for (y = 0; y < number; y++)
            {
                mapLayout[x][y] = 1;
                lastHeight = y;
            }
            terrainUnitsBuilt++;
            terrainUnitsToBuild--;
        }
        /*This concludes the building of a deformation*/
    }
    else /*Not enough blocks available for a deformation.*/
    {
        for (x = terrainUnitsBuilt; x < MAX_X; x++)
        {
            for (y = 0; y < lastHeight; y++)
            {
                mapLayout[x][y] = 1; /*Sets the rest of the map's surface to the last built height*/
            }
        }
    }

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
