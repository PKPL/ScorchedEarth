#ifndef __MAPS_CREATE_H__
#define __MAPS_CREATE_H__

/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_X 200
#define MAX_Y 80
#define MIN_X 0
#define MIN_Y 0
#define MAX_TERRAIN_HEIGHT_PLAINS_MAP 60
#define MAX_TERRAIN_INITIAL_HEIGHT_MOUNTAINS_MAP 70
#define MAX_DISTANCE_UNTIL_DEFORMATION_START 10
#define MAX_WIDTH_DEFORMATION 31
#define MAX_HEIGHT_DEFORMATION 75
#define HEIGHT_OFFSET 6

typedef struct
{
    int x, y;
} tCoordinates;

void createPlainMap(int mapLayout[MAX_X][MAX_Y], int *counter);
void createMountainMap(int mapLayout[MAX_X][MAX_Y], int *counter);
void newRndSeed(int *counter);
void test_maps_create();
void drawMap(int mapLayout[MAX_X][MAX_Y]);

#endif // __MAPS_CREATE_H__
