//---------------------------- Removing files ----------------------------
// Removing files
// Roberto and Daniel       Portuguese Team
//------------------------------------------------------------------------


	#include<stdio.h>
	#include "remove_save_files.h"
	#include "maps_load.h"

	int remove_file(void)
	{
    int status;
    char name_File_Map[MAX_NAME_FILE];


    read_String(name_File_Map, MAX_NAME_FILE);

   printf("Enter the name of file you wish to delete\n");

   status = remove(name_File_Map);

   if( status == 0 )
      printf("%s file deleted successfully.\n",name_File_Map);
   else
   {
      printf("Unable to delete the file\n");
      perror("Error");
   }

   return 0;
}
