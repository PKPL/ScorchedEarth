//---------------------------- Load Maps ---------------------------------
// Loading maps
// PORTUGUESE TEAM
//------------------------------------------------------------------------

#include "maps_load.h"

bool load_Map (int map_layout[MAX_X][MAX_Y])
{
    int x, y;
    char name_File_Map[MAX_NAME_FILE];
    FILE *map_Load = NULL;
    char option = option_User("\n\nDo you want to load an existing map");
    if (option == 'Y')
    {
        list_dir ();
        printf ("\n\nName of the map to load: ");
        read_String(name_File_Map, MAX_NAME_FILE);
        fflush(stdin);
        map_Load = fopen (name_File_Map, "r");
        if (map_Load == NULL)
        {
            perror("Error on trying to load the map");
            Sleep(1500);
        }
        else
        {
            char ch;
            for (x = 0; x < MAX_X; x++)
            {
                for (y = 0; y < MAX_Y; y++)
                {
                    fscanf (map_Load, "%c", &ch);
                    map_layout[x][y] = ch - '0';
                }
            }
            fclose (map_Load);
            return true;
        }
    }
    else
        return false;
}

char option_User (char *str)
{
    char option;
    printf ("%s?\n(Y/N)", str);
    do
    {
        option = getchar ();
        option = toupper (option);
        fflush(stdin);
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
        char path[13] = "Saved_Maps\\";
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
            strcat (path, str);
            strcpy(str, path);
        }
    }
    while (strlen (str) == 0);
}

void list_dir()
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("Saved_Maps\\")) != NULL)
    {
        printf("List of saved maps:\n");
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    }
    else
    {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
}
