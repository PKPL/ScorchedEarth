#ifndef __MATRIX_H__
#define __MATRIX_H__

#define LENGTH 200 //x axis
#define HEIGHT 80 //y axis

int xVectorCoordinate[LENGTH];
int yVectorCoordinate[HEIGHT];

float xVectorVelocity[LENGTH];
float yVectorVelocity[HEIGHT];

int matrix[HEIGHT][LENGTH];
void init_matrix();
void print_matrix();

#endif // __MATRIX_H__
