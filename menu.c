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
#include "shot_final_equation.h"
#include "game_load.h"
#include "instructions.h"


void menu() // function for agreagate testing
{
    //unit player, bot;

    system("cls");
    system("COLOR 9");

    printf("#######   #######     #####     ######    #######   ##   ##   #######   ####\n");
    printf("###       ###        ##000##    ##   ##   ###       ##   ##   ##        ##  ##\n");
    printf(" ###      ##        ##00100##   ##   ##   ##        ##   ##   ###       ##    ##\n");
    printf("  ###     ##        ##01110##   ######    ##        #######   #######   ##    ##\n");
    printf("   ###    ##        ##11111##   ## ##     ##        ##   ##   ###       ##    ##\n");
    printf("    ###   ###        ##111##    ##  ##    ###       ##   ##   ##        ##  ##\n");
    printf("#######   #######     #####     ##   ##   #######   ##   ##   #######   ####\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                   ####   ####   ###   #####   #  #\n");
    printf("                                   #      #  #   #  #    #     #  #\n");
    printf("                                   ###    ####   ###     #     ####\n");
    printf("                                   #      #  #   # #     #     #  #\n");
    printf("                                   ####   #  #   #  #    #     #  #\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                     Powered by Zrobimy Domani\n\n");


    getchar();
    fflush(stdin);

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
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        else
        {
            printf("\n|Scorched Earth (Project Work In Progress) MENU|\n");
            printf("|______________________________________________|\n\n");
            printf("[ 1 ] -> Start a New Game\n[ 2 ] -> Load the last game\n[ 3 ] -> View Highscores\n[ 4 ] -> Instructions\n[ 5 ] -> View Credits\n[ 6 ] -> Exit Game, although you don't want to do it =]\n");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selectedOption);
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            wrongInput = 1;
        }
    }
    while (selectedOption < 1 || selectedOption > 6 || control == 0);
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
        choose_levels(map_layout);
        break;
    }
    case 2:
    {
        bool game_loaded = game_load(map_layout, &selected_level, &player, &bot, &wind_speed);
        if (game_loaded == true)
        {
            game_loop(map_layout, true, false);
        }
        break;
    }
    case 3:// highscore
    {
        system("cls");
        read_highscores();
        printf("\n\nPress any key to go back to the menu...");
        getch();
        break;
    }
    case 4://instructions
        {
            system("cls");
           game_instructions();
           break;
        }
    case 5:// credits
    {
        system("cls");
        credits();
        break;
    }

    case 6://exit game
    {
        system("cls");
        close_game();
        break;

    }
    default:
    {
        menu();
        break;
    }
    }
    menu();
}
