#include <iostream>

#include "GameObj.h"

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

        GameObj game{sizes, window};


        //game loop

        while (window.isOpen()) {

            sf::Event event;

            while (window.pollEvent(event)) {
                game.HandleEvent(event);
            }

            game.CheckWinType();

            game.Draw();
        }
    }
    catch (Exceptions &e) {
        e.ShowExcept();
    }
    catch (...) {
        std::cerr << "Unknown Problem!\t0" << std::endl;
    }

    return 0;
}