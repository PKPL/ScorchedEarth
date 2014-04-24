//---------------------------- Level ------------------------------------
// Stuctur resposible for levels setting
//-----------------------------------------------------------------------

#include "levels_level.h"

extern level_struct selected_level; //It must be global xD

void levels(int option)
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
    switch (option)
    {
    case 1:
        selected_level = easy_level;
        break;
    case 2:
        selected_level = hard_level;
        break;
    case 3:
        selected_level = hard_level;
        break;
    }

}
