//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------

#include "drawing_units.h"


extern int map_layout [MAX_X][MAX_Y];


void test_drawing_units (int map_layout[MAX_X][MAX_Y])
{
    drawing_units(map_layout);
}

void drawing_units (int map_layout[MAX_X][MAX_Y])
{
    tCoordinates coordinates_player, coordinates_enemy;
    do
    {
        coordinates_player = position (map_layout);
        coordinates_enemy = position (map_layout);
        if (abs(coordinates_enemy.x - coordinates_player.x) <= DISTANCE && abs(coordinates_enemy.y - coordinates_player.y) <= DISTANCE) {
            map_layout[coordinates_player.x][coordinates_player.y] = 1;
            map_layout[coordinates_enemy.x][coordinates_enemy.y] = 1;
        }
    }
    while (abs(coordinates_enemy.x - coordinates_player.x) <= DISTANCE && abs(coordinates_enemy.y - coordinates_player.y) <= DISTANCE);
    map_layout[coordinates_player.x][coordinates_player.y] = PLAYER;
    map_layout[coordinates_enemy.x][coordinates_enemy.y] = ENEMY;
}

tCoordinates position (int map_layout[MAX_X][MAX_Y])
{
    int i;
    tCoordinates coordinates;
        coordinates.x = coordinates.x = rand () % (MAX_X + 1);
        for (i = 0; i < MAX_Y; i++) {
            srand (time (NULL));
            if (map_layout[coordinates.x][i] == 0) {
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

