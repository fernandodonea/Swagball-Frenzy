#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Player
{
    private:
        sf::RectangleShape shape;

        void initVariables();
        void initShape();

    public:
        //Constructors and Destructors
        Player();
        virtual ~Player();

        void update();
        void render(sf::RenderTarget* target);
};




#endif // PLAYER_H