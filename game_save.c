/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include "game_save.h"
#include "levels_level.h"
#include "unit.h"

bool save_game(int map_layout[MAX_X][MAX_Y], level_struct level, unit player, unit bot, float wind)
{
    FILE * game_save_file;

    char option = option_User("Do you want to save your game");
    if (option == 'Y') {
         game_save_file = fopen("game_save.dat","wb"); // w means we are able to write it and create it if it didn't exist
    if (game_save_file == NULL)
    {
        perror("Error:\t The program could not open the file where the map was saved");
    }
    else if (map_layout[MAX_X][MAX_Y] == NULL)
    {
        perror("Error:\t map");
    }
    else
    {
        fwrite(map_layout, sizeof(int), MAX_X * MAX_Y, game_save_file);
        fwrite(&level, sizeof(level_struct), 1, game_save_file);
        fwrite(&player, sizeof(unit), 1, game_save_file);
        fwrite(&bot, sizeof(unit), 1, game_save_file);
        fwrite(&wind, sizeof(float), 1, game_save_file);
    }
    fclose(game_save_file);
    printf("Your game is saved.\n");
    return true;
    }
    return false;
}
