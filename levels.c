//---------------------------- Levels ------------------------------------
// It combines the files responsible for levels of a game
//------------------------------------------------------------------------

// Included libraries

// Included files
#include "levels_set.c"
#include "levels_level.c"


void test_levels() // function for agreagte testing
{
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

