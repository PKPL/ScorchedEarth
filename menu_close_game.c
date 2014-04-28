//---------------------------- Close game --------------------------------
// Closing game and single play
//------------------------------------------------------------------------

#include "menu_close_game.h"

int close_game()
{
    char decision;
    printf("Are you sure you want to quit the game? y/n");
    scanf("%d",&decision);

    if(decision == 'y') exit(EXIT_SUCCESS);
    else
    {
    system("cls");
    return(0);
    }

}
