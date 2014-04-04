#ifndef __SHOT_FINAL_EQUATION_H__
#define __SHOT_FINAL_EQUATION_H__

//On this file Team 1 is working: Federico Bollotta and Lorenzo Romanelli

#define MAX_WIND_SPEED 100 //Meters per second
#define VECTOR_LENGTH 1000
#define LENGTH 100 //X axis of the matrix
#define HEIGHT 80 //Y axis of the matrix

/* In the following struct are stored all the datas related to the firt type of missile
(for further missile types we'll use more structs) */
typedef struct {
    char name[100];
    float weight; //Kilograms per second
    float initial_velocity; //Meters per second
    float x_vector_velocity[VECTOR_LENGTH], y_vector_velocity[VECTOR_LENGTH]; //We're storing velocity value (x and y components) in these vectors as time increases
    int x_turret_position, y_turret_position;
    int x_vector_coordinate[VECTOR_LENGTH], y_vector_coordinate[VECTOR_LENGTH]; //Coordinates of the missile inside the matrix as time increases
    int shot_angle; //In sexagesimal degrees
} missile_data;

void setTime();
void setWindSpeed();
void windForce();

double cosDegrees(double);
double sinDegrees(double);

missile_data* initializeMissile();
void setInitialVelocity(missile_data*);
void setShootingAngle(missile_data*);

void xVelocityFormula(missile_data*);
void yVelocityFormula(missile_data*);
void xCoordinate(missile_data*);
void yCoordinate(missile_data*);

#endif // __SHOT_FINAL_EQUATION_H__
