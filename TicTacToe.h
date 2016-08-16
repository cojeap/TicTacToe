//
// Created by petru on 8/16/16.
//

#ifndef TICTACTOE_THREADER_H
#define TICTACTOE_THREADER_H



#include "GameObj.h"

#include "Score.h"


class TicTacToe {
public:
    TicTacToe();
    ~TicTacToe();
    void Run();
    void Replay();
private:
    void UpdateScore();
    int scorePlayerRed;
    int scorePlayerBlue;
    int scoreTie;
    sf::Vector2f winSize;
    sf::RenderWindow* window;
    GameObj* game;
    Score* scoreBoard;
};


#endif //TICTACTOE_THREADER_H
