//On this file team 1 is working: Federico Bollotta and Lorenzo Romanelli

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shot_final_equation.h"

missile_data* initializeMissile(int x_coord, int y_coord, int missile_type)   //Initializes missile information
{
    int i;
    missile_data *leiria_missile;
    missile_data *milano_missile;
    missile_data *krakow_missile;
    missile_data *terraformer_missile;
    missile_data *missile_choosed;
    switch (missile_type)
    {
    case 1:
        leiria_missile = (missile_data*)malloc(sizeof(missile_data));
        strcpy(leiria_missile->name, "Leiria");
        leiria_missile->weight = 1.8 ;  /* Weight is assumed according to Colonel Albert Borgard's standardization of the Royal Ordnance cannonballs (1716).
                    Cannonballs weights are: 4 (as for now the only one considered), 6, 9, 12, 18, 24, 32 and 42 pounds (lb).
                    1 lb = 0.45 kg
                    NOTE: these values are only for reference! */
        leiria_missile->initial_velocity = 0;
        leiria_missile->shot_angle = 0;
        leiria_missile->x_turret_position = x_coord;
        leiria_missile->y_turret_position = y_coord+1; //Notice that, for testing, we're drawing the curve maintaining coordinates of the cartesian system, and then we simply print the matrix upside-down.
        leiria_missile->unit_damage = 50;
        for (i = 0; i < VECTOR_LENGTH; i++)
        {
            leiria_missile->x_vector_velocity[i] = 0;
            leiria_missile->y_vector_velocity[i] = 0;
        }
        missile_choosed = leiria_missile;
        break;
    case 2:
        milano_missile = (missile_data*)malloc(sizeof(missile_data));
        strcpy(milano_missile->name, "Milano");
        milano_missile->weight = 0.5 ;  /* Weight is assumed according to Colonel Albert Borgard's standardization of the Royal Ordnance cannonballs (1716).
                    Cannonballs weights are: 4 (as for now the only one considered), 6, 9, 12, 18, 24, 32 and 42 pounds (lb).
                    1 lb = 0.45 kg
                    NOTE: these values are only for reference! */
        milano_missile->initial_velocity = 0;
        milano_missile->shot_angle = 0;
        milano_missile->x_turret_position = x_coord;
        milano_missile->y_turret_position = y_coord+1; //Notice that, for testing, we're drawing the curve maintaining coordinates of the cartesian system, and then we simply print the matrix upside-down.
        milano_missile->unit_damage = 50;
        for (i = 0; i < VECTOR_LENGTH; i++)
        {
            milano_missile->x_vector_velocity[i] = 0;
            milano_missile->y_vector_velocity[i] = 0;
        }
        missile_choosed = milano_missile;
        break;
    case 3:
        krakow_missile = (missile_data*)malloc(sizeof(missile_data));
        strcpy(krakow_missile->name, "Milano");
        krakow_missile->weight = 0.5 ;  /* Weight is assumed according to Colonel Albert Borgard's standardization of the Royal Ordnance cannonballs (1716).
                    Cannonballs weights are: 4 (as for now the only one considered), 6, 9, 12, 18, 24, 32 and 42 pounds (lb).
                    1 lb = 0.45 kg
                    NOTE: these values are only for reference! */
        krakow_missile->initial_velocity = 0;
        krakow_missile->shot_angle = 0;
        krakow_missile->x_turret_position = x_coord;
        krakow_missile->y_turret_position = y_coord+1; //Notice that, for testing, we're drawing the curve maintaining coordinates of the cartesian system, and then we simply print the matrix upside-down.
        krakow_missile->unit_damage = 50;
        for (i = 0; i < VECTOR_LENGTH; i++)
        {
            krakow_missile->x_vector_velocity[i] = 0;
            krakow_missile->y_vector_velocity[i] = 0;
        }
        missile_choosed = krakow_missile;
        break;
    case 4:
        terraformer_missile = (missile_data*)malloc(sizeof(missile_data));
        strcpy(terraformer_missile->name, "Terraformer");
        terraformer_missile->weight = 1.3;
        terraformer_missile->initial_velocity = 0;
        terraformer_missile->shot_angle = 0;
        terraformer_missile->x_turret_position = x_coord;
        terraformer_missile->y_turret_position = y_coord+1; //Notice that, for testing, we're drawing the curve maintaining coordinates of the cartesian system, and then we simply print the matrix upside-down.
        terraformer_missile->unit_damage = 50;
        for (i = 0; i < VECTOR_LENGTH; i++)
        {
            terraformer_missile->x_vector_velocity[i] = 0;
            terraformer_missile->y_vector_velocity[i] = 0;
        }
        missile_choosed = terraformer_missile;
        break;
    }
    return missile_choosed;
}

void identificating_missile (char missile_name[], int missile_option) {

  switch (missile_option) {
    case 1:
        strcpy(missile_name, "Leiria");
        break;
    case 2:
        strcpy(missile_name, "Milano");
        break;
    case 3:
        strcpy(missile_name, "Krakow");
        break;
    case 4:
        strcpy(missile_name, "Terraformer");
        break;
    }
}

double cosDegrees (double alpha)   //Modifies cos() function in math.h so that it accepts values in degrees instead of radians
{
    return cos(M_PI * alpha / 180);
}

double sinDegrees (double alpha)   //Modifies sin() function in math.h so that it accepts values in degrees instead of radians
{
    return sin(M_PI * alpha / 180);
}

void setInitialVelocity (missile_data *m, float v)   //Allows the player to set the initial velocity of the shot
{

    m->initial_velocity = v;
}

void setShootingAngle (missile_data *m, int alpha)   //Allows the player to set shot angle
{
    m->shot_angle = alpha;
}

float windForce (float ws)   //Calculates wind force
{
    const float c = 0.1; // kg/s
    return ws * c;
}

void xVelocityFormula (missile_data *m, float wf)   //Calculates x component of velocity against time and stores the values in a vector
{
    const float b = 0.1; // kg/s
    int i;
    float velocity_x_0; //Velocity x component at 0 seconds
    float t;
    velocity_x_0 = m->initial_velocity * cosDegrees(m->shot_angle);
    for (t = 0, i = 0; t < SHOT_TIME; t += 0.02)   //We're calculating velocity every 0.02 seconds
    {
        m->x_vector_velocity[i] = (wf / b) + ((velocity_x_0 - (wf / b)) * exp( - (b / m->weight) * t));
        i++; //This index allows "for cycle" to break if the number of components calculated outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
}

void yVelocityFormula (missile_data *m)   //Calculates y component of velocity against time and stores the values in a vector
{
    const float b = 0.1; // kg/s
    const float g = 9.81; //Acceleration of Gravity
    int i;
    float velocity_y_0; //Velocity y component at 0 seconds
    float t;
    velocity_y_0 = m->initial_velocity * sinDegrees(m->shot_angle);
    for (t = 0, i = 0; t < SHOT_TIME; t += 0.02)
    {
        m->y_vector_velocity[i] = (velocity_y_0 + (m->weight * g / b)) * exp( - (b / m->weight) * t) - m->weight * g / b;
        i++; //This index allows "for cycle" to break if the number of components calculated outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
}

void xCoordinate (missile_data *m, float wf)   //Calculates x coordinate against time and stores the values in a vector
{
    const float b = 0.1; // kg/s
    int x0, i;
    float t, temp;
    float velocity_x_0;
    velocity_x_0 = m->initial_velocity * cosDegrees(m->shot_angle);
    x0 = m->x_turret_position;
    for (t = 0, i = 0; t < SHOT_TIME; t += 0.02)   //As for velocity, we're calculating coordinates every 0.02 seconds
    {
        temp = x0 + ((wf / b) * t) + (m->weight / b) * (velocity_x_0 - wf / b) * (1 - exp( - (b / m->weight) * t ));
        switch (selected_level.edge)
        {
        case EDGE_NO:
            m->x_vector_coordinate[i] = temp;
            break;
        case EDGE_BOUNCE:
            m->x_vector_coordinate[i] = bounce(temp);
            break;
        case EDGE_CONTINUE:
            m->x_vector_coordinate[i] = continuous(temp);
            break;
        }
        i++; //This index allows "for cycle" to break if number of calculations outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
}

void yCoordinate (missile_data *m)   //Calculates y coordinate against time and stores the values in a vector
{
    const float g = 9.81; //Acceleration of Gravity
    const float b = 0.1; // kg/s
    int y0, i;
    float t;
    float velocity_y_0;
    velocity_y_0 = m->initial_velocity * sinDegrees(m->shot_angle);
    y0 = m->y_turret_position;
    for (t = 0, i = 0; t < SHOT_TIME; t += 0.02)
    {
        m->y_vector_coordinate[i] = y0 + m->weight / b * (velocity_y_0 + m->weight * g / b) * (1 - exp(-(b / m->weight * t))) - m->weight * g / b * t;
        i++; //This index allows "for cycle" to break if number of calculations outgoes defined vector length
        if (i >= VECTOR_LENGTH) break;
    }
}

void shotFunction (missile_data *m, float wf)   //Puts together coordinates calculations and velocities calculations
{
    xVelocityFormula(m, wf);
    yVelocityFormula(m);
    yCoordinate(m);
    xCoordinate(m, wf);
}

float bounce (float coord)
{
    if (coord < 0)
    {
        if (abs(coord) < MAX_X) return abs(coord);
        else return bounce(abs(coord));
    }
    else if (coord > MAX_X)
    {
        if ((MAX_X - (coord - MAX_X)) > 0) return MAX_X - (coord - MAX_X);
        else return bounce(-(MAX_X - (coord - MAX_X)));
    }
    else return coord;
}

float continuous (float coord)
{
    if (coord < 0)
    {
        return continuous(coord + MAX_X);
    }
    else if (coord > MAX_X)
    {
        return continuous(coord - MAX_X);
    }
    else return coord;
}
