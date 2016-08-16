//
// Created by petru on 8/16/16.
//



#include "TicTacToe.h"

TicTacToe::TicTacToe() {

    unsigned int sizeX=800;
    unsigned int sizeY=600;
    winSize.x=sizeX;
    winSize.y=sizeY;

    window = new sf::RenderWindow{{sizeX,sizeY},"TicTacToe"};
    game = new GameObj{{winSize.x,winSize.y},*window};

}

TicTacToe::~TicTacToe(){
    delete game;
    delete window;
}

void TicTacToe::Run() {

    while (window->isOpen()) {

        sf::Event event;

        while (window->pollEvent(event)) {
            game->HandleEvent(event);
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
                if(this->game->isReplayAllowed())
                    Replay();
        }

        game->CheckWinType();

        game->Draw();
    }
}

void TicTacToe::Replay() { // not perfect, can or cannot keep score???? -> next thing to do!!
    delete game;
    game=NULL;
    game=new GameObj{{winSize.x,winSize.y},*window};

}
