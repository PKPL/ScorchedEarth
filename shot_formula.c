//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include "shot_formula.h"

missile_data* formula() {

    int i;
    missile_data *missile;
    init_matrix();

    missile = initializeMissile();

    setTime();
    setWindSpeed();
    windForce();
    setShootingAngle(missile);
    setInitialVelocity(missile);

    xVelocityFormula(missile);
    yVelocityFormula(missile);
    xCoordinate(missile);
    yCoordinate(missile);

    /*Following cycle controls if the projectile hits anything before going out of the map; if so, functions checking what was hit are called*/
    for (i = 0; i < VECTOR_LENGTH; i++)
        switch (checkHit(i, missile)) {
            case 0: continue;
            case 1: break;
            case 2: /*explosion*/; break;
            case 3: /*explosion*/; break;
            case 4: matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] = 5; break;
        }

    print_matrix();

    return missile;

}
