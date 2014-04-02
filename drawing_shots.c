//---------------------------- Draw shots --------------------------------
// Drawing shots
//------------------------------------------------------------------------

#include "drawing_shots.h"

void test_drawing_shots ()
{
    int x, y;
    missile_data m;
    int mapLayout[MAX_X][MAX_Y] = {{0}}; // just for testing
    drawing_shots(mapLayout, m);
}

void drawing_shots (int mapLayout[MAX_X][MAX_Y], missile_data m)
{
    int i, j, k, x, y;

    int vetor[VECTOR_LENGTH];

    for (j = VECTOR_LENGTH, k = 0 ; j >= 0, k < VECTOR_LENGTH ; j-- , k++)
    {
        vetor[k] =  m.y_vector_coordinate[j]; // we need to change the the elements's order
    }

    for (i = 0; i < VECTOR_LENGTH; i++)
    {
        x = m.x_vector_coordinate[i];
        y = vetor[i];

        if (mapLayout[x][y] != SKY) // if the missile hits something, it explodes
        {
            // EXPLOSION!
            i = VECTOR_LENGTH; // it stops the for cycle
        }
        else // it draws the missile's trajectory
        {
            mapLayout[x][y]=PLAYER_SHOT; // We have no reference for the shooter, so it stays the player for now
        }
    }


}
