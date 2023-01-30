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

#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Triangle.h"


void fTree(double x, double y, double L, int N,
    sf::RenderWindow* window, sf::Color color) {
    // create triangle object
    Triangle triangle(x, y, L, color);
    window->draw(triangle);
    double height = ((sqrt(3)/2) * L);

    if (N > 0) {
        fTree(x - (L / 2), y - height, L / 2, N - 1, window, sf::Color::Red);
        fTree(x + (L / 2) + (L / 4), y - height + ((sqrt(3)/2) * L / 2),
        L / 2, N - 1, window, sf::Color::Green);
        fTree(x - (L / 4), y + ((sqrt(3)/2) * L / 2),
        L / 2, N -1, window, sf::Color::Blue);
    }
}

int main(int argc, char* argv[]) {
    // exit if there are not enough command line arguements
    if (argc != 3) {
        std::cerr << "Incorrect number of command";
        std::cerr <<  " line arguements!" << std::endl;
        return -1;
    }

    // contains length of side
    double L = std::stod(argv[1]);

    // contains depth of recursion
    int N = std::stoi(argv[2]);

    // window size variable to adjust for small or large L sizes
    double windowSize = L * 3.5;

    // starting point
    double x, y;

    // center initial triangle to middle of window
    x = windowSize / 2;
    y = (windowSize / 2) + (((sqrt(3)/2) * L) / 2);

    // error for if length is less than zero
    if (L <=0) {
        std::cerr << "Length of the side of the base of the";
        std::cerr << " equilateral triangle";
        std::cerr << " must be greater than 0!" << std::endl;
        return -1;
    }

    // error for if the depth of recursion is less than 0
    if (N < 0) {
        std::cerr << "Depth of recursion can not";
        std::cerr << " be a negative integer!" << std::endl;
    }

    // create window
    sf::RenderWindow window(sf::VideoMode(windowSize,
    windowSize), "Triangle Fractal");

    // store color
    sf::Color color = sf::Color::Black;

    sf::Font impact;
    if (!impact.loadFromFile("impact.ttf")) {
        std::cerr << "Unable to open font file!" << std::endl;
        return -1;
    }

    // create message

    std::string message = "Depth of Recursion: ";
    message += std::to_string(N);

    sf:: Text text;
    text.setFont(impact);
    text.setString(message);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Black);
    text.setPosition((L * 3.5) / 2, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(text);
        fTree(x, y, L, N, &window, color);
        window.display();
    }

    return 0;
}
