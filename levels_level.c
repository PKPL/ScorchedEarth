//---------------------------- Level ------------------------------------
// Stuctur resposible for levels setting
//------------------------------------------------------------------------

enum wind_type
{
  no_wind,
  const_wind,
  variable_wind
};

enum ai_type
{
  ai_easy,
  ai_medium,
  ai_hard
};

typedef struct level_struct
{
   wind_type level_wind;
   ai_type level_ai;
} level_struct;
