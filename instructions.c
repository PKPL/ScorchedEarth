//---------------------------- Game Instructions -------------------------
// Objective and keyboard instructions
//------------------------------------------------------------------------
// Portugal Team

#include <stdio.h>

void game_instructions () {

    printf("\t\t\tOBJECTIVES\n\n");
    printf("The main objective of our game is to take down the enemy tank using some missiles.\n");
    printf("During the game you will be able to choose the missile you want to use and the angle and power of\nyour shot.\n");
    printf("There will be 2 armor bonuses in the map that you can shoot to increase the actual armor your tank\nhas.\n");
    printf("\n");
    printf("\t\t\tINSTRUCTIONS\n\n");
    printf("Shooting Angle\t\tUp and Down arrows\n");
    printf("Shooting Power\t\tLeft and Right arrows\n");
    printf("Shooting\t\tENTER\n");
    printf("Sauron\t\t\tSPACE\n");
    printf("Exit\t\t\tESC\n");

    getch();
}
