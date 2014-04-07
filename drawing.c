//---------------------------- Drawing -----------------------------------
// It combines the files responsible for drawing objects and maps
//------------------------------------------------------------------------

// Included libraries

// Included files
#include "drawing.h"

double x0 = 5.0;
double y0 = 10.0;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void test_drawing(int mapLayout [MAX_X][MAX_Y]) // function for agreagte testing
{
    printf("Drawing test\n");
    test_drawing_units(mapLayout);
<<<<<<< HEAD
    test_drawing_destruction(mapLayout);
    drawing(mapLayout);
}

void drawing (int mapLayout [MAX_X][MAX_Y])
{
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
=======
    //test_drawing_destruction(mapLayout);
>>>>>>> a37de7174a827e66903becc4c59ec78b9deb6950
}
