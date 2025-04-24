#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

namespace Game_Entities
{

class Player
{
    private:
        sf::RectangleShape shape;


        float movement_speed; 
        int hp;
        int hp_max; 


        void _InitVariables();
        void _InitShape();


    public:
        //Constructors and Destructors
        Player(float x=0.f, float y=0.f);
        virtual ~Player();

        //Accesssors
        const sf::RectangleShape& GetShape() const;
        const int& GetHp() const;
        const int& GetHpMax() const;


        //Function
        void TakeDamage(const int damage);
        void GainHealth(const int health);

        void UpdateInput(); 
        void UpdateWindowBoundsCollision(const sf::RenderTarget * target);
        void Update(const sf::RenderTarget* target);
        void Render(sf::RenderTarget* target);
};

}//namespace Game_Entities


#endif // PLAYER_H