//
// Created by petru on 8/16/16.
//

#include "GameObj.h"

GameObj::GameObj(sf::Vector2f sizes, sf::RenderWindow& winRef,sf::Font& someFont) : size{sizes}, wRef{winRef},textFont{someFont} {

    gameGrid=NULL;
    textBox=NULL;
    winPauseScreen=NULL;

    background.setSize(size);
    background.setPosition(0, 0);
    background.setFillColor(sf::Color::White);

    gameGrid=new Grid {size,winRef};

    textBox=new XandZero{size,wRef,textFont};

    winPauseScreen=new WinScreen{WinType::playing,size,wRef,textFont};


}

GameObj::~GameObj() {
    delete gameGrid;
    delete textBox;
    delete winPauseScreen;
}

void GameObj::HandleEvent(sf::Event &e) { //incomplete
    if (e.type == sf::Event::Closed)
        wRef.close();
    if ((e.type == sf::Event::KeyReleased) && (e.key.code == sf::Keyboard::F4))
        wRef.close();
    if (!this->winPauseScreen->pause) {
        if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)) {
            this->winPauseScreen->SetWinType(WinType::playing);
            this->winPauseScreen->pause = true;
        }
    }
    this->winPauseScreen->HandleEvent(e);

    if(!winPauseScreen->pause)
        this->textBox->HandleEvent(e);
}

void GameObj::CheckWinType() {
    gameState=this->textBox->CheckWinLogic();
    this->winPauseScreen->SetWinType(gameState.winTypeText);
}

void GameObj::Draw() {

    if (!gameState.gameEnded) {
        if (!this->winPauseScreen->pause) {
            wRef.draw(background);
            this->gameGrid->draw();
            this->textBox->DrawHighlight();
            this->textBox->Draw();
        } else {
            this->winPauseScreen->Draw();
        }
    } else {
        switch(gameState.winTypeText){
            case WinType::tie :
                if (this->winPauseScreen->GetWinType() != WinType::tie)
                    this->winPauseScreen->SetWinType(WinType::tie);
                break;
            case WinType::winPlayerRed :
                if (this->winPauseScreen->GetWinType() != WinType::winPlayerRed)
                    this->winPauseScreen->SetWinType(WinType::winPlayerRed);
                break;
            case WinType::winPlayerBlue :
                if (this->winPauseScreen->GetWinType() != WinType::winPlayerBlue)
                    this->winPauseScreen->SetWinType(WinType::winPlayerBlue);
                break;
            default :
                break;
        }

        this->winPauseScreen->Draw();
    }

}

bool GameObj::isReplayAllowed() {
    return this->winPauseScreen->GetWinType() != WinType::playing;
}

bool GameObj::isPlayig() {
    return !this->gameState.gameEnded;
}

WinType GameObj::getWinType() const{
    return gameState.winTypeText;
}
