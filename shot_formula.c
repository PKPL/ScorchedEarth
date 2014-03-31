//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include "shot_formula.h"
#include "matrix.h"
#include "shot_final_equation.h"
#include <stdio.h>
#include <stdlib.h>

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
    for (i = 0; i < VECTOR_LENGTH; i++) {
        if (missile->y_vector_coordinate[i] > HEIGHT || missile->x_vector_coordinate[i] > LENGTH || missile->y_vector_coordinate[i] < 0 || missile->x_vector_coordinate[i] < 0) continue;
        matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] = 5;
    } // we use number 5 because we need to difference ground ( that is 1 ) and not 50 becuse the "drawing" could be shifted.
    
    
    
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
