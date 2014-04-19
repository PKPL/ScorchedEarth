//---------------------------- Levels ------------------------------------
// It combines the files responsible for levels of a game
//------------------------------------------------------------------------

// Included libraries
//
// Included files

// It was a hard nut for us to understand what kind of return is here. So we change this in working stage to something simplier

// Ania Gil  and Nuno  Valente



#include "levels.h"

/*level_struct test_levels() // function for agreagate testing
{
    //printf("Drawing test\n");
    level_struct selected_level;
    int selected_option, control;
    int wrong_input = 0;
    do
    {
        if (wrong_input == 1)
        {
            printf("The chosen option is not valid.\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            fflush(stdin);
        }
        else
        {
            printf("\nPick the desired level|\n");
            printf("|______________________________________________|\n\n");
            printf("[ 1 ] -> Easy\n[ 2 ] -> Medium\n[ 3 ] -> Hard\n");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            fflush(stdin);
            wrong_input = 1;
        }
    }
    while (selected_option < 1 || selected_option > 3 || control == 0);
//    selected_level = level_set (selected_option); Problem with this function
    return selected_level;
} */

int test_levels() // function for agreagate testing
{
    //printf("Drawing test\n");
    level_struct selected_level;
    int selected_option, control;
    int wrong_input = 0;
    do
    {
        if (wrong_input == 1)
        {
            printf("The chosen option is not valid.\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            fflush(stdin);
        }
        else
        {
            printf("\nPick the desired level|\n");
            printf("|______________________________________________|\n\n");
            printf("[ 1 ] -> Easy\n[ 2 ] -> Medium\n[ 3 ] -> Hard\n");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selected_option);
            fflush(stdin);
            wrong_input = 1;
        }
    }
    while (selected_option < 1 || selected_option > 3 || control == 0);
//    selected_level = level_set (selected_option); Problem with this function
    return selected_option;
}
