//
// Created by petru on 8/16/16.
//

#ifndef TICTACTOE_SCORE_H
#define TICTACTOE_SCORE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Score{
    sf::Vector2f size;
    sf::Text scoreText;
    sf::Text playerBlue;
    sf::Text playerRed;
    sf::Text playerTie;
    sf::Font font;
    sf::RenderWindow& win;
public:
    Score(sf::Vector2f sizes, sf::Font fontRef,sf::RenderWindow& winRef);
    ~Score()= default;
    void Draw();
    void SetScore(int red,int blue,int tie);
};

#endif //TICTACTOE_SCORE_H