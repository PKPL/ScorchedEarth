//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include "menu_highscore.h"

	 player players[11];
	// bubble sorting

	int add_score( players[10].nickname, players[10].points)
	{
	    fp=fopen("highscore.txt", "r+");
	    check_top_ten();
	    fclose(fp);
	}
	void bubblesort(void)
 	{

		int i, j, temp;
		const int n=10;
		for (i = 0; i<n-1; i++)
	        {

			for (j=0; j<n-1-i; j++)
	            {
	            if (players[j].points > players[j+1].points)
				{
					temp =players[j+1];
					players[j+1] =players[j];
					players[j] = temp;
				}
			}
	        }



	}
	void save_score (void)
	{
	    for (int i=0; i<10; i++)
	    { fputs(players[i].nickname,fp);
	    fputs(players[i].points,fp);
	    }

 	}
 	void check_top_ten(void)
 	{
	 if (players[10].points> player[9].points)
	     {bubblesort();} save_score();  highscore();

 	}

 	void highscore(void)
     {

     putchar(inChar);
        inChar = getc(fp);

    fclose(fp);
}
