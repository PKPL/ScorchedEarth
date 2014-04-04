// On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

#include "shot.h"

void testShot (void) {

    missile_data *missile;

    init_matrix();

    missile = formula();

    free(missile);

}

