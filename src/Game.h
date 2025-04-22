
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
#include <sstream>

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
         
        int points;

        sf::Font font;
        sf::Text guiText;
        sf::Text endGameText;

        std::vector<SwagBall> swagBalls;
        float spawnTimerMax;
        float spawnTimer;
        unsigned maxSwagBalls; 

        void initVariables(); 
        void initWindow();
        void initText();
        void initFont();
        
     

    public:
        //Constructors and Destructors
        Game ();
        ~Game ();

        //Accessors
        const bool& getEndGame() const;


        //Modifiers 

        //Functions 
        const bool running() const;
        void pollEvents();

        void spawnSwagBalls();
        const int randBallType() const;

        void updatePlayer();
        void updateCollision();
        void updateGui();
        void update();

        void renderGui(sf::RenderTarget* target);
        void render();
};

#endif // GAME_H