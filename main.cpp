#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "XandZero.h"

#include "Exceptions.h"

using std::cout;
using std::endl;
using std::cin;


int main() {
    try{

        //init

        const int sizeX=800;
        const int sizeY=600;

        sf::RenderWindow window{{sizeX,sizeY},"TicTacToe"};
        window.setFramerateLimit(60);

        sf::Vector2f sizes(sizeX,sizeY);

        sf::Font someFont;

        if(!someFont.loadFromFile("Resources/good times rg.ttf")) throw Exceptions("Failed to load font from file. (main.cpp)",31);

        //background
        sf::RectangleShape background;
        background.setPosition(0,0);
        background.setSize(sizes);
        background.setFillColor(sf::Color::White);

        //grid
        Grid cutie{sizeX,sizeY,window};
        XandZero textBox{sizeX,sizeY,window,someFont};

        //game loop
        while (window.isOpen()){
            sf::Event event;

            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape) )
                    window.close();
                textBox.HandleEvent(event);
            }


            window.clear();
            //draw
            window.draw(background);
            cutie.draw();
            textBox.DrawHighlight();
            textBox.Draw();
            //display
            window.display();
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