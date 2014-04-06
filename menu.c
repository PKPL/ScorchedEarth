//---------------------------- Menu --------------------------------------
// It combines the files responsible for menu of a game
//------------------------------------------------------------------------

// Team 2 File (Polish Group)

// Included files
#include "menu.h"

void test_menu() // function for agreagate testing
{
    int selectedOption, control;
    int wrongInput = 0;
    do
    {
        if (wrongInput == 1)
        {
            printf("The chosen option is not valid.\nNumber of desired option: ");
            control = scanf("%d", &selectedOption);
            fflush(stdin);
        }
        else
        {
            printf("\n|Scorched Earth (Project Work In Progress) MENU|\n");
            printf("|______________________________________________|\n\n");
            printf("[ 1 ] -> Start a New Game\n[ 2 ] -> View Highscores\n[ 3 ] -> View Credits\n[ 4 ] -> Exit Game, although you don't want to do it =]\n");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selectedOption);
            fflush(stdin);
            wrongInput = 1;
        }
    }
    while (selectedOption < 1 || selectedOption > 4 || control == 0);
}
