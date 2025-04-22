#ifndef SWAGBALL_H
#define SWAGBALL_H


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

        void initShape(const sf::RenderWindow& window);
     
    public:
        //Constructors and Destructors
        SwagBall (const sf::RenderWindow& window, int type);
        virtual ~SwagBall ();  

        //Accesor
        const sf::CircleShape getShape() const;
        const int& getType() const;

        //Functions
        void update(); 
        void render(sf::RenderTarget &target);
}; 

#endif // SWAGBALL_H