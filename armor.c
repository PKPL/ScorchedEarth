#include <stdio.h>
#include <windows.h>
#include "armor.h"

armorCoords create_armor(int map_layout[MAX_X][MAX_Y], int armor_number)
{
    int tempX, tempY;
    armorCoords coords;
    bool exit = false;
    if (armor_number%2 == 0) {
        srand(time(NULL));
        tempX = rand() % (MAX_X / 2);

        srand(rand() + time(NULL) + NUMBER_OF_ARMORS);
        tempY = rand() % MAX_Y;

        while (!exit) {
            if (map_layout[tempX][tempY] == 0) {
                coords.x = tempX;
                coords.y = tempY;
                exit = true;
            }
            else tempY--;
            if (tempY < 0) {
                tempX++;
                if (tempX > MAX_X/2) {
                    srand(time(NULL));
                    tempX = rand() % (MAX_X / 2);
                }
            }
        }
    }
    else if (armor_number%2 == 1)
        {
        srand(time(NULL) + rand());
        tempX = rand() % (MAX_X / 2);

        srand(time(NULL) - NUMBER_OF_ARMORS);
        tempY = rand() % MAX_Y;

        while (!exit) {
            if (map_layout[MAX_X - tempX][tempY] == 0) {
                coords.x = MAX_X - tempX;
                coords.y = tempY;
                exit = true;
            }
            else tempY--;
            if (tempY < 0) {
                tempX++;
                if (tempX < MAX_X/2) {
                    srand(time(NULL) - NUMBER_OF_ARMORS + rand());
                    tempX = rand() % (MAX_X / 2);
                }
            }
        }
    }
    return coords;
}

void drawing_armors (int map_layout[MAX_X][MAX_Y], int armor_number)
{
    armorCoords armor;
    int i;

    for (i = 0; i < armor_number; i++) {
        armor = create_armor(map_layout, i);
        map_layout[armor.x][armor.y] = ARMOR;
        gotoxy(armor.x, 79 - armor.y);
        printf("%c", 8);
    }
}

void hit_armor (int map_layout[MAX_X][MAX_Y], int x, int y, bool isBot) {
    if (isBot)
        bot.armor = 100;
    else
        player.armor = 100;
    gotoxy(x, 79 - y);
    printf("ARMOR!");
    Sleep(1000);
    draw_armor_hit(map_layout, x, y);
    player.points += 10;
    map_layout[x][y] = 0;
}

void draw_armor_hit (int map_layout[MAX_X][MAX_Y], int x, int y) {
    int i;
    for (i = 0; i < 6; i++) {
        gotoxy(x+i, 79 - y);
        switch (map_layout[x+i][y]) {
            case SKY: printf(" "); break;
            case GROUND: printf("1"); break;
            case PLAYER: printf("3"); break;
            case ENEMY: printf("2"); break;
            case ARMOR: printf(" "); break;
        }
    }
}
