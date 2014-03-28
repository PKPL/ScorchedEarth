//---------------------------- Load Maps ---------------------------------
// Loading maps
//------------------------------------------------------------------------
/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO
*/

#include "maps_load.h"

void test_maps_load () {
    int x, y;
    int mapLayout[MAX_X][MAX_Y] = {{0}}; // just for testing
    load_Map (mapLayout);
}

void load_Map (int mapLayout[MAX_X][MAX_Y])
{
    char option; // Because we will be different names for each map, we need to ask the name of the map that the user wants to load.
    static bool existing_Map = false; // This variable allows to know if one map was already loaded. So, in order to this information will be not destroyed , we putted 'static int'
    if (existing_Map != 0)
    {
        option = option_User ("You already loaded one map, do you want to load another and forget the last");
        if (option == 'Y')
        {
            reading_from_File (mapLayout);
            existing_Map = true;
        }
    }
    else
    {
        reading_from_File (mapLayout);
        existing_Map = true;
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

void reading_from_File (int mapLayout [MAX_X][MAX_Y])
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
     for (y = 0; y < MAX_Y; y++) {
            for (x = 0; x < MAX_X; x++) {
                fscanf (map_Load, "%d", mapLayout[x][y]);
            }
        }
    fclose (map_Load);
    }
}
