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

        void initShape(const sf::RenderWindow& window);
     
    public:
        //Constructors and Destructors
        SwagBall (const sf::RenderWindow& window);
        virtual ~SwagBall ();  

        const sf::CircleShape getShape() const;

        //Functions
        void update(); 
        void render(sf::RenderTarget &target);
}; 

#endif // SWAGBALL_H