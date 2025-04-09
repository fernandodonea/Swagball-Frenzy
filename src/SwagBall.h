#ifndef SWAGBALL_H
#define SWAGBALL_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


class SwagBall
{
    private:
        sf::CircleShape shape;

        void initShape();
     
    public:
        //Constructors and Destructors
        SwagBall ();
        virtual ~SwagBall ();

        //Functions
        void update(); 
        void render(sf::RenderTarget *target);
}; 

#endif // SWAGBALL_H