//---------------------------- Levels ------------------------------------
// It combines the files responsible for levels of a game
//------------------------------------------------------------------------

// Included libraries

// Included files
#include "levels.h"

void test_levels() // function for agreagate testing
{
    //printf("Drawing test\n");

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
            printf("\nPick the desired level|\n");
            printf("|______________________________________________|\n\n");
            printf("[ 1 ] -> Easy\n[ 2 ] -> Medium\n[ 3 ] -> Hard\n");
            printf("\nNumber of desired option: ");
            control = scanf("%d", &selectedOption);
            fflush(stdin);
            wrongInput = 1;
        }
    }
    while (selectedOption < 1 || selectedOption > 3 || control == 0);

    levels();
}

void levels()
{
    level_struct easy_level;
    {
        easy_level.level_wind = WIND_NO;
        easy_level.level_ai = AI_EASY;
    }

    level_struct medium_level;
    {
        medium_level.level_wind = WIND_CONST;
        medium_level.level_ai = AI_MEDIUM;
    }

    level_struct hard_level;
    {
        hard_level.level_wind = WIND_VARIABLE;
        hard_level.level_ai = AI_HARD;
    }

}

