/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include "maps_save.h"


extern int map_layout[MAX_X][MAX_Y];

void test_maps_save()
{

    int map_layout[MAX_X][MAX_Y] = {{0}}; // This line was just added to test the .txt writing
    save_map(map_layout);
}

void save_map(int map_layout[MAX_X][MAX_Y])
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
                fprintf(map_file,"map_layout\t[%d]\t[%d]\t%d\n",x ,y ,map_layout[x][y]); // Not sure if the parenthesis are needed
            }
        }
        printf("\nMap saved in maps_save.txt\n");
        fclose(map_file);
    }
}
