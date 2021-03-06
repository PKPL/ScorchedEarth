#include "sauron.h"
#include "drawing_units.h"

void sauron_creation(int map_layout[MAX_X][MAX_Y], unit *bot)
{
    int y;
    int x= bot->x ;
    int tempX = bot->x;

    tCoordinates position_left_8;

    x++;
    int athX = bot->x-1;

    for (y = bot->y; y <= (bot->y + sauron_height); y++)
    {
        if (y == bot->y + sauron_height)
        {
            constructor (bot->x, y, &map_layout[tempX][y], 8);
            tempX -= 4;
            y += 2;
            constructor(tempX,y, &map_layout[tempX][y],8);
            position_left_8.x = tempX;
            position_left_8.y = y;
            tempX += 8;
            constructor(tempX,y, &map_layout[tempX][y],8);
            tempX = bot->x;
            y += 2;
            constructor(tempX,y, &map_layout[tempX][y],8);
            break;
        }
        else
        {
            constructor (bot->x,y, &map_layout[bot->x][y], 7);
            constructor (x,y, &map_layout[x][y],7);
            constructor (athX,y, &map_layout[athX][y],7);

        }
    }
    sauron_shoot(map_layout, position_left_8);
}

void sauron_destruction (int map_layout[MAX_X][MAX_Y], unit *bot)
{
    int x, y;
    for (x = 0; x < MAX_X; x++)
    {
        for ( y = 0; y < MAX_Y; y++)
        {
            if (map_layout[x][y] == 7 || map_layout[x][y] == 8)
            {
                constructor(x, y, &map_layout[x][y], 0);
            }
        }
    }
    constructor(bot->x, bot->y, &map_layout[bot->x][bot->y], 2);
}

void constructor (int x, int y, int *pos, int number)
{
    if(x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
    {

    gotoxy(x, 79 - y);

    *pos = number;
    if ( number == 0)
    {
        printf (" ");
    }
    else
    {
        printf ("%d", number);
    }
    Sleep(40);
    }

}
