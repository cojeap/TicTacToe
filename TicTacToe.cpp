//
// Created by petru on 8/16/16.
//



#include "TicTacToe.h"

TicTacToe::TicTacToe() {

    unsigned int sizeX=800;
    unsigned int sizeY=600;
    winSize.x=sizeX;
    winSize.y=sizeY;

    scoreTie=0;
    scorePlayerRed=0;
    scorePlayerBlue=0;

    window = new sf::RenderWindow{{sizeX,sizeY},"TicTacToe"};
    game = new GameObj{{winSize.x,winSize.y},*window};
    scoreBoard=new Score{{winSize.x,winSize.y},this->game->getFont(),*window};
}

TicTacToe::~TicTacToe(){
    delete scoreBoard;
    delete game;
    delete window;
}

void TicTacToe::Run() {

    bool executedOnce{false};

    while (window->isOpen()) {

        sf::Event event;

        while (window->pollEvent(event)) {
            game->HandleEvent(event);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                if (this->game->isReplayAllowed()) {
                    Replay();
                    executedOnce=false;
                }
            }
        }


        game->CheckWinType();
        if (!executedOnce) {
            if (!game->isPlayig()) {
                UpdateScore();
                scoreBoard->SetScore(scorePlayerRed, scorePlayerBlue, scoreTie);
                executedOnce=true;
            }
        }

        window->clear();
        game->Draw();

        if(!game->isPlayig()){
            scoreBoard->Draw();
        }

        window->display();

    }
}

void TicTacToe::Replay() {
    delete game;
    game=NULL;
    game=new GameObj{{winSize.x,winSize.y},*window};

}

void TicTacToe::UpdateScore() {
    switch(this->game->getWinType()){
        case WinType::tie :
            scoreTie++;
            break;
        case WinType ::winPlayerRed :
            scorePlayerRed++;
            break;
        case WinType::winPlayerBlue :
            scorePlayerBlue++;
            break;
        default :
            break;
    }
}

