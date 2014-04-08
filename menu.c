//---------------------------- Menu --------------------------------------
// It combines the files responsible for menu of a game
//------------------------------------------------------------------------

// Team 2 File (Polish Group)

/*
This file says Team 2 File (Polish Group)
However I thought that this file would be the correct one to work on in order to complete the task:
"Drawing Menu screen" Assigned to the Portuguese team.
Should it not be in this file, advise us (Portuguese team) as soon as possible.
*/

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

void menu_reaction(int SelectedOption)// undone
{
   switch (SelectedOption)
    {
   case 1: //new game
       { //starting new game
                        break;
       }
   case 2:// highscore
       { // highscore();
          break;
       }

    case 3:// credits
       {   // credits();
             break;
       }

    case 4://exit game
       {    exit(EXIT_SUCCESS);

       }
       default:
       { test_menu();
        break;
       }
    }
}

