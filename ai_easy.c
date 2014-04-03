//---------------------------- AI Easy level -----------------------------
// AI for easy level
//------------------------------------------------------------------------

#include "ai_easy.h"
#include #include "shot_final_equation.h" // place where bot's missle will be calculated (?)


void ai_easy(unit bot)
{
    float min_angle = min_angle();//searching for minimal angle
    float max_angle = 90;
    float ai_shoot_angle = find_random(min_angle,max_angle);
    float ai_shoot_power = find_random(1,100);
    printf("ai_shoot angle = %f ai_shoot_power = %f",ai_shot_angle,ai_shot_power );
    //in easy AI, shoot angle and shoot velocity (power) is random
    //take_a_shot(bot.x,bot.y,ai_shoot_angle,ai_shoot_power);
    //we are waiting for complex function which take a shoot from given arguments like coords of unit, angle and power of the shoot

}
