//
// Created by petru on 7/27/16.
//

#include "XandZero.h"

XandZero::XandZero(sf::Vector2f sizes, sf::RenderWindow &windowRef, sf::Font &fnt) : size{sizes}, font{fnt},
                                                                               winRef{windowRef} {

    originPoz.x = 4;
    originPoz.y = 4;

    arrSize = 9; // force  9 for the TicTacToe grid.

    highlightBox.setFillColor(sf::Color::Transparent);
    highlightBox.setPosition(originPoz);
    highlightBox.setOutlineColor(sf::Color::Green);
    highlightBox.setOutlineThickness(4);
    highlightBox.setSize(sf::Vector2f(size.x / 3 - 9, size.y / 3 - 9));

    for (unsigned int it = 0; it < arrSize; ++it) {
        xTxt.push_back(sf::Text("E", font));
    }
    for (unsigned int it = 0; it < arrSize; ++it) {
        xTxt[it].setColor(sf::Color::Transparent);
        xTxt[it].setCharacterSize(235);
    }

}

void XandZero::DrawHighlight() {
    winRef.draw(highlightBox);
}

void XandZero::HandleEvent(sf::Event &evt) {

    float moveSizeX{ size.x / 3};
    float moveSizeY{ size.y / 3};
    float pozX = highlightBox.getPosition().x;
    float pozY = highlightBox.getPosition().y;

    sf::Vector2f smVct = highlightBox.getPosition();

    int position = UpdatePosition(smVct);
    xTxt[position].setPosition(smVct);
    xTxt[position].move(17, -55);    //place it properly in the box

    if (evt.type == sf::Event::KeyReleased) {
        switch (evt.key.code) {
            case sf::Keyboard::Right :
                if ((pozX + moveSizeX) < (size.x - 100)) {
                    highlightBox.move(moveSizeX, 0);
                }
                break;
            case sf::Keyboard::Down :
                if ((pozY + moveSizeY) < (size.y - 100)) {
                    highlightBox.move(0, moveSizeY);
                }
                break;
            case sf::Keyboard::Left :
                if ((pozX - moveSizeX) > 0) {
                    highlightBox.move(-moveSizeX, 0);
                }
                break;
            case sf::Keyboard::Up :
                if ((pozY - moveSizeY) > 0) {
                    highlightBox.move(0, -moveSizeY);
                }
                break;
            case sf::Keyboard::X :
                if (xTxt[position].getString() != "0") {
                    xTxt[position].setString("X"); //playerBlue
                    xTxt[position].setColor(sf::Color::Blue);
                }
                break;
            case sf::Keyboard::Numpad0 :
            case sf::Keyboard::Num0 :
            case sf::Keyboard::O :
                if (xTxt[position].getString() != "X") {
                    xTxt[position].setString("0"); //playerRed
                    xTxt[position].setColor(sf::Color::Red);
                }
                break;
            case sf::Keyboard::Escape :
            case sf::Keyboard::BackSpace :
            case sf::Keyboard::R :
                break;
            default:
                highlightBox.setPosition(originPoz);
                break;
        }
    }
}

void XandZero::Draw() {
    for (auto &text : xTxt) {
        winRef.draw(text);
    }

}

int XandZero::UpdatePosition(sf::Vector2f smVct) {
    if (smVct.x == originPoz.x && smVct.y == originPoz.y)
        return 0;
    else if (smVct.x == (originPoz.x + ( size.x / 3)) && smVct.y == originPoz.y)
        return 1;
    else if (smVct.x == (originPoz.x + ( 2 * size.x / 3)) && smVct.y == originPoz.y)
        return 2;
    else if (smVct.x == originPoz.x && smVct.y == (originPoz.y +  size.y / 3))
        return 3;
    else if (smVct.x == (originPoz.x + ( size.x / 3)) && smVct.y == (originPoz.y +  size.y / 3))
        return 4;
    else if (smVct.x == (originPoz.x + ( 2 * size.x / 3)) && smVct.y == (originPoz.y +  size.y / 3))
        return 5;
    else if (smVct.x == originPoz.x && smVct.y == (originPoz.y +  2 * size.y / 3))
        return 6;
    else if (smVct.x == (originPoz.x + ( size.x / 3)) && smVct.y == (originPoz.y +  2 * size.y / 3))
        return 7;
    else if (smVct.x == (originPoz.x + (2 * size.x / 3)) && smVct.y == (originPoz.y +  2 * size.y / 3))
        return 8;
    else throw Exceptions("That was unexpected!!! (XandZero.cpp)", 120);
}

WinCondition XandZero::CheckWinLogic() { //incomplete

    //init
    bool firstTimeInit{false};
    std::vector<std::string> box;

    if (!firstTimeInit) {
        for (const auto &txt : xTxt) {
            box.push_back(txt.getString());
        }
        if (box.size() == xTxt.size())
            firstTimeInit = true;
        else throw Exceptions("Win condition vector is not the same size as vector of <sf::Text>", 126);
    } else {
        for (unsigned int it = 0; it < box.size(); it++) {
            box[it] = xTxt[it].getString();
        }
    }

    //check condition

    //playerBlue X
    if (box[0] == "X" && box[1] == "X" && box[2] == "X") {
        condition.SetWinType(WinType::winPlayerBlue);
    }
    else if (box[0] == "0" && box[1] == "0" && box[2] == "0") {
        condition.SetWinType(WinType::winPlayerRed);
    }

    return condition;

}
