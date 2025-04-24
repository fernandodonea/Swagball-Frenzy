
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

#include "player.h"
#include "swag_ball.h"

/*
Class that acts as a game engine
Wrapper Class
*/


class Game
{
    private:
        sf::VideoMode video_mode; 
        sf::RenderWindow *window; 
        bool end_game;
        sf::Event sfml_event;

        Player player;
         
        int points;

        sf::Font font;
        sf::Text gui_text;
        sf::Text end_game_text;

        std::vector<SwagBall> swag_balls;
        float spawn_timer_max;
        float spawn_timer;
        unsigned max_swag_balls; 

        void _InitVariables(); 
        void _InitWindow();
        void _InitText();
        void _InitFont();
        
    public:
        //Constructors and Destructors
        Game ();
        ~Game ();

        //Accessors
        const bool& GetEndGame() const;

        //Modifiers 

        //Functions 
        const bool Running() const;
        void PollEvents();

        void SpawnSwagBalls();
        const int RandBallType() const;

        void UpdatePlayer();
        void UpdateCollision();
        void UpdateGui();
        void Update();

        void RenderGui(sf::RenderTarget* target);
        void Render();
};

#endif // GAME_H