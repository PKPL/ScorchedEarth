//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include "shot_formula.h"
#include "drawing_destruction.h"
#include "drawing_shots.h"
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
    int flag = 0;
    for (i = 0; i < VECTOR_LENGTH; i++){

        switch (checkHit(i, missile)) {
            case 0: continue;
            case 1: break;
            case 2: /*explosion: hit ground*/
                    createExplosion(matrix); //connection with drawing_destruction.c
                    flag=1;
                    break;
            case 3: /*explosion: hit unit*/
                //Call function Destruction of Unit or similar.
                flag=1;
                break;
            case 4:
                drawing_shots(matrix,missile);
              //  matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] = 5; // This print shot Parabola on ITALIAN TEAM MATRIX, for now just let it in comment.
                break;
        }

        createDestruction(matrix);

        if ( flag == 1 ) break;
    }
    print_matrix();

    return missile;

}
