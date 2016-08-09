//
// Created by petru on 7/27/16.
//

#include "XandZero.h"

XandZero::XandZero(int x,int y,sf::RenderWindow& windowRef,sf::Font& fnt) : sizeX{x},sizeY{y},font{fnt},winRef{windowRef} {


    arrSize=9;

    highlightBox.setFillColor(sf::Color::Transparent);
    highlightBox.setPosition(4,4);
    highlightBox.setOutlineColor(sf::Color::Green);
    highlightBox.setOutlineThickness(4);
    highlightBox.setSize(sf::Vector2f(sizeX/3-9,sizeY/3-9));

    for(unsigned int it=0;it<arrSize;++it){
        xTxt.push_back(sf::Text("E",font));
    }
    for(unsigned int it=0;it<arrSize;++it){
        xTxt[it].setColor(sf::Color::Transparent);
        xTxt[it].setCharacterSize(235);
    }

}

void XandZero::DrawHighlight(){
    winRef.draw(highlightBox);
}

void XandZero::HandleEvent(sf::Event& evt){
    float moveSizeX{(float)sizeX/3};
    float moveSizeY{(float)sizeY/3};
    float pozX = highlightBox.getPosition().x;
    float pozY = highlightBox.getPosition().y;

    sf::Vector2f smVct=highlightBox.getPosition();
    int position=UpdatePosition(smVct);
    xTxt[position].setPosition(smVct);
    xTxt[position].move(17,-55);    //place it properly in the box

        if (evt.type == sf::Event::KeyReleased) {
            switch (evt.key.code) {
                case sf::Keyboard::Right :
                    if ((pozX + moveSizeX) < (sizeX - 100)) {
                        highlightBox.move(moveSizeX, 0);
                    }
                    break;
                case sf::Keyboard::Down :
                    if ((pozY + moveSizeY) < (sizeY - 100)) {
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
                    xTxt[position].setString("X");
                    xTxt[position].setColor(sf::Color::Blue);
                    break;
                case sf::Keyboard::Numpad0 :
                case sf::Keyboard::Num0 :
                case sf::Keyboard::O :
                    xTxt[position].setString("0");
                    xTxt[position].setColor(sf::Color::Red);
                    break;
                case sf::Keyboard::Escape :
                case sf::Keyboard::P :
                    break;
                default:
                    highlightBox.setPosition(4, 4);
                    break;
            }
        }
}

void XandZero::Draw(){
for(auto &text : xTxt){
        winRef.draw(text);
    }

}

int XandZero::UpdatePosition(sf::Vector2f smVct){
    if     (smVct.x==4.f                      && smVct.y==4.f)
        return 0;
    else if(smVct.x==(4.f+((float)sizeX/3))   && smVct.y==4.f)
        return 1;
    else if(smVct.x==(4.f+((float)2*sizeX/3)) && smVct.y==4.f)
        return 2;
    else if(smVct.x==4.f                      && smVct.y==(4.f +(float)sizeY/3) )
        return 3;
    else if(smVct.x==(4.f+((float)sizeX/3))   && smVct.y==(4.f +(float)sizeY/3) )
        return 4;
    else if(smVct.x==(4.f+((float)2*sizeX/3)) && smVct.y==(4.f +(float)sizeY/3) )
        return 5;
    else if(smVct.x==4.f                      && smVct.y==(4.f +(float)2*sizeY/3) )
        return 6;
    else if(smVct.x==(4.f+((float)sizeX/3))   && smVct.y==(4.f +(float)2*sizeY/3) )
        return 7;
    else if(smVct.x==(4.f+((float)2*sizeX/3)) && smVct.y==(4.f +(float)2*sizeY/3) )
        return 8;
    else throw Exceptions("That was unexpected!!! (XandZero.cpp)",109);
}

WinCondition XandZero::CheckWinLogic(){ //incomplete

    //init
    bool firstTimeInit{false};
    std::vector<std::string> whatIsDrawn;

    if(!firstTimeInit) {
        for (const auto &txt : xTxt) {
            whatIsDrawn.push_back(txt.getString());
        }
        if(whatIsDrawn.size()==xTxt.size())
            firstTimeInit=true;
        else throw Exceptions("Win condition vector is not the same size as vector of <sf::Text>",125);
    } else {
        for(unsigned int it=0;it<whatIsDrawn.size();it++){
            whatIsDrawn[it]=xTxt[it].getString();
        }
    }

    //check condition










}