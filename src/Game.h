
#ifndef GAME_H
#define GAME_H

//precompiled headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <ctime>
#include <sstream>

/*
Class that acts as a game engine
Wrapper Class
*/


class Game
{
    private:
        sf::VideoMode videoMode; //Video mode
        sf::RenderWindow *window; 
        bool endGame;

        void initVariables(); 
        void initWindow();

    public:
        //Constructors and Destructors
        Game ();
        ~Game ();

        //Accessors

        //Modifiers

        //Functions 
        void update();
        void render();
};

#endif // GAME_H