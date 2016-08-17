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

    float moveSizeX{size.x / 3};
    float moveSizeY{size.y / 3};
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

    if(smVct.y==originPoz.y){
        if(smVct.x == originPoz.x)
            return 0;
        else if(smVct.x == (originPoz.x + (size.x / 3)))
            return 1;
        else if(smVct.x == (originPoz.x + (2 * size.x / 3)))
            return 2;
    } else if(smVct.y == (originPoz.y + size.y / 3)){
        if(smVct.x == originPoz.x)
            return 3;
        else if(smVct.x == (originPoz.x + (size.x / 3)))
            return 4;
        else if(smVct.x == (originPoz.x + (2 * size.x / 3)))
            return 5;
    } else if(smVct.y == (originPoz.y + 2 * size.y / 3)){
        if(smVct.x == originPoz.x)
            return 6;
        else if(smVct.x == (originPoz.x + (size.x / 3)))
            return 7;
        else if(smVct.x == (originPoz.x + (2 * size.x / 3)))
            return 8;
    } else throw Exceptions("Should be only 9 cases [0,8](XandZero.cpp)",125);
}

WinCondition XandZero::CheckWinLogic() { 

    //init
    std::vector<std::string> box;

    for (auto &txt : xTxt) {
        box.push_back(txt.getString());
    }

    int numberForTie{0};

    for (auto txt : box) {
        if (txt == "X" || txt == "0")
            numberForTie += 1;
    }

    if (numberForTie == 8) //if only 1 space is empty;
        condition.SetWinType(WinType::tie);

    //playerBlue X, playerRed 0

    if (box[2] == "X" && box[4] == "X" && box[6] == "X") {
        condition.SetWinType(WinType::winPlayerBlue);
    }
    else if (box[2] == "0" && box[4] == "0" && box[6] == "0") {
        condition.SetWinType(WinType::winPlayerRed);
    }
    else {

        for (unsigned int i = 0; i < arrSize-2; i += 3) {
            if (box[i] == "X" && box[i + 1] == "X" && box[i + 2] == "X") {
                condition.SetWinType(WinType::winPlayerBlue);
            }
            else if (box[i] == "0" && box[i + 1] == "0" && box[i + 2] == "0") {
                condition.SetWinType(WinType::winPlayerRed);
            }
        }

        for (unsigned int i = 0; i < 3; i++) {
            if (box[i] == "X" && box[i + 3] == "X" && box[i + 6] == "X") {
                condition.SetWinType(WinType::winPlayerBlue);
            } else if (box[i] == "0" && box[i + 3] == "0" && box[i + 6] == "0") {
                condition.SetWinType(WinType::winPlayerRed);
            }
        }

        if (box[0] == "X" && box[4] == "X" && box[8] == "X") {
            condition.SetWinType(WinType::winPlayerBlue);
        } else if (box[0] == "0" && box[4] == "0" && box[8] == "0") {
            condition.SetWinType(WinType::winPlayerRed);
        }

    }


    return condition;

}
