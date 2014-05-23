//---------------------------- Artificial Inteligence --------------------
// It combines the files responsible for artificial inteligence
//------------------------------------------------------------------------
// Polish team is working on this file
// Included files
#include "ai.h"
#include "unit.h"
#include <math.h>
#include <stdlib.h>
#include "maps_create.h"
#include <stdbool.h>
#include <time.h>


float min_angle(unit local_bot)
{
    if(player.y > local_bot.y)return (atan((player.y-local_bot.y)/abs(player.x - local_bot.x)));
    return 0;
}

int find_random(int min_ang, int max_ang)
{
    srand ( time(NULL) );
    return  (rand() % (max_ang - min_ang) + min_ang);
}

bool raycast(unit from, int angle,  int map_layout[MAX_X][MAX_Y])
{
    int ray_length = 20;
    int i = 1;
    for(i = 1; i < ray_length; i++)
    {
        float local_x, local_y;

        local_x = cos(angle)*i;
        local_y = sin(angle)*i;

        int local_x_rounded = (int)(local_x + 0.5);
        int local_y_rounded = (int)(local_y + 0.5);

        if(from.x + local_x_rounded > MAX_X || from.y + local_y_rounded > MAX_Y) break;
        else if(map_layout[from.x + local_x_rounded][from.y + local_y_rounded] == 1)
        {
            return true;
        }

    }
    return false;
}


void ai(unit local_bot, int map_layout[MAX_X][MAX_Y])
{

    if(selected_level.level_ai == AI_EASY)ai_easy(local_bot, map_layout);
    else if(selected_level.level_ai == AI_MEDIUM)ai_medium(local_bot, map_layout);
    else if(selected_level.level_ai == AI_HARD)ai_hard(local_bot, map_layout,false);

}

int find_min_angle_fixed (int map_layout[MAX_X][MAX_Y], int Xturr,int Xtar, int Yturr)
{
    int x,y;
    int TMP_ownerHighestX = 0;
    int TMP_highestY = 0;
    int ownerHighestX = 0;
    int highestY = 0;
    float a,b;
    double frac;
    for(x=Xturr; x>=Xtar; x--)
    {
        for(y=0; y<MAX_Y; y++)
        {
            if(map_layout[x][y] == 1 && map_layout[x][y+1] ==0 )
            {
                TMP_ownerHighestX = x;
                TMP_highestY = y;
            }
        }
        if(TMP_highestY > highestY)
        {
            ownerHighestX = TMP_ownerHighestX;
            highestY = TMP_highestY;
        }
    }
    a = Xturr - ownerHighestX;
    b = highestY - Yturr;
    frac = b/a;

    double alpha = atan(frac);//*180/PI;//*180/PI;
    ;

//    gotoxy(30,26);
//    printf("do naj ogólnie = %d",alpha*10);
//    gotoxy(30,27);
//    printf("do naj ogólnie = %f",alpha*10);


/////////////////////////// already found highest
    TMP_ownerHighestX = 0;
    TMP_highestY = 0;
    ownerHighestX = 0;
    highestY = 0;
    int aux = Xturr-10;
    for(x = Xturr; x >= aux; x--)
    {
        for(y=0; y<MAX_Y; y++)
        {
            if(map_layout[x][y] == 1 && map_layout[x][y+1] ==0 )
            {
                TMP_ownerHighestX = x;
                TMP_highestY = y;
            }
        }
        if(TMP_highestY > highestY)
        {
            ownerHighestX = TMP_ownerHighestX;
            highestY = TMP_highestY;
        }
    }
    a = Xturr - ownerHighestX;
    b = highestY - Yturr;
    frac = b/a;
    double alpha2 = atan(frac);//*180/PI;//*180/PI;
//gotoxy(30,32);
//printf("alpha = %f",10 * alpha);
//gotoxy(30,33);
//printf("alpha2 = %f",10 * alpha2);

    if(alpha2>alpha) alpha2=alpha;
///////////////////////////////////////////
    return ((int)(20+(alpha*10)));
}
