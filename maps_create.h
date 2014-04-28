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
#include <math.h>

#define MAX_X 100
#define MAX_Y 80 /*When this value is changed, we must pay attention to MAX_HEIGHT_DEFORMATION and change some values in drawing_maps.c*/
#define MIN_X 0
#define MIN_Y 0
#define MAX_TERRAIN_HEIGHT_PLAINS_MAP 60
#define MAX_TERRAIN_INITIAL_HEIGHT_MOUNTAINS_MAP 30
#define MAX_DISTANCE_UNTIL_DEFORMATION_START 10
#define MAX_WIDTH_DEFORMATION 31
#define MAX_HEIGHT_DEFORMATION 75
#define HEIGHT_OFFSET 6

void create_mountain_map(int map_layout[MAX_X][MAX_Y]);
void new_rnd_seed();
void print_loading_status(int x);
void test_maps_create();

#endif // __MAPS_CREATE_H__
