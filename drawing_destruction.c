//---------------------------- Draw destructions -------------------------
// Drawing destructions
//------------------------------------------------------------------------

#include "drawing_destruction.h"

void test_drawing_destruction(int mapLayout [MAX_X][MAX_Y])
{
    checkIfHit();
    createExplosion(mapLayout); //Draws the explosion
    createDestruction(mapLayout); //Draws the destruction
}

int checkIfHit()
{
    int checkHitValue;
    return checkHitValue;
}

void createDestruction(int mapLayout [MAX_X][MAX_Y])
{
    int x, y;
    int breaksLoop = 0;


    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            if (mapLayout[x][y] == 50 && mapLayout[x][y-1] == 1) //This means this is the final position of the player projectile, as below it there is ground, so it hits the ground
            {
                mapLayout[x][y] = 0;

                if ((x - 1) >= 0)
                {
                    mapLayout[x-1][y] = 0;
                }

                if ((x + 1) <= MAX_X)
                {
                     mapLayout[x+1][y] = 0;
                }

                if ((y + 1) <= MAX_Y)
                {
                    mapLayout[x][y+1] = 0;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    mapLayout[x-1][y+1] = 0;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    mapLayout[x+1][y+1] = 0;
                }
                //The code above restores the explosion to empty


                if ((y - 1) >= 0)
                {
                    mapLayout[x][y-1] = 0;
                }

                if ((x - 1) >= 0 && (y - 1) >= 0)
                {
                    mapLayout[x-1][y-1] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 1) >= 0)
                {
                    mapLayout[x+1][y-1] = 0;
                }

                if ((y - 2) >= 0)
                {
                    mapLayout[x][y-2] = 0;
                }

                if ((x - 1) >= 0 && (y - 2) >= 0)
                {
                    mapLayout[x-1][y-2] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 2) >= 0)
                {
                    mapLayout[x+1][y-2] = 0;
                }

                y = MAX_Y;
                breaksLoop = 1;

                //The code above destroys terrain
            }
            else if (mapLayout[x][y] == 60 && mapLayout[x][y-1] == 1) //This means this is the final position of the enemy projectile, as below it there is ground, so it hits the ground
            {
                mapLayout[x][y] = 0;

                if ((x - 1) >= 0)
                {
                    mapLayout[x-1][y] = 0;
                }

                if ((x + 1) <= MAX_X)
                {
                     mapLayout[x+1][y] = 0;
                }

                if ((y + 1) <= MAX_Y)
                {
                    mapLayout[x][y+1] = 0;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    mapLayout[x-1][y+1] = 0;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    mapLayout[x+1][y+1] = 0;
                }
                //The code above restores the explosion to empty


                if ((y - 1) >= 0)
                {
                    mapLayout[x][y-1] = 0;
                }

                if ((x - 1) >= 0 && (y - 1) >= 0)
                {
                    mapLayout[x-1][y-1] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 1) >= 0)
                {
                    mapLayout[x+1][y-1] = 0;
                }

                if ((y - 2) >= 0)
                {
                    mapLayout[x][y-2] = 0;
                }

                if ((x - 1) >= 0 && (y - 2) >= 0)
                {
                    mapLayout[x-1][y-2] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 2) >= 0)
                {
                    mapLayout[x+1][y-2] = 0;
                }

                y = MAX_Y;
                breaksLoop = 1;

                //The code above destroys terrain
            }

            if (breaksLoop == 1)
            {
                x = MAX_X;
            }
        }
    }
}

void createExplosion(int mapLayout [MAX_X][MAX_Y])
{
    int x, y;
    int breaksLoop = 0;


    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            if (mapLayout[x][y] == 50 && mapLayout[x][y-1] == 1) //This means this is the final position of the player projectile, as below it there is ground, so it hits the ground
            {
                //The code below will define where the explosion will be seen on the map. This is a basic implementation at this stage.
                mapLayout[x][y] = 100;

                if ((x - 1) >= 0)
                {
                    mapLayout[x-1][y] = 100;
                }

                if ((x + 1) <= MAX_X)
                {
                     mapLayout[x+1][y] = 100;
                }

                if ((y + 1) <= MAX_Y)
                {
                    mapLayout[x][y+1] = 100;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    mapLayout[x-1][y+1] = 100;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    mapLayout[x+1][y+1] = 100;
                }

                y = MAX_Y; //breaks out of the loop
                breaksLoop = 1;
            }
            else if (mapLayout[x][y] == 60 && mapLayout[x][y-1] == 1) //This means this is the final position of the enemy projectile, as below it there is ground, so it hits the ground
            {
                //The code below will define where the explosion will be seen on the map. This is a basic implementation at this stage.
                mapLayout[x][y] = 100;

                if ((x - 1) >= 0)
                {
                    mapLayout[x-1][y] = 100;
                }

                if ((x + 1) <= MAX_X)
                {
                     mapLayout[x+1][y] = 100;
                }

                if ((y + 1) <= MAX_Y)
                {
                    mapLayout[x][y+1] = 100;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    mapLayout[x-1][y+1] = 100;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    mapLayout[x+1][y+1] = 100;
                }

                y = MAX_Y; //breaks out of the loop
                breaksLoop = 1;
            }
        }

        if (breaksLoop == 1)
        {
            x = MAX_X;
        }
    }
}
