//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------

#include "drawing_units.h"

void test_drawing_units (int mapLayout[MAX_X][MAX_Y])
{
    drawing_units(mapLayout);
    //drawMap(mapLayout);
}

void drawing_units (int mapLayout[MAX_X][MAX_Y])
{
    tCoordinates coordinates_player, coordinates_enemy;
    do
    {
        coordinates_player = position (mapLayout);
        coordinates_enemy = position (mapLayout);
        if (abs(coordinates_enemy.x - coordinates_player.x) <= DISTANCE && abs(coordinates_enemy.y - coordinates_player.y) <= DISTANCE) {
            mapLayout[coordinates_player.x][coordinates_player.y] = 1;
            mapLayout[coordinates_enemy.x][coordinates_enemy.y] = 1;
        }
    }
    while (abs(coordinates_enemy.x - coordinates_player.x) <= DISTANCE && abs(coordinates_enemy.y - coordinates_player.y) <= DISTANCE);
    mapLayout[coordinates_player.x][coordinates_player.y] = PLAYER;
    mapLayout[coordinates_enemy.x][coordinates_enemy.y] = ENEMY;
}

tCoordinates position (int mapLayout[MAX_X][MAX_Y])
{
    int i;
    tCoordinates coordinates;
        coordinates.x = coordinates.x = rand () % (MAX_X + 1);
        for (i = 0; i < MAX_Y; i++) {
            srand (time (NULL));
            if (mapLayout[coordinates.x][i] == 0) {
                continue;
            }
            else
            {
                coordinates.y = i;
                break;
            }
        }
    return coordinates;
}

