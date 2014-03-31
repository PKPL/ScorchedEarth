//
//  shot_hit.c
//  shot_formula
//
//  Created by Federico Bollotta on 31/03/14.
//  Copyright (c) 2014 Federico Bollotta. All rights reserved.
//


#include <stdio.h>
#include "shot_hit.h"
#include "matrix.h"

#define range1 0.5
void explosion ( missile_data *m, int i){
    if ( m-> x_vector_velocity[i] < range1  ) { //andare a calcolare il vettore in maniera corretta con la legge del PARALLELEPIPEDO
        
        //explosiontype 1
        
        
        
    }
        //explosiontype 2
}

void shotHit(missile_data *m, int n, int i){
    
    //prende i vettori esplosione e li mette nella matrice.
    
    switch (n) {
        case  1: //shotground
            explosion(m,i);
            break;
        case  2:
            ;   //shotunit
            break;
    }
}