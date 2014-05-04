//---------------------------- AI Medium level ---------------------------
// AI for medium level
//------------------------------------------------------------------------

#include "ai.h"
#include "ai_medium.h"
#include "unit.h"
#include "shot_final_equation.h" // place where bot's missle will be calculated (?)
#include "maps_create.h"
#include <stdbool.h>

static int medium_dec_range = 10;

void ai_medium(unit local_bot, int map_layout[MAX_X][MAX_Y])
{
    int mini_angle = min_angle(local_bot);//searching for minimal angle
    int maxi_angle = 90;
    int ai_shoot_angle;
    while(true)
    {
       ai_shoot_angle = find_random(mini_angle,maxi_angle);
       if(player.x > local_bot.x)ai_shoot_angle = 180 - ai_shoot_angle;
       if(raycast(local_bot, ai_shoot_angle, map_layout[MAX_X][MAX_Y]) == false)break;
    }

    float perfect_power = AIcheck(local_bot.x, local_bot.y, 1.8, ai_shoot_angle, player.x, player.y);
    float min_power = perfect_power - medium_dec_range;
    float max_power = perfect_power + medium_dec_range;

    int ai_shoot_power = find_random(min_power,max_power);
    if(medium_dec_range > 2)medium_dec_range = medium_dec_range - 2;
    //in easy AI, shoot angle and shoot velocity (power) is random
    //take_a_shot(bot.x,bot.y,ai_shoot_angle,ai_shoot_power);
    //we are waiting for complex function which take a shoot from given arguments like coords of unit, angle and power of the shoot
    testShot(ENEMY, (int)ai_shoot_power, ai_shoot_angle, local_bot.x, local_bot.y, map_layout);


}
