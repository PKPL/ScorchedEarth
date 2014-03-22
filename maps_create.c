//---------------------------- Create Maps -----------------------------------
// Creating maps
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_X 100
#define MAX_Y 100
#define MIN_X 0
#define MIN_Y 0

typedef struct
{
    int x, y;
} tCoordinates;

void createMap(int map[MAX_X][MAX_Y]);
int timeSeconds();


int main(void)
{
    int map[MAX_X][MAX_Y]; /*Matrix containing the map information*/
    return 0;
}

void createMap(int map[MAX_X][MAX_Y])
{
    /*Asks which type of map the player wants, plains, mountains, etc*/
    int x,y;
    /*For a Plain map*/

    srand(timeSeconds);

    /*---End of plain map---*/
}

int timeSeconds()
{
    int seconds;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    seconds = t->tm_sec;
    return seconds;
}
