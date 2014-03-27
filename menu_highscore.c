//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include "menu_highscore.h"


 player players[11];
// bubble sorting
void bubblesort(void)
{
      fp=fopen("highscore.txt", "r+");
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


            fclose(fp);
}

void save_score ()
{  fp=fopen("highscore.txt", "r+w");
    for (int i=0; i<10; i++)
    { fputs(players[i].nickname,fp);
    fputs(players[i].points,fp);
    }
 fclose(fp);
}
void check_top_ten()
{
 if (players[10].points> player[9].points)
     {bubblesort();} save_score();  highscore();

}

void highscore()
{
    printf("Highscore\n\n");


    fp=fopen("highscore.txt", "r+");


     inChar = getc(fp);
    while (inChar != EOF)
    {
        putchar(inChar);
        inChar = getc(fp);
    }

    fclose(fp);
}


