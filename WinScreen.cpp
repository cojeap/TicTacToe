//
// Created by petru on 8/4/16.
//

#include "WinScreen.h"

WinScreen::WinScreen(WinType wType, sf::Vector2f wSize, sf::RenderWindow& wRef, sf::Font& rFont) : winType{wType}, winSize{wSize}, win{wRef},refFont{rFont}  {

    pause=false;
    playAgain=false;

    background.setSize(winSize);
    background.setFillColor(sf::Color::White);

    winText.setFont(refFont);
    winText.setPosition((60),(winSize.y/2));
    winText.setCharacterSize(50);


    switch(winType){
        case WinType::winPlayerBlue :
            winText.setColor(sf::Color::Blue);
            winText.setString("Blue Player Won!");
            break;
        case WinType::winPlayerRed :
            winText.setColor(sf::Color::Red);
            winText.setString("Red Player Won!");
            break;
        case WinType::tie :
            winText.setColor(sf::Color::Cyan);
            winText.setString("It's a tie!");
            break;
        default :
            winText.setColor(sf::Color::Black);
            winText.setString("Pause");
            break;
    }


}

void WinScreen::Draw() {
    win.draw(background);
    win.draw(winText);
}


void WinScreen::SetWinType(WinType wType) {
    winType = wType;
    switch(wType){
        case WinType::winPlayerBlue :
            winText.setColor(sf::Color::Blue);
            winText.setString("Blue Player Won!");
            break;
        case WinType::winPlayerRed :
            winText.setColor(sf::Color::Red);
            winText.setString("Red Player Won!");
            break;
        case WinType::tie :
            winText.setColor(sf::Color::Cyan);
            winText.setString("It's a tie!");
            break;
        default :
            winText.setColor(sf::Color::Black);
            winText.setString("Pause");
            break;
    }
}


void WinScreen::HandleEvent(sf::Event &evt) { //incomplete

    if(evt.type==sf::Event::KeyReleased){
        switch (evt.key.code){
            case sf::Keyboard::F4 :
                win.clear(sf::Color::Black);
                win.display();
                win.close();
                break;
            case sf::Keyboard::BackSpace :
                if(winType==WinType::playing)
                    pause=false;
                break;
            case sf::Keyboard::T :
                break;
            case sf::Keyboard::R :
                playAgain=true;
            default:
                break;

        }
    }

}

WinType WinScreen::GetWinType() {
    return winType;
}

void WinScreen::Reset() {
    pause=false;
    playAgain=false;
    winType=WinType::playing;
    winText.setColor(sf::Color::Black);
    winText.setString("Pause");
}