//
// Created by petru on 8/16/16.
//

#include "Score.h"

Score::Score(sf::Vector2f sizes, sf::Font fontRef,sf::RenderWindow& winRef) : font{fontRef},size{sizes},win{winRef}{

    scoreText.setFont(font);
    playerBlue.setFont(font);
    playerRed.setFont(font);
    playerTie.setFont(font);

    scoreText.setString("Wins:");
    playerBlue.setString("Wins:");
    playerRed.setString("Wins:");
    playerTie.setString("Wins:");

    scoreText.setColor(sf::Color::Black);
    playerBlue.setColor(sf::Color::Blue);
    playerRed.setColor(sf::Color::Red);
    playerTie.setColor(sf::Color::Cyan);

    scoreText.setCharacterSize(50);
    playerBlue.setCharacterSize(50);
    playerRed.setCharacterSize(50);
    playerTie.setCharacterSize(50);

    scoreText.setPosition(60,size.y/4);
    playerBlue.setPosition(size.x/5+scoreText.getLocalBounds().width,size.y/4);
    playerTie.setPosition(2*size.x/5+scoreText.getLocalBounds().width,size.y/4);
    playerRed.setPosition(3*size.x/5+scoreText.getLocalBounds().width,size.y/4);

}

void Score::Draw(){
    win.draw(scoreText);
    win.draw(playerBlue);
    win.draw(playerTie);
    win.draw(playerRed);
}

void Score::SetScore(int red, int blue, int tie) {
    std::string txt=std::to_string(red);
    playerRed.setString(txt);
    txt=std::to_string(blue);
    playerBlue.setString(txt);
    txt=std::to_string(tie);
    playerTie.setString(txt);
}
