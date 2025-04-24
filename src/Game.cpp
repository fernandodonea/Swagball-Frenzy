#include "game.h"

void Game::initVariables()
{
    this->end_game=false;

    this->spawn_timer_max=10.f;
    this->spawn_timer=this->spawn_timer_max;
    this->max_swag_balls=10;

    this->points=0;
}
void Game::initWindow()
{
    this->video_mode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->video_mode, "Swagball Frenzy", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initFont()
{
    if(!this->font.loadFromFile("resources/fonts/Dosis.ttf"))
    {
        std::cout<<"ERROR: GAME::INITFONT could not load font"<<'\n';
    }
   
}
void Game::initText()
{
    //Gui text init
    this->gui_text.setFont(this->font);
    this->gui_text.setFillColor(sf::Color::White);
    this->gui_text.setCharacterSize(30);

    //End game text
    this->end_game_text.setFont(this->font);
    this->end_game_text.setFillColor(sf::Color::Red);
    this->end_game_text.setCharacterSize(60);
    this->end_game_text.setPosition(sf::Vector2f(20,300));
    this->end_game_text.setString("Game Over!"); 

}


// Constructos and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initFont();
    this->initText();
}
Game::~Game()
{
    delete this->window;
}

const bool& Game::getEndGame() const
{
    return this->end_game; 
}


//Functions
const bool Game::running() const
{
    return this->window->isOpen() /*&& this->end_game==false*/;
}
void Game::pollEvents()
{
    while(this->window->pollEvent(this->sfml_event))
    {
        if(this->sfml_event.type == sf::Event::Closed)
            this->window->close();
        if(this->sfml_event.type == sf::Event::KeyPressed)
            if(this->sfml_event.key.code == sf::Keyboard::Escape)
                this->window->close();
    }
}


void Game::spawnSwagBalls()
{
    //Timer
    if(this->spawn_timer<this->spawn_timer_max)
        this->spawn_timer+=1.f;
    else
    {
        if(this->swag_balls.size()<this->max_swag_balls)
        {
            this->swag_balls.push_back(SwagBall(*this->window,this->randBallType()));  

            this->spawn_timer+=1.f;

        }
    } 
}

const int Game::randBallType() const
{
    int type=SwagBallTypes::DEFAULT;
    int rand_value=rand()%100+1;
    if(rand_value > 60 && rand_value<=80)
        type=SwagBallTypes::DAMAGING;
    else if(rand_value>80 && rand_value<=100)
        type=SwagBallTypes::HEALING;


    return type;

}

void Game::updatePlayer()
{
    this->player.update(this->window);

    if(this->player.getHp()<=0)
        this->end_game=true;
}

void Game::updateCollision()
{
     //Check the collision
     for(size_t i=0;i<swag_balls.size();++i)
     {
        if(this->player.getShape().getGlobalBounds().intersects(this->swag_balls[i].getShape().getGlobalBounds()))
        {
            switch(this->swag_balls[i].getType())
            {
                case SwagBallTypes::DEFAULT:
                    //Add points
                    this->points++;
                    break;
                case SwagBallTypes::DAMAGING:
                    this->player.takeDamage(1);
                    break;
                case SwagBallTypes::HEALING:
                    this->player.gainHealth(1);
                    break;

            }

            //Removing the balls
            this->swag_balls.erase(this->swag_balls.begin()+i);
            
        }
     }
}

void Game::updateGui()
{
    std::stringstream ss; 

    ss << "- Points: "<<this->points<<"\n"
        <<"-Health:"<<this->player.getHp()<<" / "<<this->player.getHpMax()<<"\n";

    this->gui_text.setString(ss.str());

}

void Game::update()
{
    pollEvents();


    if(this->end_game==false)
    {
        this->spawnSwagBalls();

        this->updatePlayer();
        this->updateCollision();
        this->updateGui();
    }
}
void Game::renderGui(sf::RenderTarget* target)
{
    target->draw(this->gui_text);
     
}
void Game::render()
{
    //Clearing the old frame
    this->window->clear();

    //Render stuf
    this->player.render(this->window); 
    
    for(auto i: this->swag_balls)
    {
        i.render(*this->window);
    }

    //Render Gui
    this->renderGui(this->window);

    //Render end text
    if(this->end_game==true)
    {
        this->window->draw(this->end_game_text);
    }
    this->window->display();

}
