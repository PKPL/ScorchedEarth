#ifndef __LEVELS_LEVEL_H__
#define __LEVELS_LEVEL_H__

//---------------------------- Level ------------------------------------
// Stuctur resposible for levels setting
//-----------------------------------------------------------------------
#include "levels.h"
#include "levels_set.h"

typedef enum wind_type
{
  WIND_NO,
  WIND_CONST,
  WIND_VARIABLE
} wind_type;

typedef enum ai_type
{
  AI_EASY,
  AI_MEDIUM,
  AI_HARD
} ai_type;

typedef struct level_struct
{
   wind_type level_wind;
   ai_type level_ai;
} level_struct;

level_struct levels(int option);

#endif // __LEVELS_LEVEL_H__
