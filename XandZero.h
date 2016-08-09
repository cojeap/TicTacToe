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
    XandZero(int x,int y, sf::RenderWindow& windowRef,sf::Font& fnt);
    ~XandZero()=default;
    void Reset();
    void HandleEvent(sf::Event& evt);
    void DrawHighlight();
    void Draw();
    WinCondition CheckWinLogic();
private:
    WinCondition condition;
    int UpdatePosition(sf::Vector2f smVct);
    unsigned int arrSize;
    sf::RectangleShape highlightBox;
    int sizeX;
    int sizeY;
    sf::RenderWindow& winRef;
    sf::Font font;
    std::vector<sf::Text> xTxt;

};

#endif //TICTACTOE_XANDZERO_H
