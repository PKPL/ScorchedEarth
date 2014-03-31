//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include "shot_formula.h"

void formula() {

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
    getchar();
    xCoordinate(missile);
    yCoordinate(missile);

    /*Following cycle controls if the projectile hits anything before going out of the map; if so, functions checking what was hit are called
    It never checks if projectile outgoes the map on the bottom (y coordinate < 0), supposing that ground covers all of the map length; if not, please let us know! */
    for (i = 0; i < VECTOR_LENGTH; i++) {
        if (missile->y_vector_coordinate[i] > HEIGHT) continue; //If the projectile outgoes map height without hitting anything, it waits for it to enter again in the map
        if (missile->x_vector_coordinate[i] >= LENGTH || missile->x_vector_coordinate[i] < 0) break; //If the projectile outgoes map length (either on the left or right side) without hitting anything, the shot goes lost
        //Following functions are still to be developed fully
        if (matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] == 1) { //Projectile hits ground
            shotHit(missile, 1, i); //Under development in shot_hit.c and .h
            break;
        }
        if (matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] == 10 || matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] == 20) { //Projectile hits unit (either player's ones or enemy's ones)
            shotHit(missile, 2, i); //As above
            break;
        }
        matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] = 5; //If projectile doesn't hit ground or unit, the point considered in the matrix becomes trajectory of the missile (we didn't use 50 or 60 purely for a graphic advantage during testing)
    }

    //printMissileData(missile);
    //getchar();
    print_matrix();
    /*printf("X velocity values:\n");
    printFloatVector(missile->x_vector_velocity, VECTOR_LENGTH);
    printf("\nY velocity values:\n");
    printFloatVector(missile->y_vector_velocity, VECTOR_LENGTH);
    getchar();*/

    printf("\nX coordinates:\n");
    printIntVector(missile->x_vector_coordinate, VECTOR_LENGTH);
    printf("\nY coordinates:\n");
    printIntVector(missile->y_vector_coordinate, VECTOR_LENGTH);
    printf("\n");

    free(missile);


}
