//---------------------------- Create Maps -----------------------------------
// Creating maps
//------------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define MIN_X 0
#define MIN_Y 0
#define MAX_X 800
#define MAX_Y 600
#define GROUND 0

typedef struct
{
    int x, y;
} tCoordinates;

void createPlainMap ();

int main (void)
{
    tCoordinates coordinates;
    int map [MAX_X][MAX_Y];

    return 0;
}

void createMap ()
{
    int x, y;

    for (x = 0; x < MAX_X; x++)
    {
        //draw X;

        for (y = 0; y < MAX_Y; y++)
        {
        //draw Y;

        }
    }
}
