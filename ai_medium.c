//---------------------------- AI Medium level ---------------------------
// AI for medium level
//------------------------------------------------------------------------

#include "ai.h"
#include "ai_medium.h"
#include "unit.h"
#include "shot_final_equation.h" // place where bot's missle will be calculated (?)
#include "maps_create.h"
#include <stdbool.h>

extern int destruct_radius;
static float medium_dec_range = 10;
int ai_angle = 180;

void ai_easy(unit local_bot, int map_layout[MAX_X][MAX_Y])
{

    int mini_angle = min_angle(local_bot);//searching for minimal angle
    int maxi_angle = 90;
    int ai_shoot_angle;

    while(true)
    {


       ai_shoot_angle = find_random(mini_angle,maxi_angle);
       if(player.x < local_bot.x)ai_shoot_angle = 180 - ai_shoot_angle;
       break;
       //if(raycast(local_bot, ai_shoot_angle, map_layout[MAX_X][MAX_Y]) == false)break;
    }


    int ai_shoot_power = find_random(1,100);
    //printf("ai_shoot angle = %d ai_shoot_power = %d",ai_shoot_angle,ai_shoot_power );
    //in easy AI, shoot angle and shoot velocity (power) is random
    //take_a_shot(bot.x,bot.y,ai_shoot_angle,ai_shoot_power);
    //we are waiting for complex function which take a shoot from given arguments like coords of unit, angle and power of the shoot
    //testShot(ENEMY, ai_shoot_power, ai_shoot_angle, local_bot.x, local_bot.y);


    missile_data *missile;
    missile = initializeMissile(local_bot.x, local_bot.y);
    playerShot(missile, ai_shoot_power, ai_shoot_angle, map_layout,false);


}


void ai_medium(unit local_bot, int map_layout[MAX_X][MAX_Y])
{

int power;
gotoxy(20,25);
printf("ai angle = %d", ai_angle);

power = -1;
//gotoxy(10,29);
while(power == -1)
{
ai_angle --;
if(ai_angle <= 50)
{
    ai_angle = 180;
}
power = AIcheck (local_bot.x, local_bot.y, 1.8, ai_angle, player.x, player.y);
//gotoxy(10,29);
//printf("angle = %d", angle);

}
missile_data *missile;
    missile = initializeMissile(local_bot.x, local_bot.y);
gotoxy(20,26);
printf("ai angle = %d", ai_angle);
gotoxy(20,27);
printf("paler = %d", power);

int rnd = find_random(-5,5);
gotoxy(20,28);
printf("rnd = %d",rnd);




    playerShot(missile, (power + rnd) * 4, 180 - ai_angle, map_layout,false);
}

void ai_hard(unit local_bot, int map_layout[MAX_X][MAX_Y])
{

int power;


power = -1;

while(power == -1)
{
ai_angle --;
if(ai_angle <= 50)
{
    ai_angle = 180;
}
power = AIcheck (local_bot.x, local_bot.y, 1.8, ai_angle, player.x, player.y);


}
missile_data *missile;
    missile = initializeMissile(local_bot.x, local_bot.y);

int rnd = find_random(-5,5);

    playerShot(missile, (power + rnd) * 4, 180 - ai_angle, map_layout,false);
}




