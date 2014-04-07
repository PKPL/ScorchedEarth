//---------------------------- Draw maps ---------------------------------
// Drawing maps
//------------------------------------------------------------------------

#include "drawing_maps.h"

void test_drawing_map (int mapLayout [MAX_X][MAX_Y])
{
    double x0;
    double y0;

    system("mode 100, 80");
    for (x0 = 0.0; x0 < (double) MAX_X; x0++)
    {
        for (y0 = 0.0; y0 < (double) MAX_Y; y0++)
        {
            gotoxy((int)x0, 80-(int)y0);
            printf("%d", mapLayout[(int)x0][(int)y0]);
        }
    }
    _getch();
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
