#include "game.h"

int main()
{

    //Initialise random seed
    srand(static_cast<unsigned int>(time(0))); 

    //Initialise the game object
    Game game;

    //Game loop
    while (game.Running())
    {
        game.Update();
        game.Render();
    }


    //End of application
    return 0; 
}