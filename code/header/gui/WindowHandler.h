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

public:
    sf::RenderWindow window;

    void drawBackground();

    sf::Texture backgroundTexture;

    void drawMandelbrotPixel(std::vector<MandelbrotResult> mandelbrotResults);

    void addPixel(sf::Vector2f position, unsigned char red, unsigned char green, unsigned char blue);

    void displayWindow();
};

#endif //MANDELBROT_WINDOWHANDLER_H
