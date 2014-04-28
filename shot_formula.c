//---------------------------- Shot formula ------------------------------
// Formula for the shot
//------------------------------------------------------------------------
//On this file Team 1 is working: Lorenzo Romanelli and Federico Bollotta

#include "shot_formula.h"

/* When a player shoots, the following function is called: it asks the player for all necessary data (shooting angle, initial velocity), then calculates the shot, checks the shot and, if possible, calls for explosion functions. */

void playerShot(missile_data *missile) {

    int i, flag = 0;
    int shooting_angle = 0;
    float initial_velocity = 0;

    init_matrix();

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

    shotFunction(missile, windForce(wind_speed));

    /*Following cycle controls if the projectile hits anything before going out of the map; if so, functions checking what was hit are called*/
    for (i = 0; i < VECTOR_LENGTH; i++) {

        switch (checkHit(i, missile)) {
            case 0: continue;
            case 1: break;
            case 2: /*explosion: hit ground*/
                    // createExplosion(matrix); //connection with drawing_destruction.c
                    //EXTRA_EXPLOSION!!!!!

                   // extra_explosion(missile); //you can find it in shot_hit.c
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
    //print_matrix();

}


/*Here we have an equivalent AI shooting function (instead of asking the player for necessary data, they will be passed as arguments) */

void AIShoot (missile_data *missile, float ai_init_velocity, int ai_shoot_angle) {

    int i, flag = 0;

    init_matrix();

    setInitialVelocity(missile, ai_init_velocity);
    setShootingAngle(missile, ai_shoot_angle);

    shotFunction(missile, windForce(wind_speed));

    /*Following cycle controls if the projectile hits anything before going out of the map; if so, functions checking what was hit are called*/
    for (i = 0; i < VECTOR_LENGTH; i++) {

        switch (checkHit(i, missile)) {
            case 0: continue;
            case 1: break;
            case 2: /*explosion: hit ground*/
                createExplosion(matrix); //connection with drawing_destruction.c
                flag = 1;
                break;
            case 3: /*explosion: hit unit*/
                //Call function Destruction of Unit or similar.
                flag = 1;
                break;
            case 4:
                drawing_shots(matrix, missile);
              //  matrix[missile->y_vector_coordinate[i]][missile->x_vector_coordinate[i]] = 5; // This print shot Parabola on ITALIAN TEAM MATRIX, for now just let it in comment.
                break;
        }

        createDestruction(matrix);

        if (flag == 1) break;
    }
    print_matrix();

}

float AIcheck (int x_enemy_coord, int y_enemy_coord, float missile_weight, int angle, int x_player_coord, int y_player_coord) {

    const float b = 0.1;
    const float g = 9.81;
    int x0, y0, x_target, y_target;
    float t, velocity, vel_x0, vel_y0, wf;

    wf = windForce(wind_speed);
    x0 = x_enemy_coord;
    y0 = y_enemy_coord;
    velocity = 1;
    t = 0;

    for (;;) { //This "for cycle" increases initial velocity value by 1 m/s
        t = 0;
        if (velocity > 100) break;
        vel_x0 = velocity * cosDegrees(angle);
        vel_y0= velocity * sinDegrees(angle);

        for (;;) { //This "for cycle" increases time by 0.02 seconds

            t += 0.2;
            x_target = x0 + ((wf / b) * t) + (missile_weight / b) * (vel_x0 - wf / b) * (1 - exp( - (b / missile_weight) * t ));
            y_target = y0 + missile_weight / b * (vel_y0 + missile_weight * g / b) * (1 - exp(-(b / missile_weight * t))) - missile_weight * g / b * t;

            if (y_target < 0) break; //If projectile outgoes map, it is not good, so next try :)
            if (x_target == x_player_coord) {
                if (y_target == y_player_coord)
                    return velocity;
                else continue; //It might happen that in two consecutive instants, x coord of the shoot remains the same while y coord changes
            }

            else if (x_target >= LENGTH || x_target < 0) //Here instead of LENGTH (of matrix) we'll have to put length of map
                break;
        }
        velocity += 1;
    }

    return -1;

}
