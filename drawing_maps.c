//---------------------------- Draw maps ---------------------------------
// Drawing maps
//------------------------------------------------------------------------

#include "drawing_maps.h"
#include <windows.h>



extern int map_layout [MAX_X][MAX_Y];


void test_drawing_map (int map_layout [MAX_X][MAX_Y])
{
    double x;
    double y;


    //drawing_game_screen();
    for (x = 0.0; x < MAX_X; x++)
    {
        for (y = 0.0; y < MAX_Y; y++)
        {
            gotoxy((int)x, 79 - (int)y);
            if (map_layout[(int)x][(int)y] != 0)
            {
                printf("%d", map_layout[(int)x][(int)y]);
            }
        }
    }
    gotoxy(0, 79);

}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawing_game_screen() //the parameters will be the info needed
{
    int i;

    for (i = 0; i < (MAX_X + 4); i++) // first frame row
    {
        printf("_");
    }

//    printf("\n|\tWind direction:\t%d\tPlayer:\t%s\t",&wind_direction_angle, &player_name ); // I guess it will be like this, so i set these variables example

//    printf("\n|\tWind force:\t%dMissile:\t%s\t",&wind_force, &missile_data.name );

    for (i = 0; i < (MAX_X + 4); i++) // last frame row
    {
        printf("_");
    }

}
