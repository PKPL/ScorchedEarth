// On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

#include "shot.h"
#include "maps_create.h"

void testShot (int who_is_shooting, int init_velocity, int shoot_angle, int x_coord, int y_coord, int map_layout[MAX_X][MAX_Y] ) {

    missile_data *missile;

    missile = initializeMissile(x_coord, y_coord);

    if (who_is_shooting == PLAYER)
        playerShot(missile, init_velocity, shoot_angle, map_layout);

    else if (who_is_shooting == ENEMY)
        AIShoot(missile, init_velocity, shoot_angle);

    free(missile);

}


