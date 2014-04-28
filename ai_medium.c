//---------------------------- AI Medium level ---------------------------
// AI for medium level
//------------------------------------------------------------------------

#include "ai_medium.h"
#include "ai.h"
#include "unit.h"
#include "shot_final_equation.h" // place where bot's missle will be calculated (?)
#include "maps_create.h"
#include <stdbool.h>

int medium_dec_range = 10;

int min_power(unit from, int angle)
{
    int min_power_x;
    int min_power_value;
    if(player.x > from.x)min_power_x = player.x - medium_dec_range;
    else if(player.x < from.x)min_power_x = player.x + medium_dec_range;

    //Now we must calculate power to hit the min_power_x, and return it to min_power_value
    return min_power_value;
}

int max_power(unit from, int angle)
{
    int max_power_x;
    int max_power_value;
    if(player.x > from.x)max_power_x = player.x + medium_dec_range;
    else if(player.x < from.x)max_power_x = player.x - medium_dec_range;

    //Now we must calculate power to hit the min_power_x, and return it to min_power_value
    return max_power_value;
}

void ai_medium(unit local_bot, int mapLayout[MAX_X][MAX_Y])
{
    int mini_angle = min_angle(local_bot);//searching for minimal angle
    int maxi_angle = 90;
    int ai_shoot_angle;
    while(true)
    {
       ai_shoot_angle = find_random(mini_angle,maxi_angle);
       if(player.x > local_bot.x)ai_shoot_angle = 180 - ai_shoot_angle;
       if(raycast(local_bot, ai_shoot_angle, mapLayout[MAX_X][MAX_Y]) == false)break;
    }

    int ai_shoot_power = find_random(min_power(local_bot, ai_shoot_angle),max_power(local_bot, ai_shoot_angle));
    printf("ai_shoot angle = %f ai_shoot_power = %f",ai_shoot_angle,ai_shoot_power );
    medium_dec_range = medium_dec_range - 1;
    //in easy AI, shoot angle and shoot velocity (power) is random
    //take_a_shot(bot.x,bot.y,ai_shoot_angle,ai_shoot_power);
    //we are waiting for complex function which take a shoot from given arguments like coords of unit, angle and power of the shoot

}
