//---------------------------- Level ------------------------------------
// Stuctur resposible for levels setting
//------------------------------------------------------------------------

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
