//---------------------------- Load Maps ---------------------------------
// Loading maps
// PORTUGUESE TEAM
//------------------------------------------------------------------------

#include "maps_load.h"

bool load_Map (int map_layout[MAX_X][MAX_Y])
{
    bool checkInteger = true;
    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            if (map_layout[x][y] % 2 != 0 && map_layout[x][y] % 2 != 1) // is not integer
            {
                printf("Map generation error: Contents of array different than expected.\n");
                checkInteger = !checkInteger;
                break;
            }
        }
    }

    if (checkInteger)
    {
        char option; // Because we will be different names for each map, we need to ask the name of the map that the user wants to load.
    static bool existing_Map = false; // This variable allows to know if one map was already loaded. So, in order to this information will be not destroyed , we putted 'static int'
    if (existing_Map != 0)
    {
        option = option_User ("You already loaded one map, do you want to load another and forget the last");
        if (option == 'Y')
        {
            reading_from_File (map_layout);
            existing_Map = true;
        }
    }
    else
    {
        bool sucess = reading_from_File (map_layout);
        if (sucess) {
            existing_Map = true;
            return true;
        }
    }
    return false;
    }


}

char option_User (char *str)
{
    char option;
    printf ("%s?\n(Y/N)", str);
    do
    {
        fflush (stdin);
        option = getchar ();
        if (option != 'Y' && option != 'N')
        {
            printf ("Only 'Y' or 'N'\n");
        }
    }
    while (option != 'Y' && option != 'N');
    return option;
}

void read_String(char str[], int max)
{
    char * ptr = NULL;
    do
    {
        fgets(str, max, stdin);
        ptr = strchr(str, '\n');
        if (ptr != NULL)
        {
            *ptr = '\0';
        }
        if (strlen (str) == 0)
        {
            printf ("Write the name of the map.\n");
        }
        else
        {
            strcat (str, ".txt"); //concatenating the name; in this case, because it is a text file we concatenate ".txt"
        }
    }
    while (strlen (str) == 0);
}

bool reading_from_File (int map_layout [MAX_X][MAX_Y])
{
    int x, y;
    char name_File_Map[MAX_NAME_FILE];
    FILE *map_Load = NULL;
    fflush (stdin);
    printf ("Name of the map to load: ");
    read_String(name_File_Map, MAX_NAME_FILE);
    map_Load = fopen (name_File_Map, "r");
    if (map_Load == NULL)
    {
        fprintf (stderr, "Error on trying to load the map file");
    }
    else
    {
        for (y = 0; y < MAX_Y; y++)
        {
            for (x = 0; x < MAX_X; x++)
            {
                fscanf (map_Load, "%d", map_layout[x][y]);
                if (map_layout[x][y] % 2 != 0 && map_layout[x][y] % 2 != 1) // is not integer
                {
                    fprintf(stderr, "Map generation error: Contents of array different than expected.\n");
                    return false;
                }
            }
        }
        fclose (map_Load);
        return true;
    }
    return false;
}
