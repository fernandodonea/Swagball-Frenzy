#include "Game.h"

void Game::initVariables()
{
    this->endGame=false;

}
void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Titlebar | sf::Style::Close);
}



// Constructos and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}
Game::~Game()
{
    delete this->window;
}


//Functions
const bool Game::running() const
{
    return this->window->isOpen();
}
void Game::pollEvents()
{
    while(this->window->pollEvent(this->sfmlEvent))
    {
        if(this->sfmlEvent.type == sf::Event::Closed)
            this->window->close();
        if(this->sfmlEvent.type == sf::Event::KeyPressed)
            if(this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->window->close();
    }
}
void Game::update()
{
    pollEvents();
}
void Game::render()
{
    //Clearing the old frame
    this->window->clear();

    //Render stuf
    this->player.render(this->window); 

    
    this->window->display();

}
