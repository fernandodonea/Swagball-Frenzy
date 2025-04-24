#ifndef SWAG_BALL_H
#define SWAG_BALL_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum SwagBallTypes {DEFAULT=0, DAMAGING, HEALING, NROFTYPES};


class SwagBall
{
    private:
        sf::CircleShape shape;
        int type;

        void _InitShape(const sf::RenderWindow& window);
     
    public:
        //Constructors and Destructors
        SwagBall (const sf::RenderWindow& window, int type);
        virtual ~SwagBall ();  

        //Accesor
        const sf::CircleShape GetShape() const;
        const int& GetType() const;

        //Functions
        void Update(); 
        void Render(sf::RenderTarget &target);
}; 

#endif // SWAG_BALL_H