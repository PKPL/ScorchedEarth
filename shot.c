// On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

//IMPORTANT: ALL OF THE FOLLOWING CODE IS NOT WORKING!
//That is because some arguments of functions are either missing or it is not clear yet how/where they are determined
//Sorry for changes but i just want to end that problem :D £ukasz Czechowicz

#include "shot.h"

void testShot (int who_is_shooting, int ai_init_velocity, int ai_shoot_angle, int x_coord, int y_coord, float wind_speed/*where?*/) {

    missile_data *missile;
    missile = initializeMissile();

    if (who_is_shooting == PLAYER)
        missile = playerShot(missile, wind_speed);

    else if (who_is_shooting == ENEMY) {
        /* all the randomized stuff: ai_init_velocity, ai_shoot_angle, x_coord, y_coord, wind_speed
        CONNECTION WITH POLISH CODE, but there are things that are missing! */
       AIShoot(missile, ai_init_velocity, ai_shoot_angle, x_coord, y_coord, wind_speed);
    }

    free(missile);

}

