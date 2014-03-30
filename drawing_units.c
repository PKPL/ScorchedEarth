//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------

#include "drawing_units.h"

 void test_drawing_units () {
 	int x, y;
    int mapLayout[MAX_X][MAX_Y] = {{0}}; // just for testing
    drawing_units(mapLayout[MAX_X][MAX_Y]);
 }

 void drawing_units (int mapLayout[MAX_X][MAX_Y]) {
 	tCoordinates coordinates_player, coordinates_enemy;
 	do {
 	coordinates_player = position (mapLayout);
 	coordinates_enemy = position (mapLayout);
 	} while (abs(coordinates_enemy.x - coordinates_player.x) <= DISTANCE && abs(coordinates_enemy.y - coordinates_player.y) <= DISTANCE);
 	mapLayout[coordinates_player.x][coordinates_player.y] = PLAYER;
 	mapLayout[coordinates_enemy.x][coordinates_enemy.y] = ENEMY;
 }

 tCoordinates position (int mapLayout[MAX_X][MAX_Y] {
	int exit, i;
	tCoordinates coordinates;
	do {
		for (i = 1; i <= 2; i++) {
			srand (time (NULL) + i);
			if (i == 1) { // if it is the first round, generate the X position
			coordinates.x = rand () % (MAX_X + 1);
			}
			else { // else, generate the Y position
			coordinates.y = rand () % (MAX_Y + 1);
 			}
 		}
 		if (mapLayout[coordinates.x][coordinates.y] == 0) { //confirms that the generated position is on the ground and not in sky.
 			exit = 1;
 		}
 		else {
 			exit == 0
 		}
 	}
 	while (exit != 1);
 	return coordinates;
 }
