//---------------------------- New game ----------------------------------
// Start new game
//------------------------------------------------------------------------

#include "menu_new_game.h"
#include "levels_level.h"
#include "unit.h"
#include <conio.h>
#include <stdio.h>

int screen_bufor [MAX_X][MAX_Y];

void game_loop(int map_layout [MAX_X][MAX_Y])
{
    system("cls");

    unit_func();
    int queue = 1; //1 - Player, 2 - Bot
    int max_players = 2;
    int key_pressed;
    int player_angle = 0;
    int player_power = 100;

    test_drawing_map(map_layout);
    printf("\n\n");

    while(player.hp > 0 && bot.hp > 0)
    {
        //Main game loop :)

        if(queue == 1)
        {
            //Player move

                //Choose power and angle
                printf("Angle = %d", player_angle);
                printf("\t\tPower = %d", player_power);
                printf("\t\tWind = %d", (int)wind_speed);
                printf("\t\tPoints = %d", player.points);
                printf("\r");

                key_pressed = getch();
                if(key_pressed == 27)break;
                else if(key_pressed == 224)
                {
                    switch(getch())
                    {
                        case 72:
                        if(player_angle < 180)player_angle = player_angle + 1;
                        break;

                        case 75:
                        if(player_power > 0)player_power = player_power - 1;
                        break;

                        case 77:
                        if(player_power < 200)player_power = player_power + 1;
                        break;

                        case 80:
                        if(player_angle > -180)player_angle = player_angle - 1;
                        break;
                    }
                }


                //----------------------

                //Shooting with animation

                //-----------------------

            //-----------
        }

        else
        {
            //Bot move

                //Choose power and angle

                //----------------------

                //Shooting with animation

                //-----------------------

            //--------
        }

        queue = queue + 1;
        if(queue >= max_players)
        {
            queue = 1; //Returning to player move
            if(selected_level.level_wind == WIND_VARIABLE)wind_speed = random_wind(); //Generate new wind force
        }
        //-----------------
    }

    system("cls");
    if(player.hp > 0)
    {
        //Inform about victory

        //--------------------

        //Back to menu

        //------------
    }

    else if(bot.hp > 0 || key_pressed == 27)
    {
        //Inform about defeat

        //--------------------

        getch();

        //Back to menu

            system("cls");
            test_menu(map_layout);

        //------------
    }
}
