//
// Created by petru on 8/16/16.
//

#ifndef TICTACTOE_GAMEOBJ_H
#define TICTACTOE_GAMEOBJ_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "XandZero.h"
#include "WinScreen.h"
#include "WinCondition.h"

class GameObj {
private:
    Grid *gameGrid;
    XandZero *textBox;
    WinScreen *winPauseScreen;
    sf::Font textFont;

    sf::Vector2f size;

    sf::RenderWindow& wRef;

    sf::RectangleShape background;

    WinCondition gameState;


public:
    GameObj(sf::Vector2f sizes, sf::RenderWindow& winRef);
    ~GameObj();
    WinType  getWinType() const;
    bool isPlayig();
    bool isReplayAllowed();
    void HandleEvent(sf::Event& e);
    void CheckWinType();
    void Draw();
    sf::Font& getFont();
};


#endif //TICTACTOE_GAMEOBJ_H
