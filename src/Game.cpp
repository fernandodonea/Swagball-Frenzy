#include "game.h"

void Game::_InitVariables()
{
    this->end_game=false;

    this->spawn_timer_max=10.f;
    this->spawn_timer=this->spawn_timer_max;
    this->max_swag_balls=10;

    this->points=0;
}
void Game::_InitWindow()
{
    this->video_mode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->video_mode, "Swagball Frenzy", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::_InitFont()
{
    if(!this->font.loadFromFile("resources/fonts/Dosis.ttf"))
    {
        std::cout<<"ERROR: GAME::INITFONT could not load font"<<'\n';
    }
   
}
void Game::_InitText()
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
    this->_InitVariables();
    this->_InitWindow();
    this->_InitFont();
    this->_InitText();
}
Game::~Game()
{
    delete this->window;
}

const bool& Game::GetEndGame() const
{
    return this->end_game; 
}


//Functions
const bool Game::Running() const
{
    return this->window->isOpen() /*&& this->end_game==false*/;
}
void Game::PollEvents()
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


void Game::SpawnSwagBalls()
{
    //Timer
    if(this->spawn_timer<this->spawn_timer_max)
        this->spawn_timer+=1.f;
    else
    {
        if(this->swag_balls.size()<this->max_swag_balls)
        {
            this->swag_balls.push_back(SwagBall(*this->window,this->RandBallType()));  

            this->spawn_timer+=1.f;

        }
    } 
}

const int Game::RandBallType() const
{
    int type=SwagBallTypes::DEFAULT;
    int rand_value=rand()%100+1;
    if(rand_value > 60 && rand_value<=80)
        type=SwagBallTypes::DAMAGING;
    else if(rand_value>80 && rand_value<=100)
        type=SwagBallTypes::HEALING;

    return type;

}

void Game::UpdatePlayer()
{
    this->player.Update(this->window);

    if(this->player.GetHp()<=0)
        this->end_game=true;
}

void Game::UpdateCollision()
{
     //Check the collision
     for(size_t i=0;i<swag_balls.size();++i)
     {
        if(this->player.GetShape().getGlobalBounds().intersects(this->swag_balls[i].GetShape().getGlobalBounds()))
        {
            switch(this->swag_balls[i].GetType())
            {
                case SwagBallTypes::DEFAULT:
                    //Add points
                    this->points++;
                    break;
                case SwagBallTypes::DAMAGING:
                    this->player.TakeDamage(1);
                    break;
                case SwagBallTypes::HEALING:
                    this->player.GainHealth(1);
                    break;

            }

            //Removing the balls
            this->swag_balls.erase(this->swag_balls.begin()+i);
            
        }
     }
}

void Game::UpdateGui()
{
    std::stringstream ss; 

    ss << "- Points: "<<this->points<<"\n"
        <<"-Health:"<<this->player.GetHp()<<" / "<<this->player.GetHpMax()<<"\n";

    this->gui_text.setString(ss.str());

}

void Game::Update()
{
    PollEvents();


    if(this->end_game==false)
    {
        this->SpawnSwagBalls();

        this->UpdatePlayer();
        this->UpdateCollision();
        this->UpdateGui();
    }
}
void Game::RenderGui(sf::RenderTarget* target)
{
    target->draw(this->gui_text);
     
}
void Game::Render()
{
    //Clearing the old frame
    this->window->clear();

    //Render stuf
    this->player.Render(this->window); 
    
    for(auto i: this->swag_balls)
    {
        i.Render(*this->window);
    }

    //Render Gui
    this->RenderGui(this->window);

    //Render end text
    if(this->end_game==true)
    {
        this->window->draw(this->end_game_text);
    }
    this->window->display();

}
