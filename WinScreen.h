//
// Created by petru on 8/4/16.
//

#ifndef TICTACTOE_WINSCREEN_H
#define TICTACTOE_WINSCREEN_H

#include <SFML/Graphics.hpp>
#include "WinCondition.h"

class WinScreen{
public:
    WinScreen(WinType wType, sf::Vector2f wSize, sf::RenderWindow& wRef,sf::Font& rFont);
    ~WinScreen()= default;
    void Draw();
    void SetWinType(WinType wType);
    void HandleEvent(sf::Event& evt);
    WinType GetWinType();
    bool pause;
private:
    sf::Vector2f winSize;
    WinType winType;
    sf::RenderWindow& win;
    sf::Font& refFont;
    sf::Text winText;
    sf::RectangleShape background;
};

#endif //TICTACTOE_WINSCREEN_H
