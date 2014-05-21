/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

#include "maps_save.h"
#include "maps_load.h"

void create_folder(char folderName[])
{
#ifdef _WIN32
    CreateDirectory(folderName,NULL);
#else
    mkdir(folderName, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
}

void save_map(int map_layout[MAX_X][MAX_Y])
{

    FILE * map_file;
    int x = 0;
    int y = 0;
    char name_File_Map[MAX_NAME_FILE];


    create_folder("Saved_Maps");
    printf ("Name of the map to save: ");
    read_String(name_File_Map, MAX_NAME_FILE);
    while(kbhit())getch();
    map_file = fopen(name_File_Map,"w"); // w means we are able to write it and create it if it didn't exist
    if (map_file == NULL)
    {
        perror("Error:\t The program could not open the file where the map was saved");
    }
    else
    {
        for (x = 0; x < MAX_X; x++)
        {
            for (y = 0; y < MAX_Y; y++)
            {
                fprintf(map_file, "%d", map_layout[x][y]);
            }
        }
        int i;
        printf("\nMap saved in a file named \"");
        int array_length = strlen(name_File_Map) - 4;
        for (i = 11; i < array_length; i++)
        {
            printf ("%c", name_File_Map[i]);

        }
        printf("\"\n");
        Sleep (1500);
        fclose(map_file);
    }
}
