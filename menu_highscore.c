//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------


#include <stdio.h>
FILE *fp;

int inChar;

int main()
{
printf("Highscore\n\n");
sort();

fp=fopen("highscore.txt", "r+");


     inChar = getc(fp);
while (inChar != EOF)
{
putchar(inChar);
inChar = getc(fp);
}
fclose(fp);
return 0;
}


