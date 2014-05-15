//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------
#include "menu_highscore.h"

FILE *fp;
char c_open;

// bubble sorting

void add_score()
{player_highscore players[11];
    fp=fopen("highscore.txt", "r+");
    check_top_ten(players);
    fclose(fp);
}
void bubblesort(player_highscore players[11])
{
    fp=fopen("highscore.txt", "r+");
    int i_loop, j_loop, temp;

    for (i_loop = 0; i_loop<9; i_loop++)
    {

        for (j_loop=0; j_loop<9-i_loop; j_loop++)
        {
            if (players[j_loop+1].points < players[j_loop].points)
            {
                temp = players[j_loop+1].points;
                players[j_loop+1].points =players[j_loop].points;
                players[j_loop].points = temp;
            }
        }
    }
    fclose(fp);
}

void save_score (player_highscore players[11])
{
    int counter_loop;
    for (counter_loop=0; counter_loop<10; counter_loop++)
    {
        fputs(players[counter_loop].nickname,fp);
        fputs(players[counter_loop].points,fp);
    }

}
void check_top_ten(player_highscore players[11])
{
    if (players[10].points> players[9].points)
    {
        bubblesort(players);
    }
    save_score(players);
    highscore(players);

}

void highscore()
{
    fp=fopen("highscore.txt", "r+");
    while ((c_open=fgetc(fp))!=EOF)
        printf("%c", c_open);

    fclose(fp);

    printf("\n\n \tPress any button to back to menu");
    getch();
    return(0);

}
