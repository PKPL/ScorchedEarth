//---------------------------- Draw maps ---------------------------------
// Drawing maps
// NUNO VALENTE
// DANIEL PINTO
// PORTUGUESE TEAM
//------------------------------------------------------------------------

#include "drawing_maps.h"
#include <windows.h>
#include "unit.h"



extern int map_layout [MAX_X][MAX_Y];
extern float wind_speed;

void drawing_map (int map_layout [MAX_X][MAX_Y])
{
    double x;
    double y;
    int i, j;
    int error = 0;

    for (i = 0; i < MAX_X; i++)
    {
        for (j = 0; j < MAX_Y; j++)
        {
            if (map_layout [i][j] % 2 != 1 && map_layout [i][j] % 2 != 0)
            {
                error = 1;
                printf("Map generation error. Contents of array different than expected.\n");
                i = MAX_X;
                j = MAX_Y;
            }
        }
    }
    if (error != 1) {
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

void falling(int map_layout[MAX_X][MAX_Y])
{
    int i, j;

    Sleep (7);
    for(i = 0; i < MAX_X; i++)
    {
        for(j = MAX_Y - 1; j > 0; j--)
        {
            if(map_layout[i][j] != 0 && map_layout[i][j-1] == 0 && map_layout[i][j] != 4)
            {
                //Sleep(10);
                if(map_layout[i][j] == 3)player.y--;
                else if(map_layout[i][j] == 2)bot.y--;
                map_layout[i][j-1] = map_layout[i][j];
                map_layout[i][j] = 0;
                gotoxy(i,79-j + 1);
                printf("%d", map_layout[i][j-1]);
                gotoxy(i,79-j);
                printf(" ");
//                Sleep(0.5);
                j = MAX_Y;
            }
        }
//        Sleep(10);
    }
}

void information(int pl_pow, int pl_ang, char missile_name[])
{
    int i;
    int draw_stuff;
    gotoxy(0,80);
            printf("            ");
            gotoxy(0,80);
            printf("Angle = %d", pl_ang);
            gotoxy(20,80);
            printf("              ");
            gotoxy(20,80);
            printf("Power = %d", pl_pow);
            gotoxy(40,80);
            printf("          ");
            gotoxy(40,80);
            printf("Wind = %d", (int)wind_speed);
            gotoxy(60,80);
            printf("            ");
            gotoxy(60,80);
            printf("Points = %d", player.points);
            gotoxy(0,81);
            printf("                                      ");
            gotoxy(0,81);
            printf("Player HP = %d ", player.hp);
            for (draw_stuff = (player.hp)/10, i = 0; i < draw_stuff; i++)
                putchar(3);
            for (draw_stuff = 10-(player.hp/10), i = 0; i < draw_stuff; i++)
                putchar(' ');
            gotoxy(40,81);
            printf("              ");
            gotoxy(40,81);
            printf("Enemy HP = %d ", bot.hp);
            for (draw_stuff = (bot.hp)/10, i = 0; i < draw_stuff; i++)
                putchar(3);
            for (draw_stuff = 10-(bot.hp/10), i = 0; i < draw_stuff; i++)
                putchar(' ');
            gotoxy(0,82);
            printf("                                ");
            gotoxy(0,82);
            printf("Player armor = %d ", player.armor);
            for (draw_stuff = (player.armor)/10, i = 0; i < draw_stuff; i++)
                putchar('-');
            for (draw_stuff = 10-(player.armor/10), i = 0; i < draw_stuff; i++)
                putchar(' ');
            gotoxy(40,82);
            printf("                                ");
            gotoxy(40,82);
            printf("Enemy armor = %d ", bot.armor);
            for (draw_stuff = (bot.armor)/10, i = 0; i < draw_stuff; i++)
                putchar('-');
            for (draw_stuff = 10-(bot.armor/10), i = 0; i < draw_stuff; i++)
                putchar(' ');
            gotoxy(0,83);
            printf("Missile = %s", missile_name);

}
