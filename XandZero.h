//
// Created by petru on 7/27/16.
//

#ifndef TICTACTOE_XANDZERO_H
#define TICTACTOE_XANDZERO_H

#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "WinCondition.h"


class XandZero {
public:
    XandZero(sf::Vector2f sizes, sf::RenderWindow& windowRef,sf::Font& fnt);
    ~XandZero()=default;
    void HandleEvent(sf::Event& evt);
    void DrawHighlight();
    void Draw();
    WinCondition CheckWinLogic();
private:
    sf::RenderWindow& winRef;
    sf::Vector2f size;
    unsigned int arrSize;
    sf::RectangleShape highlightBox;
    WinCondition condition;
    sf::Font font;
    std::vector<sf::Text> xTxt;
    sf::Vector2f originPoz;
    int UpdatePosition(sf::Vector2f smVct);
};

#endif //TICTACTOE_XANDZERO_H
