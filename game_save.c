/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include "game_save.h"
#include "levels_level.h"
#include "unit.h"

bool save_game(int map_layout[MAX_X][MAX_Y], level_struct level, unit player, unit bot, missile_data *missile, float wind, bool playerTurn)
{
    FILE * game_save_file;

    game_save_file = fopen("game_save.dat","wb"); // w means we are able to write it and create it if it didn't exist
    if (game_save_file == NULL)
    {
        perror("Error:\t The program could not open the file where the map was saved.");
    }
    else if (map_layout[MAX_X][MAX_Y] == NULL)
    {
        perror("Error:\t map.\n");
    }
    else if (missile == NULL)
    {
        perror("Error:\t missile.\n");
    }
//    else if (wind == )
//    {
//        perror("Error:\t wind.\n");
//    }
//    else if ( level == NULL)
//    {
//        perror("Error:\t level.\n");
//    }
    else
    {
        fwrite(&map_layout[MAX_X][MAX_Y], sizeof(int), MAX_X * MAX_Y, game_save_file);
        fwrite(missile, sizeof(missile_data), 1, game_save_file);
        fwrite(&wind, sizeof(float), 1, game_save_file);
        fwrite(&level, sizeof(level_struct), 1, game_save_file);
        fwrite(&player, sizeof(unit), 1, game_save_file);
        fwrite(&bot, sizeof(unit), 1, game_save_file);
        fwrite(&playerTurn, sizeof(bool), 1, game_save_file);
    }
    fclose(game_save_file);
    printf("Your game is saved.\n");
}
