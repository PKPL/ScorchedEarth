//---------------------------- Credits -----------------------------------
// Credits - list of people involved in creating a game
//------------------------------------------------------------------------
#include <windows.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch(c){
	case NOCURSOR:
		CurInfo.dwSize=1;
		CurInfo.bVisible=FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize=100;
		CurInfo.bVisible=TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize=20;
		CurInfo.bVisible=TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}


void credits()
{
    setcursortype(NOCURSOR);
    printf("The game is made by international team of students from:");
    Sleep( 1500 );
    system( "cls" );
    printf("\tItaly");
    Sleep( 1500 );
    printf("\n\nFederico Bollotta");
    printf("\n  Lorenzo Romanelli");
    printf("\n");
    Sleep( 3000 );
    system( "cls" );
    printf("\tPoland");
    Sleep( 1500 );
    printf("\n\nLukasz Czechowicz");
    printf("\n  Anna Gil");
    printf("\n    Konrad Dziurdz");
    printf("\n");
    Sleep( 3000 );
    system( "cls" );
    printf("\tPortugal");
    Sleep( 1500 );
    printf("\n\nDaniel Pinto");
    printf("\n  Nuno Valente");
    printf("\n    Roberto Ribeiro");
    printf("\n");
    Sleep( 3000 );
    system( "cls" );
    printf("Coordinator of the project was Mr. Pawel Lempa");
    Sleep( 3000 );
    system( "cls" );
    printf("\n Thanks to ERASMUS IP Lifelong Learning Programme");
    Sleep( 4000 );

    printf("\n\n \tLeiria, Portugal 2014");
    setcursortype(NORMALCURSOR);
    getch();
    return 0;

}
