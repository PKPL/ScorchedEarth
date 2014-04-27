// On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

#include "shot.h"

void testShot (int who_is_shooting, int ai_init_velocity, int ai_shoot_angle, int x_coord, int y_coord) {

    missile_data *missile;

    missile = initializeMissile(x_coord, y_coord);

    if (who_is_shooting == PLAYER)
        playerShot(missile);

    else if (who_is_shooting == ENEMY)
        AIShoot(missile, ai_init_velocity, ai_shoot_angle);

    free(missile);

}


