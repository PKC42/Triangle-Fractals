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
#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Triangle : public sf::Drawable {
 public:
    // default constructor
    Triangle();

    // initialize with starting point,
    // length of side, depth of recursion and color
    Triangle(double _x, double _y, double _L,
        sf::Color color);

 private:
    // convex shape that will be the triangle
    sf::ConvexShape triangle;

    // coordinates of point
    double x, y;

    // depth of recursion
    double N;

    // lenth of side of equilateral triangle
    double L;

    // draw the triangle
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
