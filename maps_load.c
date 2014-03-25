//---------------------------- Load Maps ---------------------------------
// Loading maps
//------------------------------------------------------------------------

// stdilib.h and stdio.h already included in maps_create.c
#include <stdbool.h> // includes the bool variable types, that is best when we just want true or false, 0 or 1 for the value, and takes less for RAM.

#define MAX_NAME_FILE 50

char optionUser (char *str);
void readString (char *str, int max);

int * maps_load () {
	char option, nameFileMap [MAX_NAME_FILE]; // Because we will be different names for each map, we need to ask the name of the map that the user wants to load.
	FILE *mapLoad = NULL;
	static bool existingMap = false; // This variable allows to know if one map was already loaded. So, in order to this information will be not destroyed , we putted 'static int'
	if (existingMap != 0) {
		optionUser ("You already loaded one map, do you want to load another");
		option = optionUser ();
		if (option == 'Y') {
			fflush (stdin);
			readString(nameFileMap, MAX_NAME_FILE);
			mapLoad = fopen (nameFileMap, r);
			if (mapLoad == NULL) {
				fprintf (stderr, "Error on trying to load de map file");
			}
			else {
				/*
				fscanf ();

				fscanf ();
				
				(...)
				Here the function will read the text file created before.
				(...)

				fscanf ();

				fscanf ();
				*/	
			existingMap = true;
			}
		}
	}
	return mapLoad; // returns the map loaded.
}

char optionUser (char *str) {
	char option;
	printf ("%s?\n(Y/N)",option);
	do {
	fflush (stdin);
	option = getchar ();
	if (option != 'Y' && option != 'N') {
		printf ("Only 'Y' or 'N'\n");
		}
	} while (option != 'Y' && option != 'N');
	return option;
}

void readString(char str[], int max)
{
    char * ptr = NULL;
    fgets(str, max, stdin);

    do {
    	if (strlen (str) == 0) {
    		printf ("Write the name of the map.\n");
    	}
    	else {
    		ptr = strchr(str, '\n');
    			if (ptr != NULL)
    			{
       			 *ptr = '\0';
    			}
			}
	} while (strlen (str) == 0);
}