//---------------------------- Load Maps ---------------------------------
// Loading maps
//------------------------------------------------------------------------

/*
PORTUGUESE TEAM

NUNO VALENTE
ROBERTO RIBEIRO
DANIEL PINTO

*/

// stdilib.h and stdio.h already included in maps_create.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // includes the bool variable types, that is best when we just want true or false, 0 or 1 for the value, and takes less for RAM.
#include <string.h>
#define MAX_NAME_FILE 50

char optionUser (char *str);
void readString (char *str, int max);
int readingfromFile ();

int maps_load ()
{
    char option; // Because we will be different names for each map, we need to ask the name of the map that the user wants to load.
    int Map; // for now is an int (just for example), but we will change, according the struct of the map;
    static bool existingMap = false; // This variable allows to know if one map was already loaded. So, in order to this information will be not destroyed , we putted 'static int'
    if (existingMap != 0)
    {
        option = optionUser ("You already loaded one map, do you want to load another");
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
    return Map; // returns the map loaded.
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
    int n;
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

int readingfromFile ()
{
    int Map; //that will be a struct for the map, and not an int. This int is for example and meaning.
    char nameFileMap[MAX_NAME_FILE];
    FILE *mapLoad = NULL;
    fflush (stdin);
    printf ("Name of the map to load: ");
    readString(nameFileMap, MAX_NAME_FILE - 4);
    //Cuts 4 chars at MAX_NAME_FILE in order to concatenate ".txt"; That will be more user-friendly, the played doesn't need to write ".txt", but just the name.
    mapLoad = fopen (nameFileMap, "r");
    if (mapLoad == NULL)
    {
        fprintf (stderr, "Error when trying to load the map file");
    }
    else
    {
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
    return Map; // for now it is int, but will return the struct of file;
}
