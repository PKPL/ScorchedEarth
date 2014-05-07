//---------------------------- Draw shots --------------------------------
// Drawing shots
// ROBERTO RIBEIRO
// PORTUGUESE TEAM
//------------------------------------------------------------------------

#include "drawing_shots.h"

extern int map_layout [MAX_X][MAX_Y];

void test_drawing_shots ()
{
    int x, y;
    missile_data m;
    int map_layout[MAX_X][MAX_Y] = {{0}}; // just for testing
    drawing_shots(map_layout, m);
}


void drawing_shots (int i,int map_layout[MAX_X][MAX_Y], missile_data *m)
{


int sign = map_layout[m->x_vector_coordinate[i]][m->y_vector_coordinate[i]];


if(m->x_vector_coordinate[i] != player.x && m->y_vector_coordinate[i] != player.y && (79-m->y_vector_coordinate[i]) < MAX_Y && m->x_vector_coordinate[i] >= 0 && m->x_vector_coordinate[i] <= MAX_X )
{
    gotoxy(m->x_vector_coordinate[i],79-(m->y_vector_coordinate[i]));
    printf("8");
    Sleep(20);
}
    gotoxy(m->x_vector_coordinate[i],79-(m->y_vector_coordinate[i]));
    switch (sign)
    {
    case 0:
    printf(" ");
    break;
    case 1:
    printf("1");
    break;
    }

}
