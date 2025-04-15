
#ifndef GAME_H
#define GAME_H

//precompiled headers
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "SwagBall.h"

/*
Class that acts as a game engine
Wrapper Class
*/


class Game
{
    private:
        sf::VideoMode videoMode; 
        sf::RenderWindow *window; 
        bool endGame;
        sf::Event sfmlEvent;

        Player player;

        std::vector<SwagBall> swagBalls;
        float spawnTimerMax;
        float spawnTimer;
        unsigned maxSwagBalls; 

        void initVariables(); 
        void initWindow();

    public:
        //Constructors and Destructors
        Game ();
        ~Game ();

        //Accessors

        //Modifiers 

        //Functions 
        const bool running() const;
        void pollEvents();

        void spawnSwagBalls();
        void update();
        void render();
};

#endif // GAME_H