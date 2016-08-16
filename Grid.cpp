//
// Created by petru on 7/26/16.
//

#include "Grid.h"


Grid::Grid(sf::Vector2f sizes, sf::RenderWindow& windowRef) : size{sizes}, winRef{windowRef} {

    pointSize = 9; // force  9 for the TicTacToe grid.

    sf::Vector2f reducedSizes(size.x / 3, size.y / 3);

    boxes = new sf::RectangleShape[pointSize];

    for (int i = 0; i < pointSize; i++) {
        boxes[i].setSize(reducedSizes);
        boxes[i].setFillColor(sf::Color::Transparent);
        boxes[i].setOutlineColor(sf::Color::Blue);
        boxes[i].setOutlineThickness(4);
        SetPositions(boxes[i], i);
    }
}

Grid::~Grid() {

    delete[] boxes;

}

void Grid::draw() {
    for (int i = 0; i < pointSize; i++) {
        winRef.draw(boxes[i]);
    }
}

void Grid::SetPositions(sf::RectangleShape &box, int i) {

    float fx = size.x;
    float fy = size.y;

    switch (i) {
        case 0:
            box.setPosition(0, 0);
            break;
        case 1:
            box.setPosition(fx / 3, 0);
            break;
        case 2:
            box.setPosition(2 * fx / 3, 0);
            break;
        case 3:
            box.setPosition(0, fy / 3);
            break;
        case 4:
            box.setPosition(fx / 3, fy / 3);
            break;
        case 5:
            box.setPosition(2 * fx / 3, fy / 3);
            break;
        case 6:
            box.setPosition(0, 2 * fy / 3);
            break;
        case 7:
            box.setPosition(fx / 3, 2 * fy / 3);
            break;
        case 8:
            box.setPosition(2 * fx / 3, 2 * fy / 3);
            break;
        default:

            break;
    }
}