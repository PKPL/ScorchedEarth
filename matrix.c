//Team 1 is working on this file: Federico Bollotta and Lorenzo Romanelli

#include <stdio.h>
#include "matrix.h"

void init_matrix() { //Initializes a matrix that we'll use for testing formulas and checking shoots
    int i,j;
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < LENGTH; j++)
            matrix[i][j] = 0;
}

void print_matrix() { //Prints the above mentioned matrix
    int i,j;
    for (i = HEIGHT; i > 0; i--) { //The matrix is printed upside-down. In this way, there's no need to change the formula for calculating y-coordinate of the shoot
        for (j = 0; j < LENGTH; j++) {
            printf("%d", matrix[i][j]);
        }
        putchar('\n');
    }
}
