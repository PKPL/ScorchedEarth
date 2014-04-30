//---------------------------- Close game --------------------------------
// Closing game and single play
//------------------------------------------------------------------------

#include "menu_close_game.h"

int close_game()
{
    char decision;
    printf("Are you sure you want to quit the game? y/n ");
    scanf(" %c",&decision); //The %c (becouse we want char, no integer :)) conversion specifier won't automatically skip any leading whitespace,
    //so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately.

    if(decision == 'y') exit(EXIT_SUCCESS);
    else
    {
    system("cls");
    return(0);
    }

}
