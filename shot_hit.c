//On this file Team 1 is working: Federico Bollotta and Lorenzo Romanelli
//UNDER DEVELOPMENT!!!!

#include "shot_hit.h"

int checkHit (int i, missile_data *m,int matrix[MAX_X][MAX_Y]) {
    if (m->y_vector_coordinate[i] >= MAX_Y)
    {
        //Sleep(20);
        return 0; //If the projectile outgoes map height without hitting anything, it waits for it to enter again in the map
    }
    if (m->x_vector_coordinate[i] >= MAX_X || m->x_vector_coordinate[i] < 0 || m->y_vector_coordinate[i] < 0) return -1; //If the projectile outgoes map length (either on the left or right side) without hitting anything, the shot goes lost
    if (matrix[m->x_vector_coordinate[i]][m->y_vector_coordinate[i]] == 1) //Projectile hits ground
        return 1;
    if (matrix[m->x_vector_coordinate[i]][m->y_vector_coordinate[i]] == 3) //Projectile hits player
        return 3;
    if (matrix[m->x_vector_coordinate[i]][m->y_vector_coordinate[i]] == 2) //Proj hits enemy
        return 20;
    if (matrix[m->x_vector_coordinate[i]][m->y_vector_coordinate[i]] == 4) return 5;
    return 4;
}
/*
void extra_explosion(missile_data *m){

}
*/
