//---------------------------- Draw units --------------------------------
// Drawing units
// DANIEL PINTO
// PORTUGUESE TEAM
//------------------------------------------------------------------------

#include "drawing_units.h"
#include "unit.h"
#include <time.h>
#include <math.h>


extern int map_layout [MAX_X][MAX_Y];


void test_drawing_units (int map_layout[MAX_X][MAX_Y])
{
    srand (time (NULL));
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

    player.x = coordinates_player.x;
    player.y = coordinates_player.y;
    bot.x = coordinates_enemy.x;
    bot.y = coordinates_enemy.y;

    int i,j;
    for(i = 0; i < MAX_X; i++)
    {
        for(j = 0; j < MAX_Y; j++)
        {
                if(j >= player.y && abs(i - player.x) <= 5 && map_layout[i][j] == 1)
                {
                 gotoxy(i, 79 - j);
                 map_layout[i][j] = 0;
                 printf(" ");
                }
        }

    }

    for(i = 0; i < MAX_X; i++)
    {
        for(j = 0; j < MAX_Y; j++)
        {
                if(j >= bot.y && abs(i - bot.x) <= 5 && map_layout[i][j] == 1)
                {
                 gotoxy(i, 79 - j);
                 map_layout[i][j] = 0;
                 printf(" ");
                }
        }

    }

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

