#include "Game.h"

void Game::initVariables()
{
    this->endGame=false;

    this->spawnTimerMax=10.f;
    this->spawnTimer=this->spawnTimerMax;
    this->maxSwagBalls=10;

}
void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
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


void Game::spawnSwagBalls()
{
    //Timer
    if(this->spawnTimer<this->spawnTimerMax)
        this->spawnTimer+=1.f;
    else
    {
        if(this->swagBalls.size()<this->maxSwagBalls)
        {
            this->swagBalls.push_back(SwagBall(*this->window ));  

            this->spawnTimer+=1.f;

        }
    } 
}

void Game::updateCollision()
{
     //Check the collision
     for(size_t i=0;i<swagBalls.size();++i)
     {
        if(this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
        {
            this->swagBalls.erase(this->swagBalls.begin()+i);
        }
     }
}

void Game::update()
{
    pollEvents();

    this->spawnSwagBalls();

    this->player.update(this->window);
    this->updateCollision();
}
void Game::render()
{
    //Clearing the old frame
    this->window->clear();

    //Render stuf
    this->player.render(this->window); 
    
    for(auto i: this->swagBalls)
    {
        i.render(*this->window);

    }

    this->window->display();

}
