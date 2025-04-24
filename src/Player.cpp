#include "player.h"

void Player::_InitVariables()
{
    this->movement_speed=5.f; 
    this->hp_max=10;
    this->hp=this->hp_max; 
}
void Player::_InitShape()
{
    this->shape.setFillColor(sf::Color::Magenta);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
}


Player::Player(float x, float y)
{
    this->shape.setPosition(x,y);


    this->_InitVariables();
    this->_InitShape();
}

Player::~Player()
{
 
}


const sf::RectangleShape& Player::GetShape() const
{
    return this->shape;
}

const int& Player::GetHp() const
{
    return this->hp;
}
const int& Player::GetHpMax() const
{
    return this->hp_max;
}


//Functions
void Player::TakeDamage(const int damage)
{
    if(this->hp>=0)
        this->hp-=damage;
    if (this->hp<0)
        this->hp=0;


}
void Player::GainHealth(const int health)
{
    if(this->hp < this->hp_max)
        this->hp+=health;
        
    if(this->hp > this->hp_max)
        this->hp=this->hp_max; 
}

void Player::UpdateInput()
{
    //Keyboard input
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movement_speed,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movement_speed,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f,-this->movement_speed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f,this->movement_speed);
    }
}
void Player::UpdateWindowBoundsCollision(const sf::RenderTarget * target)
{
    //Left
    if(this->shape.getGlobalBounds().left <=0.f) 
        this->shape.setPosition(0.f,this->shape.getGlobalBounds().top);
    //Right
    if((this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width)>=target->getSize().x)
        this->shape.setPosition(target->getSize().x-this->shape.getGlobalBounds().width,this->shape.getGlobalBounds().top);
    //Top
    if(this->shape.getGlobalBounds().top <=0.f) 
        this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f); 
    //Bottom
    if((this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height)>=target->getSize().y)
        this->shape.setPosition(this->shape.getGlobalBounds().left,target->getSize().y-this->shape.getGlobalBounds().height);
}

void Player::Update(const sf::RenderTarget* target)
{

    this->UpdateInput();

    //Window bounds collision
    this->UpdateWindowBoundsCollision(target);
    
}
void Player::Render(sf::RenderTarget * target)
{
    target->draw(this->shape);

} 
