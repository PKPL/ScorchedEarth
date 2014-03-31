//On this file Team 1 is working: Federico Bollotta and Lorenzo Romanelli
//UNDER DEVELOPMENT!!!!

#include "shot_hit.h"
void explosion (missile_data *m, int i) {
    if (m-> x_vector_velocity[i] < RANGE1) { //We need to calculate exact velocity starting from velocity in x and y
        //explosion type 1 (according to velocity and weight of the missile)
    }
        //explosion type 2 (as above)
}

void shotHit(missile_data *m, int n, int i) { //Puts in the matrix values corresponding to explosions


    switch (n) {
        case  1: //Hits ground
            explosion(m,i);
            break;
        case  2:
            ;   //Hits unit
            break;
    }
}
