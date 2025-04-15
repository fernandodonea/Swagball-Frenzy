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


        float movementSpeed; 
        int health;
        int maxHealth ; 

        

        void initVariables();
        void initShape();


    public:
        //Constructors and Destructors
        Player(float x=0.f, float y=0.f);
        virtual ~Player();

        const sf::RectangleShape& getShape() const;

        void updateInput(); 
        void updateWindowBoundsCollision(const sf::RenderTarget * target);
        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
};




#endif // PLAYER_H