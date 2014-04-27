//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------

#include "drawing_units.h"
#include "unit.h"
#include <time.h>


extern int map_layout [MAX_X][MAX_Y];


void test_drawing_units (int map_layout[MAX_X][MAX_Y])
{
    srand (time (NULL));
    drawing_units(map_layout);
}

void drawing_units (int map_layout[MAX_X][MAX_Y])
{
    tCoordinates coordinates_player, coordinates_enemy;

    //Small changes to remember generated position in our global unit variables

    player.x = coordinates_player.x;
    player.y = coordinates_player.y;
    bot.x = coordinates_enemy.x;
    bot.y = coordinates_enemy.y;

    //-------------------------------------------------------------------------

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
    coordinates.x = rand () % (MAX_X) + 1;
        for (i = 0; i < MAX_Y; i++) { //Sorry for small change son my own i just reverse your "for" loop becouse it was working form te bottoem and units always was an the bottom :)
            if (map_layout[coordinates.x][i] == 1) {
                continue;
            }
            else
            {
                coordinates.y = i; // +1 to be on ground no in ground
                break;
            }
        }
    return coordinates;
}

