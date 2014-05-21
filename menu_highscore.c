//---------------------------- Highscore ---------------------------------
// Top ten scores of a game
//------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include "menu_highscore.h"

// bubble sorting

bool read_highscores()
{
    FILE* fp;
    fp = fopen("highscore.txt", "r");
    char c_open;
    char array_number[5];
    char array_name[20];
    int k = 0, j = 0;
    bool isNumber = true;
    bool isError = false;
//    while ((c_open = fgetc(fp)) != EOF)
//        printf("%c", c_open);
    while ((c_open = fgetc(fp)) != EOF) {
        if (c_open == '\n') {
            isNumber = true;
            k = 0;
            j = 0;
            printf("\n");
            continue;
        }
        if (c_open == ' ' && isNumber == true) {
            isNumber = false;
            printf(" ");
            continue;
        }
        if (isNumber) {
            if (k >= 5) {
                isError = true;
                break;
            }
            array_number[k++] = c_open;
            printf("%c", array_number[k-1]);
        }
        else {
            if (j >= 20) {
                isError = true;
                break;
            }
            array_name[j++] = c_open;
            printf("%c", array_name[j-1]);
        }
    }


    fclose(fp);
    return isError;
}


void save_highscore (player_highscore scores[11]) {
    FILE* f;
    int i;
    f = fopen("highscore.txt", "w");
    bubblesort(scores);
    for (i = 0; i < 10; i++) {
        fprintf(f, "%d %s\n", scores[i].points, scores[i].nickname);
    }
    fclose(f);
}


void bubblesort(player_highscore players[11])
{
    int i;
    bool isClear = true;
    player_highscore temp;

    for (i = 0; i<10; i++)
    {
        if (players[i].points < players[i+1].points) {
            temp = players[i];
            players[i] = players[i+1];
            players[i+1] = temp;
            isClear = false;
        }
        if (i == 9 && isClear == false) {
            isClear = true;
            i = -1;
        }
    }
}

//
//void save_score (player_highscore players[11])
//{
//    int counter_loop;
//    for (counter_loop=0; counter_loop <10; counter_loop++)
//    {
//        fputs(players[counter_loop].nickname, fp);
//        fputs(players[counter_loop].points, fp);
//    }
//
//}
//
//void check_top_ten(player_highscore players[11])
//{
//    if (players[10].points> players[9].points)
//    {
//        bubblesort(players);
//    }
//    save_score(players);
//}
//
//void highscore()
//{
//    fp=fopen("highscore.txt", "r+");
//    while ((c_open=fgetc(fp))!=EOF)
//        printf("%c", c_open);
//    fclose(fp);
//
//    printf("\n\n \tPress any button to back to menu");
//    getch();
//}
