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
#include "unit.h"
void test_menu() // function for agreagate testing
{//unit player, bot;

    int map_layout[MAX_X][MAX_Y] = {{0}}; /*Matrix containing the map information initialized with value 0 everywhere. It will work with [x][y] coordinates.*/
    system("COLOR 8F");
    system("cls");
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
    menu_reaction(selectedOption, map_layout);
}

void menu_reaction(int SelectedOption, int map_layout [MAX_X][MAX_Y])// undone
{
    switch (SelectedOption)
    {
    case 1: //new game
    {
        system("cls");
        //starting new game
        //Code to get the chosen level goes here
        //We also have to call the functions apropriately, for example, if difficulty is hard, AI has to be hard, and physics too etc.
        /*
        EASY LEVEL:
        create_mountain_map(map_layout);
        test_drawing_map(map_layout);
        test_drawing_units(map_layout);
        */

        /*
        MEDIUM LEVEL:
        create_mountain_map(map_layout);
        test_drawing_map(map_layout);
        test_drawing_units(map_layout);
        */

        /*
        HARD LEVEL:
        create_mountain_map(map_layout);
        test_drawing_map(map_layout);
        test_drawing_units(map_layout);
        */

        test_levels(map_layout);
        break;
    }
    case 2:// highscore
    {   player_highscore players[11];
        system("cls");
        highscore(players);
        break;
    }

    case 3:// credits
    {
        system("cls");
        credits();
        break;
    }

    case 4://exit game
    {
        system("cls");
        close_game();
        break;

    }
    default:
    {
        test_menu();
        break;
    }
    }
    test_menu();
}
