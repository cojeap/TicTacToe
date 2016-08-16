#include <iostream>

#include "TicTacToe.h"

using std::cout;
using std::endl;
using std::cin;


int main() {
    try {

        TicTacToe game;

        game.Run();

    }
    catch (Exceptions &e) {
        e.ShowExcept();
    }
    catch (...) {
        std::cerr << "Unknown Problem!\t0" << std::endl;
    }

    return 0;
}