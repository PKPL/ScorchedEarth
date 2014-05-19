//---------------------------- Levels ------------------------------------
// It combines the files responsible for levels of a game
//------------------------------------------------------------------------

// Included libraries
//
// Included files

// It was a hard nut for us to understand what kind of return is here. So we change this in working stage to something simplier

// Ania Gil  and Nuno  Valente



#include "levels.h"
#include "menu_new_game.h"
#include "menu.h"

int choose_levels(int map_layout [MAX_X][MAX_Y]) // function for agreagate testing
{
    int selected_option, control;
    int wrong_input = 0;
    do
    {
        if (wrong_input == 1)
        {
            printf("The chosen option is not valid.\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        else
        {
            printf("Choose the level of difficulty: ");
            printf("\nEASY LEVEL - 1 ");
            printf("\nMEDIUM LEVEL - 2 ");
            printf("\nHARD LEVEL - 3 ");
            printf("\nPVP HOTSEAT - 4 in progres !!! ");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            wrong_input = 1;
        }
    }
    while (selected_option < 1 || selected_option > 4 || control == 0);

    if(selected_option == 1)
    {
        levels(1);
    }
    else if(selected_option == 2)
    {
        levels(2);
    }
    else if(selected_option == 3)
    {
        levels(3);
    }
    else if(selected_option == 4)
    {
        levels(4);
    }

    test_edge();
    create_mountain_map(map_layout);
    game_loop(map_layout);


    return selected_option;

}

int test_edge () {

    int selected_option, control;
    int wrong_input = 0;
    system("cls");
    do
    {
        if (wrong_input == 1)
        {
            printf("The chosen option is not valid.\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        else
        {
            printf("Choose the edge type: ");
            printf("\nNO EDGES - 1 ");
            printf("\nBOUNCING EDGES - 2 ");
            printf("\nCONTINUE EDGES - 3 ");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            wrong_input = 1;
        }
    }
    while (selected_option < 1 || selected_option > 3 || control == 0);

    if(selected_option == 1)
    {
        selected_level.edge = EDGE_NO;
    }
    else if(selected_option == 2)
    {
        selected_level.edge = EDGE_BOUNCE;
    }
    else if(selected_option == 3)
    {
        selected_level.edge = EDGE_CONTINUE;
    }

    return selected_option;
}
