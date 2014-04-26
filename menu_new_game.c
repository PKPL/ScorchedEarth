//---------------------------- New game ----------------------------------
// Start new game
//------------------------------------------------------------------------

#include "menu_new_game.h"
#include "unit.h"

void game_loop()
{
    unit_func();
    int queue = 1; //1 - Player, 2 - Bot
    int max_players = 2;
    while(player.hp > 0 && bot.hp > 0)
    {
        //Main game loop :)

        if(queue == 1)
        {
            //Player move

                //Choose power and angle

                //----------------------

                //Shooting with animation

                //-----------------------

            //-----------
        }

        else
        {
            //Bot move

                //Choose power and angle

                //----------------------

                //Shooting with animation

                //-----------------------

            //--------
        }

        queue = queue + 1;
        if(queue >= max_players)queue = 1; //Returning to player move
        //-----------------
    }

    system("cls");
    if(player.hp <= 0)
    {
        //Inform about victory

        //--------------------

        //Back to menu

        //------------
    }

    else
    {
        //Inform about defeat

        //--------------------

        //Back to menu

        //------------
    }
}
