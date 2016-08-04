//
// Created by petru on 7/26/16.
//

#ifndef TICTACTOE_GRID_H
#define TICTACTOE_GRID_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



class Grid {
public:
    Grid(int x,int y, sf::RenderWindow& windowRef);
    ~Grid();
    void draw();
    void SetPositions(sf::RectangleShape& box, int i);
private:
    int sizeX;
    int sizeY;
    int pointSize;
    sf::RenderWindow& winRef;
    sf::RectangleShape* boxes;
};


#endif //TICTACTOE_GRID_H
