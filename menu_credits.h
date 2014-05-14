#ifndef __MENU_CREDITS_H__
#define __MENU_CREDITS_H__

//---------------------------- Credits -----------------------------------
// Credits - list of people involved in creating a game
//------------------------------------------------------------------------

#include <windows.h>
#include "defines.h"

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c);
void credits();

#endif // __MENU_CREDITS_H__
