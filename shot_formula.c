//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include <stdio.h>
#include <stdlib.h>
#include "final_equation.h"

void formula () {

    missile_data *missile;

    missile = initializeMissile();

    setTime();
    setWindSpeed();
    setShootingAngle(missile);
    setInitialVelocity(missile);

    xVelocityFormula(missile);
    yVelocityFormula(missile);
    getchar();
    xCoordinate(missile);
    yCoordinate(missile);


    printMissileData(missile);
    getchar();

    printf("X velocity values:\n");
    printFloatVector(missile->x_vector_velocity, LENGTH);
    printf("\nY velocity values:\n");
    printFloatVector(missile->y_vector_velocity, HEIGHT);
    getchar();

    printf("\nX coordinates:\n");
    printIntVector(missile->x_vector_coordinate, LENGTH);
    printf("\nY coordinates:\n");
    printIntVector(missile->y_vector_coordinate, HEIGHT);
    printf("\n");

    free(missile);

}