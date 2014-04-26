// On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

//IMPORTANT: ALL OF THE FOLLOWING CODE IS NOT WORKING!
//That is because some arguments of functions are either missing or it is not clear yet how/where they are determined
//Sorry for changes but i just want to end that problem :D £ukasz Czechowicz

#include "shot.h"

int testShot (int who_is_shooting, int ai_init_velocity, int ai_shoot_angle, int x_coord, int y_coord) {

    int ai_shoot_instant = -1;
    missile_data *missile;

    initializeMissile(missile, x_coord, y_coord);

    if (who_is_shooting == PLAYER)
        playerShot(missile);

    else if (who_is_shooting == ENEMY) {
        ai_shoot_instant = AIShoot(missile, ai_init_velocity, ai_shoot_angle);
    }

    free(missile);
    return ai_shoot_instant;

}


