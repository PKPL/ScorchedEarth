#include "game_load.h"

bool game_load(int map_layout[MAX_X][MAX_Y], level_struct *level, unit *player, unit *bot, float *wind_speed)
{
    FILE *game_load_file = NULL;
    int read;
    game_load_file = fopen("game_save.dat", "rb");
    if (game_load_file == NULL)
    {
        perror ("Error on trying to load the game");
        Sleep (1500);
        return false;
    }
    else
    {
        read = fread (map_layout, sizeof(int), MAX_X * MAX_Y, game_load_file);

        if (!checker(&read, MAX_X * MAX_Y))
        {
            fclose(game_load_file);
            return false;
        }

        read = fread(level, sizeof(level_struct), 1, game_load_file);
        if (!checker(&read, 1))
        {
            fclose(game_load_file);
            return false;
        }

        read = fread (player, sizeof(unit), 1, game_load_file);

        if (!checker(&read, 1))
        {
            fclose(game_load_file);
            return false;
        }

        read = fread (bot, sizeof(unit), 1, game_load_file);

        if (!checker(&read, 1))
        {
            fclose(game_load_file);
            return false;
        }

        read = fread (wind_speed, sizeof(float), 1, game_load_file);

        if (!checker(&read, 1))
        {
            fclose(game_load_file);
            return false;
        }
    }
    fclose (game_load_file);
    return true;
}

bool checker (int *read, int numberToCheck)
{
    if (*read == numberToCheck)
    {
        return true;
    }
    perror ("Can't read all game");
    return false;
}
