//
// Created by christopher on 2021-05-10.
//

#ifndef MANDELBROT_WINDOWHANDLER_H
#define MANDELBROT_WINDOWHANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../mandelbrot/MandelbrotResult.h"

class WindowHandler {
public:
    WindowHandler();

private:
    sf::Sprite backgroundSprite;
    std::vector<sf::RectangleShape> pixels;

public:
    sf::RenderWindow window;

    void drawBackground();

    void drawMandelbrotPixel(std::vector<MandelbrotResult> mandelbrotResults);

    void drawPixel(sf::RectangleShape pixel, sf::Vector2f position, sf::Color color);

    void displayWindow();

    double getWindowHeight();

    double getWindowWidth();

    void initPixels();
};

#endif //MANDELBROT_WINDOWHANDLER_H
