//---------------------------- Credits -----------------------------------
// Credits - list of people involved in creating a game
//------------------------------------------------------------------------
#include <stdio.h>
#include "menu_credits.h"

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
    Sleep( 2500 );
    system( "cls" );
    printf("\tItaly");
    Sleep( 1000 );
    printf("\n\nFederico Bollotta");
    printf("\n  Lorenzo Romanelli");
    printf("\n");
    Sleep( 2500 );
    system( "cls" );
    printf("\tPoland");
    Sleep( 1000 );
    printf("\n\nLukasz Czechowicz");
    printf("\n  Anna Gil");
    printf("\n    Konrad Dziurdz");
    printf("\n");
    Sleep( 2500 );
    system( "cls" );
    printf("\tPortugal");
    Sleep( 1000 );
    printf("\n\nDaniel Pinto");
    printf("\n  Nuno Valente");
    printf("\n    Roberto Ribeiro");
    printf("\n");
    Sleep( 2500 );
    system( "cls" );
    printf("Coordinator of the project was Mr. Pawel Lempa and Mr. Grzegorz Filo");
    Sleep( 3000 );
    system( "cls" );
    printf("\n Thanks to ERASMUS IP Lifelong Learning Programme");
    Sleep( 4000 );

    printf("\n\n \tLeiria, Portugal 2014");
    printf("\n\n\tPress any button to back to menu");
    setcursortype(NORMALCURSOR);
    getch();
}
