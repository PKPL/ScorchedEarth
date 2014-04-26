//---------------------------- Draw maps ---------------------------------
// Drawing maps
//------------------------------------------------------------------------

#include "drawing_maps.h"

extern int map_layout [MAX_X][MAX_Y];


void test_drawing_map (int map_layout [MAX_X][MAX_Y])
{
    double x0;
    double y0;

    system("mode 100, 80");
    //drawing_game_screen();
    for (y0 = 0.0 ; y0 < MAX_Y; y0++)
    {
        for (x0 = 0.0; x0 < MAX_X; x0++)
        {
            gotoxy((int)x0, 80 - (int)y0);
            if(map_layout[(int)x0][(int)y0] != 0)
            {
                printf("%d", map_layout[(int)x0][(int)y0]);
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
