//---------------------------- Draw destructions -------------------------
// Drawing destructions
// NUNO VALENTE
// PORTUGUESE TEAM
//------------------------------------------------------------------------


#include "drawing_destruction.h"
#include "drawing_shots.h"
#include <math.h>


extern int map_layout [MAX_X][MAX_Y];
int destruct_radius = 4;


void test_drawing_destruction(int map_layout [MAX_X][MAX_Y])
{
    //create_explosion(map_layout,); //Draws the explosion
    create_destruction(map_layout); //Draws the destruction
}

void create_destruction(int map_layout [MAX_X][MAX_Y])
{
    int x, y;
    int breaks_loop = 0;


    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            if (map_layout[x][y] == 50 && map_layout[x][y-1] == 1) //This means this is the final position of the player projectile, as below it there is ground, so it hits the ground
            {
                map_layout[x][y] = 0;

                if ((x - 1) >= 0)
                {
                    map_layout[x-1][y] = 0;
                }

                if ((x + 1) <= MAX_X)
                {
                    map_layout[x+1][y] = 0;
                }

                if ((y + 1) <= MAX_Y)
                {
                    map_layout[x][y+1] = 0;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    map_layout[x-1][y+1] = 0;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    map_layout[x+1][y+1] = 0;
                }
                //The code above restores the explosion to empty


                if ((y - 1) >= 0)
                {
                    map_layout[x][y-1] = 0;
                }

                if ((x - 1) >= 0 && (y - 1) >= 0)
                {
                    map_layout[x-1][y-1] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 1) >= 0)
                {
                    map_layout[x+1][y-1] = 0;
                }

                if ((y - 2) >= 0)
                {
                    map_layout[x][y-2] = 0;
                }

                if ((x - 1) >= 0 && (y - 2) >= 0)
                {
                    map_layout[x-1][y-2] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 2) >= 0)
                {
                    map_layout[x+1][y-2] = 0;
                }

                y = MAX_Y;
                breaks_loop = 1;

                //The code above destroys terrain
            }
            else if (map_layout[x][y] == 60 && map_layout[x][y-1] == 1) //This means this is the final position of the enemy projectile, as below it there is ground, so it hits the ground
            {
                map_layout[x][y] = 0;

                if ((x - 1) >= 0)
                {
                    map_layout[x-1][y] = 0;
                }

                if ((x + 1) <= MAX_X)
                {
                    map_layout[x+1][y] = 0;
                }

                if ((y + 1) <= MAX_Y)
                {
                    map_layout[x][y+1] = 0;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    map_layout[x-1][y+1] = 0;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    map_layout[x+1][y+1] = 0;
                }
                //The code above restores the explosion to empty


                if ((y - 1) >= 0)
                {
                    map_layout[x][y-1] = 0;
                }

                if ((x - 1) >= 0 && (y - 1) >= 0)
                {
                    map_layout[x-1][y-1] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 1) >= 0)
                {
                    map_layout[x+1][y-1] = 0;
                }

                if ((y - 2) >= 0)
                {
                    map_layout[x][y-2] = 0;
                }

                if ((x - 1) >= 0 && (y - 2) >= 0)
                {
                    map_layout[x-1][y-2] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 2) >= 0)
                {
                    map_layout[x+1][y-2] = 0;
                }

                y = MAX_Y;
                breaks_loop = 1;

                //The code above destroys terrain
            }

            if (breaks_loop == 1)
            {
                x = MAX_X;
            }
        }
    }
}

void create_explosion(int map_layout[MAX_X][MAX_Y],missile_data *m,int number, bool isBot, bool hit_unit, int hit)
{
    int x_pos = (int)m->x_vector_coordinate[number];
    int y_pos = (int)m->y_vector_coordinate[number];

    int damage;
    int check = 0;

    int i,j, h,h_x, h_y;
    int error = 0;
    if (number % 2 != 1 && number % 2 != 0)
    {
        error = 1;
        printf("One of the parameters' content is different than expected.\n");
    }
    if (error != 1)
    {
        for(i = 0; i < MAX_X; i++)
        {
            for(j = 0; j < MAX_Y; j++)
            {
                h_x = x_pos - i;
                h_y = y_pos - j;
                h = sqrt(h_x*h_x + h_y*h_y);
                if(h <= destruct_radius && map_layout[i][j] < 2)
                {
                    map_layout[i][j] = 0;
                    gotoxy(i,79 - j);
                    printf(" ");
                }
                else
                {
                    damage = m->unit_damage;
                    if (hit == 1)
                        check = 1;
                    if(h <= destruct_radius && map_layout[i][j] == 3) {
                        if (hit_unit == false)
                            damage = m->unit_damage / 2;

                        if (player.armor <= 0)
                            player.hp -= damage;
                        else if (player.armor > 0) {
                            player.armor -= damage;
                            if (player.armor < 0)
                                player.hp += player.armor;
                        }
                    }
                    else if (h <= destruct_radius)
                    {
                        if (bot.armor <= 0)
                            bot.hp -= damage;
                        else if (bot.armor > 0) {
                            bot.armor -= damage;
                            if (bot.armor < 0)
                                bot.hp += damage;
                    }
                }
            }
        }
    }
    if (isBot == false) {
        if (hit_unit == true) {
            if (hit == ENEMY && bot.armor <= 0)
                player.points += 50;
            else if (hit == ENEMY && bot.armor > 0)
                player.points += 40;
        }
        else if (hit_unit == false) {
            if (check == 1 && bot.armor <= 0 && hit == ENEMY)
                player.points += 30;
            else if (check == 1 && bot.armor > 0 && hit == ENEMY)
                player.points += 20;
            else if (hit == 1)
                player.points += 5;
        }
    }

    }

}
