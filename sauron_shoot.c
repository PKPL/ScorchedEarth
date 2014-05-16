#include "sauron_shoot.h"

void sauron_shoot(int map_layout[MAX_X][MAX_Y], tCoordinates position_left_8)
{

    int ray_height = 2;
    int x,y;

    int x0= position_left_8.x;
    int y0= position_left_8.y-1;

    for ( y = y0; y >= 0; y--)
    {
        for ( x = x0 ; x >= x0 - ray_height; x--)
        {
            if (x >= 0) {
            gotoxy(x, 79-y);
            if(map_layout[x][y] == 3)player.hp = 0;
            map_layout[x][y] = 0;
            printf(" ",map_layout[x][y]);
            Sleep(2);
            }
        }
        if (x0 >= 0) {
            x0 -= 1;
            ray_height ++ ;
        }
        else
            break;
    }
}
