/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include <stdio.h>
#include <stdlib.h>


#define MAX_X 100
#define MAX_Y 100

void saveMap(int mapLayout[MAX_X][MAX_Y]);

int main()
{
    int x,y;

    int mapLayout[MAX_X][MAX_Y] = {{0}}; // This line was just added to test the .txt writing
    saveMap(mapLayout);
    return 0;
}

void saveMap(int mapLayout[MAX_X][MAX_Y])
{

    FILE * mapFile;
    int x = 0;
    int y = 0;

    mapFile = fopen("maps_save.txt","w"); // w means we are able to write it and create it if it didn't exist
    if (mapFile == NULL)
    {
        perror("Error:\t The program could not open the file where the map was saved.");
    }
    else
    {
        for (x = 0; x < MAX_X; x++)
        {
            for (y = 0; y < MAX_Y; y++)
            {
                fprintf(mapFile,"mapLayout\t[%d]\t[%d]\t%d\n",x ,y ,mapLayout[x][y]); // Not sure if the parenthesis are needed
            }
        }
        printf("\nMap saved in maps_save.txt\n");
        fclose(mapFile);
    }
}
