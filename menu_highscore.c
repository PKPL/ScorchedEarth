//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include <windows.h>
#include <time.h>
#include <stdio.h>
FILE *fp;
const int n= 10;

  struct player
 {
   char nickname[20];
   int points;
 }player[11] ;
int inChar;

void bubblesort()
{
	int i, j, temp;
	const int n=10;
	for (i = 0; i<n-1; i++)
        {
		for (j=0; j<n-1-i; j++)
		{
			if (player[j].points > player[j+1].points)
			{
				temp =player[j+1];
				player[j+1] = player[j];
				player[j] = temp;
			}
		}
        }
}

void add_score ()
{

}
void check_top_ten()
{
    if (player[10].points> player[9].points)
        sort();
    else {}
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


