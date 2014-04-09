//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include "shot_formula.h"


/* When a player shoots, the following function is called: it asks the player for all necessary data (shooting angle, initial velocity), then calculates the shot, checks the shot and, if possible, calls for explosion functions. */

missile_data* playerShot(missile_data *missile /*second argument: float wind_speed */) {

    int i, flag = 0;
    int shooting_angle = 0;
    float initial_velocity = 0;

    init_matrix();

    missile = initializeMissile();

    while (initial_velocity < 1 || initial_velocity > 100) { //Offsets still to be decided
        printf("Enter initial velocity value (1-100 m/s): ");
        scanf("%f", &initial_velocity);
        if (initial_velocity < 1 || initial_velocity > 100)
            printf("Error: invalid choice.\n");
    }
    setInitialVelocity(missile, initial_velocity);

    while (shooting_angle < 1 || shooting_angle > 360) { //Measured from the horizontal axis (x)
        printf("Enter shooting angle (1-360): ");
        scanf("%d", &shooting_angle);
        if (shooting_angle < 1 || shooting_angle > 360)
            printf("Error: invalid choice.\n");
    }
    setShootingAngle(missile, shooting_angle);

    shotFunction(missile, windForce(setWindSpeed())); //Wind speed is still determined by the player, NEEDS TO BE DETERMINED BY DIFFICULTY LEVEL!!!

    /*Following cycle controls if the projectile hits anything before going out of the map; if so, functions checking what was hit are called*/
    for (i = 0; i < VECTOR_LENGTH; i++) {

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


/*Here we'll have an equivalent AI shooting function (instead of asking the player for necessary data, it will calculate them by itself) */

//missile_data* AIShoot (missile_data *missile, float wind_speed) {}
