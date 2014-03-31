#include <stdio.h>
#include "matrix.h"

void init_matrix() {
    int i,j;
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < LENGTH; j++)
            matrix[i][j] = 0;
}

void print_matrix() {
    int i,j;
    for (i = HEIGHT; i > 0; i--) {
        for (j = 0; j < LENGTH; j++) {
            printf("%d", matrix[i][j]);
        }
        putchar('\n');
    }
}
