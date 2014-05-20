/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include "maps_save.h"

bool save_map(int map_layout[MAX_X][MAX_Y])
{

    FILE * map_file;
    int x = 0;
    int y = 0;

    map_file = fopen("maps_save.txt","w"); // w means we are able to write it and create it if it didn't exist
    if (map_file == NULL)
    {
        perror("Error:\t The program could not open the file where the map was saved.");
    }
    else
    {
        for (x = 0; x < MAX_X; x++)
        {
            for (y = 0; y < MAX_Y; y++)
            {
                fprintf(map_file, "%d", map_layout[x][y]);
//                fprintf(map_file,"map_layout\t[%d]\t[%d]\t%d\n",x ,y ,map_layout[x][y]); // Not sure if the parenthesis are needed
//                if (map_layout[x][y] % 2 != 0 && map_layout[x][y] % 2 != 1) // is not integer
//                {
//                    fprintf(stderr, "Map generation error: Contents of array different than expected.\n");
//                    return false;
//                }
            }
        }
        printf("\nMap saved in maps_save.txt\n");
        fclose(map_file);
        return true;
    }
    return false;
}
