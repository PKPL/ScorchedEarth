//On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shot_final_equation.h"

//Global Constants and Variables
const float b = 0.1; // kg/s
const float c = 0.1; // kg/s
const float g = 9.81; //Acceleration of Gravity
float timer;
float wind_speed;
float wind_force;

missile_data* initializeMissile() { //Initializes missile information
    int i;
    missile_data *light_missile;
    light_missile = (missile_data*)malloc(sizeof(missile_data));
    strcpy(light_missile->name, "Super Light Missile");
    light_missile->weight = 1.8;  /* Weight is assumed according to Colonel Albert Borgard's standardization of the Royal Ordnance cannonballs (1716).
                    Cannonballs weights are: 4 (as for now the only one considered), 6, 9, 12, 18, 24, 32 and 42 pounds (lb).
                    1 lb = 0.45 kg
                    NOTE: these values are only for reference! */
    light_missile->initial_velocity = 0;
    light_missile->shot_angle = 0;
    light_missile->x_turret_position = 0; //We're calculating trajectory as if the turret is placed on the bottom-left corner of the map.
    light_missile->y_turret_position = 0; //Notice that, for testing, we're drawing the curve maintaining coordinates of the cartesian system, and then we simply print the matrix upside-down.
    for (i = 0; i < VECTOR_LENGTH; i++) {
        light_missile->x_vector_velocity[i] = 0;
        light_missile->y_vector_velocity[i] = 0;
    }
    return light_missile;
}

double cosDegrees (double alpha) { //Modifies cos() function in math.h so that it accepts values in degrees instead of radians
    return cos(M_PI * alpha / 180);
}

double sinDegrees (double alpha) { //Modifies sin() function in math.h so that it accepts values in degrees instead of radians
    return sin(M_PI * alpha / 180);
}

void printMissileData (missile_data *m) { //Prints all information about one missile type
    if(m == NULL) {
        printf("Uninitialized missile!\n\n"); return;
    }
    printf("\n***MISSILE DATA***\n\n");
    printf("Type: %s\nWeight: %.1f kg\n", m->name, m->weight);
    printf("Initial velocity: %.1f m/s\n", m->initial_velocity);
    printf("Shot angle: %d degrees\n", m->shot_angle);
    printf("Turret coordinates: %d;%d\n\n", m->x_turret_position, m->y_turret_position);
}

void setInitialVelocity (missile_data *m) { //Allows the player to set the initial velocity of the shot
    while (m->initial_velocity < 1 || m->initial_velocity > 100) { //Offsets still to be decided
        printf("Enter initial velocity value (1-100 m/s): ");
        scanf("%f", &m->initial_velocity);
        if (m->initial_velocity < 1 || m->initial_velocity > 100)
            printf("Error: invalid choice.\n");
    }
}

void setShootingAngle (missile_data *m) { //Allows the player to set shot angle
    while (m->shot_angle < 1 || m->shot_angle > 360) { //Measured from the horizontal axis (x)
        printf("Enter shooting angle (1-360): ");
        scanf("%d", &m->shot_angle);
        if (m->shot_angle < 1 || m->shot_angle > 360) {
            printf("Error: invalid choice.\n");
        }
    }
}

void setWindSpeed () { //Allows the user to set wind speed
    float ws;
    ws = MAX_WIND_SPEED + 1;
    while (ws < -100 || ws > 100) {
        printf("Enter wind speed (-100 to 100): "); //Useful for keeping under control all the values, I guess wind speed should be randomized
        scanf("%f", &ws);
        if (ws < -100 || ws > 100)
            printf("Error: invalid choice.\n");
    }
    wind_speed = ws;
}

void windForce () { //Calculates wind force
    wind_force = wind_speed * c;
}

void setTime () { //Allows the user to decide the maximum time of the projectile flight
    printf("Enter time (in seconds or fractions of second) against which you want velocity and position to be calculated: ");
    scanf("%f", &timer);
}

void xVelocityFormula (missile_data *m) { //Calculates x component of velocity against time and stores the values in a vector
    int i;
    float velocity_x_0; //Velocity x component at 0 seconds
    float t, wf;
    wf = wind_force;
    velocity_x_0 = m->initial_velocity * cosDegrees(m->shot_angle);
    for (t = 0, i = 0; t < timer; t += 0.02) { //We're calculating velocity every 0.02 seconds
        m->x_vector_velocity[i] = (wf / b) + ((velocity_x_0 - (wf / b)) * exp( - (b / m->weight) * t));
        i++; //This index allows "for cycle" to break if the number of components calculated outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
    printf("\nVelocity (x component) at %.1f seconds: %.1f m/s\n", timer, m->x_vector_velocity[i-1]); //Prints the last value stored in the vector
}

void yVelocityFormula (missile_data *m) { //Calculates y component of velocity against time and stores the values in a vector
    int i;
    float velocity_y_0; //Velocity y component at 0 seconds
    float t;
    velocity_y_0 = m->initial_velocity * sinDegrees(m->shot_angle);
    for (t = 0, i = 0; t < timer; t += 0.02) {
        m->y_vector_velocity[i] = (velocity_y_0 + m->weight * g / b) * exp( - (b / m->weight) * t) - m->weight * g / b;
        i++; //This index allows "for cycle" to break if the number of components calculated outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
    printf("Velocity (y component) at %.1f seconds: %.1f m/s\n\n", timer, m->y_vector_velocity[i-1]); //Prints the last value stored in the vector
}

void xCoordinate (missile_data *m) { //Calculates x coordinate against time and stores the values in a vector
    int x0, i;
    float wf, t;
    float velocity_x_0;
    wf = wind_force;
    velocity_x_0 = m->initial_velocity * cosDegrees(m->shot_angle);
    x0 = m->x_turret_position;
    for (t = 0, i = 0; t < timer; t += 0.02) { //As for velocity, we're calculating coordinates every 0.02 seconds
        m->x_vector_coordinate[i] = x0 + ((wf / b) * t) + (m->weight / b) * (velocity_x_0 - wf / b) * (1 - exp( - (b / m->weight) * t ));
        i++; //This index allows "for cycle" to break if number of calculations outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
}

void yCoordinate (missile_data *m) { //Calculates y coordinate against time and stores the values in a vector
    int y0, i;
    float t;
    float velocity_y_0;
    t = timer;
    velocity_y_0 = m->initial_velocity * sinDegrees(m->shot_angle);
    y0 = m->y_turret_position;
    for (t = 0, i = 0; t < timer; t += 0.02) {
        m->y_vector_coordinate[i] = y0 + m->weight / b * (velocity_y_0 + m->weight * g / b) * (1 - exp(-(b / m->weight * t))) - m->weight * g / b * t;
        i++; //This index allows "for cycle" to break if number of calculations outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
}

void printIntVector (int vector[], int n) { //Prints all the values stored in coordinates vectors
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", vector[i]);
}

void printFloatVector (float vector[], int n) { //Prints all the values stored in velocities vectors
    int i;
    for (i = 0; i < n; i++)
        printf("%.1f ", vector[i]);
}
