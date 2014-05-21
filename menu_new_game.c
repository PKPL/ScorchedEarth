//---------------------------- New game ----------------------------------
// Start new game
//------------------------------------------------------------------------

#include "menu_new_game.h"
#include "levels_level.h"
#include "drawing_units.h"
#include "unit.h"
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include "shot.h"
#include "ai.h"
#include "sauron.h"
#include "menu_highscore.h"
#include "shot_final_equation.h"

#define PI 3.14159265

int screen_bufor [MAX_X][MAX_Y];
unit player;
unit bot;
int angle_points[3][2];
bool first_angle = true;
float angle_drawing_distanse = 5;

void game_loop(int map_layout [MAX_X][MAX_Y], bool game_loaded, bool map_loaded)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    int c = '\13\n';
    system("cls");
    unit_func(&player);
    unit_func(&bot);

    CONSOLE_CURSOR_INFO CurInfo;
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);

    int i;
    int queue = 1; //1 - Player, 2 - Bot
    int max_players = 2;
    int key_pressed;
    int missile_option = 1; // the missile you want to use. 1 set as default
    int player_angle = 60;
    int player_power = 100;
    int draw_hp;
    int armors[NUMBER_OF_ARMORS] = {1};
    bool first_frame = 1; // thanks to this bool, map, draws only once
    bool quit = false;
    bool playerTurn = 1; // it should be an option to choose - who will begin the game - player or ai?
    bool saved = false;
    char missile_name[7]; // the name of the missile you are using

    //if(selected_level.level_ai != PVP_MODE )ai(bot, map_layout); // chain of few functions, which ends with calling function playerShot()
    //else
    //{
    int bot_angle = 180-60;
    int bot_power = 100;
    //}


    if (game_loaded == false)
    {
        drawing_units(map_layout, &player, &bot);
        drawing_armors(map_layout, NUMBER_OF_ARMORS);
    }

    while(player.hp > 0 && bot.hp > 0)
    {

        if(quit == false && first_frame == 1)
        {
            drawing_map(map_layout);
            if (game_loaded == false && map_loaded == false)
            {
                map_layout[bot.x][bot.y] = 1;
                map_layout[player.x][player.y] = 1;
                save_map(map_layout);
                system("cls");
                map_layout[bot.x][bot.y] = 2;
                map_layout[player.x][player.y] = 3;
                drawing_map(map_layout);
            }
            first_frame = 0;
            printf("\n\n");
        }


        while(playerTurn)
        {
            while(kbhit())getch();
            if(quit == true)break;
            //Player move


            //Choose power and angle
            information(player_power, player_angle);
            angle_drawing_distanse = player_power/20;


            //Drawing angle tray
            if(first_angle == true)
            {
                int i;
                for(i = 0; i < 3; i++)
                {
                    angle_points[i][0] = player.x + (int)angle_drawing_distanse*(i+1)*cos(player_angle * PI / 180.0 );
                    angle_points[i][1] = 79 - (player.y + (int)angle_drawing_distanse*(i+1)*sin(player_angle * PI / 180.0 ));
                    if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                    {
                        gotoxy(angle_points[i][0],angle_points[i][1]);
                        printf(".");
                    }
                }
                first_angle = false;

            }
            else
            {
                int i;
                for(i = 0; i < 3; i++)
                {
                    if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                    {


                        int xxx = map_layout[angle_points[i][0]][79-angle_points[i][1]];
                        gotoxy(angle_points[i][0],angle_points[i][1]);
                        switch(xxx)
                        {
                        case 0:
                            printf(" ");
                            break;
                        case 1:
                            printf("1");
                            break;
//                            default: printf(" "); break;
                        }

                    }

                }


                for(i = 0; i < 3; i++)
                {
                    angle_points[i][0] = player.x + (int)angle_drawing_distanse*(i+1)*cos(player_angle * PI / 180.0 );
                    angle_points[i][1] = 79 - (player.y + (int)angle_drawing_distanse*(i+1)*sin(player_angle * PI / 180.0 ));
                    if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                    {
                        gotoxy(angle_points[i][0],angle_points[i][1]);
                        printf(".");
                    }
                }

            }
            //------------------

            key_pressed = getch();
            if (key_pressed == 32)
            {
                sauron_creation(map_layout, &bot);
                falling(map_layout);
                if(player.hp <= 0)quit=true;
                else sauron_destruction(map_layout, &bot);
            }

            if(key_pressed == 27)
            {
                system("cls");
                saved = save_game(map_layout, selected_level, player, bot, wind_speed);
                quit = true;
            }
            if(key_pressed == 13)
            {
                missile_data *missile;
                missile = initializeMissile(player.x, player.y, missile_option);
                playerShot(missile, player_power, player_angle, map_layout,false, wind_speed, ai_angle);
                falling(map_layout);

                playerTurn = false;

            }

            if(key_pressed == 49)
                missile_option = 1;

            if(key_pressed == 50)
                missile_option = 2;

            if(key_pressed == 51)
                missile_option = 3;

            else switch(getch())
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
                    if(player_angle > 0)player_angle = player_angle - 1;
                    break;
                }
                information(player_power, player_angle);
        }

        angle_drawing_distanse = player_power/20;


        if(quit == true)break;
        if(bot.hp <= 0 || player.hp <= 0)break;
        //-----------------------------------end of player's turn

        //Sleep(2000); comented cuz now, sometimes ai need some time to find good velo
        if(selected_level.level_ai != PVP_MODE )
        {
            ai(bot, map_layout); // chain of few functions, which ends with calling function playerShot()
        }
        else
        {
            while(!playerTurn)
            {
                while(kbhit())getch();
                if(quit == true)break;
                //Player move


                //Choose power and angle
                information(player_power, player_angle);
                angle_drawing_distanse = player_power/20;

                //Drawing angle tray
                if(first_angle == true)
                {
                    int i;
                    for(i = 0; i < 3; i++)
                    {
                        angle_points[i][0] = bot.x + (int)angle_drawing_distanse*(i+1)*cos(bot_angle * PI / 180.0 );
                        angle_points[i][1] = 79 - (bot.y + (int)angle_drawing_distanse*(i+1)*sin(bot_angle * PI / 180.0 ));
                        if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                        {
                            gotoxy(angle_points[i][0],angle_points[i][1]);
                            printf(".");
                        }
                    }
                    first_angle = false;

                }
                else
                {
                    int i;
                    for(i = 0; i < 3; i++)
                    {
                        if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                        {


                            int xxx = map_layout[angle_points[i][0]][79-angle_points[i][1]];
                            gotoxy(angle_points[i][0],angle_points[i][1]);
                            switch(xxx)
                            {
                            case 0:
                                printf(" ");
                                break;
                            case 1:
                                printf("1");
                                break;
                            case 4:
                                printf("4");
                                break;
//                            default: printf(" "); break;
                            }

                        }

                    }


                    for(i = 0; i < 3; i++)
                    {
                        angle_points[i][0] = bot.x + (int)angle_drawing_distanse*(i+1)*cos(bot_angle * PI / 180.0 );
                        angle_points[i][1] = 79 - (bot.y + (int)angle_drawing_distanse*(i+1)*sin(bot_angle * PI / 180.0 ));
                        if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                        {
                            gotoxy(angle_points[i][0],angle_points[i][1]);
                            printf(".");
                        }
                    }

                }
                //------------------

                key_pressed = getch();
                if (key_pressed == 32)
                {
                    sauron_creation(map_layout, &bot);
                    falling(map_layout);
                    if(player.hp <= 0)quit=true;
                    else sauron_destruction(map_layout, &bot);
                }

                if(key_pressed == 27)
                {
                    saved = save_game(map_layout, selected_level, player, bot, wind_speed);
                    quit = true;
                    if(key_pressed == 13)
                    {
                        missile_data *missile;
                        missile = initializeMissile(bot.x, bot.y, missile_option);
                        playerShot(missile, bot_power, bot_angle, map_layout,false, wind_speed, ai_angle);
                        falling(map_layout);

                        playerTurn = true;

                    }
                    else switch(getch())

                        {
                        case 72:
                            if(player_angle < 180)bot_angle = bot_angle + 1;
                            break;

                        case 75:
                            if(player_power > 0)bot_power = bot_power - 1;
                            break;

                        case 77:
                            if(player_power < 200)bot_power = bot_power + 1;
                            break;

                        case 80:
                            if(player_angle > 0)bot_angle = bot_angle - 1;
                            break;
                        }
                }
            }
        }
        falling(map_layout);


        //------------------------------------end of bots' turn
        if(selected_level.level_wind == WIND_VARIABLE)wind_speed = random_wind(); //Generate new wind force

        Sleep(1000);
        playerTurn = true;
        if(player.y == 0)player.hp=0;
        if(bot.y == 0)bot.hp=0;
    }//end of main loop



    if(bot.hp <= 0)
    {
        player_highscore players[11];
        players[10].points=player.points;
        add_score(players );

        if(selected_level.level_ai != PVP_MODE )
        {
            //Inform about victory
            gotoxy(30,20);
            printf("VICTORY");
            gotoxy(30,21);
            printf("Press any button to go to the menu");
            getch();
            menu();
        }
        else
        {
            gotoxy(30,20);
            printf("Left player won!!!");
            gotoxy(30,21);
            printf("Press any button to go to the menu");
            getch();
            menu();
        }


        //--------------------

        //Back to menu

        //------------
    }

    else if(player.hp <= 0 || key_pressed == 27)
    {
        //Inform about defeat

        //--------------------

        if(selected_level.level_ai != PVP_MODE )
        {
            //Inform about victory

            if (!saved) {
                gotoxy(30,20);
                printf("DEFEAT");
            }
            gotoxy(30,21);
            printf("Press any button to go to the menu");
            getch();
            menu();
        }
        else
        {
            gotoxy(30,20);
            printf("Right player won!!!");
            gotoxy(30,21);
            printf("Press any button to go to the menu");
            getch();
            menu();
        }

        //------------
    }
}

