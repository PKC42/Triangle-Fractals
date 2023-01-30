// Copyright [2022] <Pratush Kc>
/************************************************************
 *Name: <Pratush Kc>
 *Course name: <COMP.2040>
 *Assignment: <PS3: Recursive Graphics (Triangle Fractal)>
 *Instructor's name: <Dr. James Daly>
 *Date: <3/1/2022>
 *Sources Of Help: <Discussions on Dr. Daly's discord server from other students and Dr. Daly>
 *Note: Some sample code was closely borrowed from the sfml tutorial website
 *Here are some of the references used: 
 *https://www.sfml-dev.org/tutorials/2.0/graphics-shape.php
 *https://www.sfml-dev.org/documentation/2.0/classsf_1_1ConvexShape.php
 *Font file source:
 *https://www.wfonts.com/
************************************************************/
#include <cmath>
#include "Triangle.h"


Triangle::Triangle() {
}

Triangle::Triangle(double _x, double _y, double _L, sf::Color color) {
    x = _x;
    y = _y;
    L = _L;

    // set the color for the outline
    triangle.setOutlineColor(color);

    // set line thickness
    triangle.setOutlineThickness(1);

    // set number of shapes (this is a triangle)
    triangle.setPointCount(3);

    // create shape
    triangle.setPoint(0, sf::Vector2f(x - (L / 2), y - (sqrt(3) / 2) * L));
    triangle.setPoint(1, sf::Vector2f(x + (L / 2), y - (sqrt(3) / 2) * L));
    triangle.setPoint(2, sf::Vector2f(x, y));
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(triangle, states);
}
