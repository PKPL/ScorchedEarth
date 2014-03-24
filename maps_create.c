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

typedef struct
{
    int x, y;
} tCoordinates;

void createMap(int mapLayout[MAX_X][MAX_Y], int *counter);
int timeSeconds(int *counter);

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
    int x,y, number, result;

    /*For a Plain map*/
    result = timeSeconds(counter);
    srand(result);
    number = rand() % MAX_TERRAIN_HEIGHT_PLAINS_MAP; /* 0 - 80  -> need to put 81*/
    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < number; y++)
        {
            mapLayout[x][y] = 1;  /*This will set everything under the surface height to be ground*/
        }
    }
    /*---End of plain map---*/


    /*For a mountain map*/
    result = timeSeconds(counter);
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
