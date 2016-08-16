//
// Created by petru on 8/16/16.
//

#ifndef TICTACTOE_THREADER_H
#define TICTACTOE_THREADER_H



#include "GameObj.h"

class TicTacToe {
public:
    TicTacToe();
    ~TicTacToe();
    void Run();
    void Replay();
private:

    sf::Vector2f winSize;
    sf::RenderWindow* window;
    GameObj* game;
};


#endif //TICTACTOE_THREADER_H
