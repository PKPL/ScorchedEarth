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

int test_maps_load () {
    int x, y;
    int mapLayout[MAX_X][MAX_Y] = {{0}};
    load_Map (mapLayout);
}

void load_Map (mapLayout[MAX_X][MAX_Y])
{
    char option; // Because we will be different names for each map, we need to ask the name of the map that the user wants to load.
    static bool existingMap = false; // This variable allows to know if one map was already loaded. So, in order to this information will be not destroyed , we putted 'static int'
    if (existingMap != 0)
    {
        option = optionUser ("You already loaded one map, do you want to load another and forget the last");
        if (option == 'Y')
        {
            Map = readingfromFile ();
            existingMap = true;
        }
    }
    else
    {
        Map = readingfromFile ();
        existingMap = true;
    }
    return 0;
}

char optionUser (char *str)
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

void readString(char str[], int max)
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

int readingfromFile (mapLayout [MAX_X][])
{
    char nameFileMap[MAX_NAME_FILE];
    FILE *mapLoad = NULL;
    fflush (stdin);
    printf ("Name of the map to load: ");
    readString(nameFileMap, MAX_NAME_FILE);
    mapLoad = fopen (nameFileMap, "r");
    if (mapLoad == NULL)
    {
        fprintf (stderr, "Error on trying to load the map file");
    }
    else
    {
        for (i = 0; mapLoad != EOF; i++)
        /*
        fscanf ("", ..., Map.(...));

        fscanf ("", ..., Map.(...));

        (...)
        Here the function will read the text file created before.
        (...)

        fscanf ("", ..., Map.(...));

        fscanf ("", ..., Map.(...));
        */
        fclose (mapLoad);
    }
    return 0;
}
