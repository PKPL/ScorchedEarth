//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------


#include <stdio.h>
FILE *fp;

int inChar;

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


