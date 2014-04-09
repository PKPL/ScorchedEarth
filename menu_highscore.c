//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include "menu_highscore.h"


	// bubble sorting

	void add_score()
	{
	    fp=fopen("highscore.txt", "r+");
	    check_top_ten();
	    fclose(fp);
	}
	void bubblesort(void)
 	{
 fp=fopen("highscore.txt", "r+");
		int i, j, temp;
		const int n=10;
		for (i = 0; i<n-1; i++)
	        {

			for (j=0; j<n-1-i; j++)
	            {
	            if (players[j+1].points < players[j].points)
				{
					temp = players[j+1].points;
					players[j+1].points =players[j].points;
					players[j].points = temp;
				}
			}
	        }
	        fclose(fp);
	}

	void save_score (void)
	{int counter;
	    for (counter=0; counter<10; counter++)
	    { fputs(players[counter].nickname,fp);
	      fputs(players[counter].points,fp);
	    }

 	}
 	void check_top_ten(void)
 	{
	 if (players[10].points> players[9].points)
	     {bubblesort();}
	     save_score();
        highscore();

 	}

 	void highscore(void)
     {fp=fopen("highscore.txt", "r+");
        while ((c=fgetc(fp))!=EOF)
        printf("%c", c);

    fclose(fp);
}
