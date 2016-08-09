#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Exceptions.h"

#include "Grid.h"
#include "XandZero.h"

#include "WinScreen.h"

#include "Logger.h"

using std::cout;
using std::endl;
using std::cin;


int main() {
    try {
        //init

        Logger log{"logger"};

        log.w("Program started");


        const int sizeX = 800;
        const int sizeY = 600;

        sf::RenderWindow window{{sizeX, sizeY}, "TicTacToe"};
        window.setFramerateLimit(60);

        sf::Vector2f sizes(sizeX, sizeY);

        sf::Font someFont;

        if (!someFont.loadFromFile("Resources/good times rg.ttf"))
            throw Exceptions("Failed to load font from file. (main.cpp)", 31);

        //background
        sf::RectangleShape background;
        background.setPosition(0, 0);
        background.setSize(sizes);
        background.setFillColor(sf::Color::White);

        //grid
        Grid cutie{sizeX, sizeY, window};
        XandZero textBox{sizeX, sizeY, window, someFont};

        WinCondition condition;
        WinScreen winPauseScreen{WinType::playing,sizes,window,someFont};

        log.w("initialising done");


        //game loop

            while (window.isOpen()) {

                sf::Event event;


                if (!condition.condition) {

                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        if((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::F4))
                            window.close();
                        if(!winPauseScreen.pause) {
                            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
                                log.w("Escape pressed");
                                winPauseScreen.SetWinType(WinType::playing);
                                winPauseScreen.pause = true;
                                log.w("Pause true");
                                winPauseScreen.HandleEvent(event);
                            }
                        }
                        textBox.HandleEvent(event);
                       //condition = textBox.CheckWinLogic();
                    }

                    if(!winPauseScreen.pause) {
                        window.clear(sf::Color::Black);
                        //draw
                        window.draw(background);
                        cutie.draw();
                        textBox.DrawHighlight();
                        textBox.Draw();
                        //display
                        window.display();
                    } else {
                        
                        log.w("game pause");
                        window.clear(sf::Color::Black);
                        winPauseScreen.Draw();
                        window.display();
                    }

                } else if (condition.winTypeText == WinType::tie) {

                    if(winPauseScreen.GetWinType()!=WinType::tie)
                        winPauseScreen.SetWinType(WinType::tie);

                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F4))
                            window.close();
                    }

                    window.clear(sf::Color::White);

                    winPauseScreen.Draw();

                    window.display();

                } else if (condition.winTypeText == WinType::winPlayerRed) {

                    if(winPauseScreen.GetWinType()!=WinType::winPlayerRed)
                        winPauseScreen.SetWinType(WinType::winPlayerRed);

                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F4))
                            window.close();
                    }

                    window.clear(sf::Color::White);

                    winPauseScreen.Draw();

                    window.display();

                } else if (condition.winTypeText == WinType::winPlayerBlue) {

                    if(winPauseScreen.GetWinType()!=WinType::winPlayerBlue)
                        winPauseScreen.SetWinType(WinType::winPlayerBlue);

                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F4))
                            window.close();
                    }

                    window.clear(sf::Color::White);

                    winPauseScreen.Draw();

                    window.display();


                } else throw Exceptions("Unknown condition type! (main.cpp)",127);
            }
    }
    catch(Exceptions& e){
        e.ShowExcept();
    }
    catch(...){
        std::cerr<<"Unknown Problem!\t0"<<std::endl;
    }

    return 0;
}