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
        easy_level.level_wind = wind_type.no_wind;
        easy_level.level_ai = ai_type.ai_easy;
    }

    level_struct medium_level;
    {
        easy_level.level_wind = wind_type.const_wind;
        easy_level.level_ai = ai_type.ai_medium;
    }

    level_struct hard_level;
    {
        easy_level.level_wind = wind_type.variable_wind;
        easy_level.level_ai = ai_type.ai_hard;
    }

}

