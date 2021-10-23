//
// Created by christopher on 2021-10-23.
//

#include "../../header/gui/WindowHandler.h"
#include "../../header/utils/ConfigUtils.h"

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


WindowHandler::WindowHandler()
        : window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()), "Mandelbrot Set",
                 sf::Style::Default),
          backgroundTexture(sf::Texture()),
          backgroundSprite(sf::Sprite()) {
   // window.setFramerateLimit(30);
}

void WindowHandler::drawMandelbrotPixel(std::vector<MandelbrotResult> mandelbrotResults) {
    for (auto &mandelbrotResult : mandelbrotResults) {
        int color = ConfigUtils::getBlackRBG() - (mandelbrotResult.getTotalIterations() * ConfigUtils::getBlackRBG() / ConfigUtils::getMaxIterations());
        addPixel({(float) mandelbrotResult.getXCoord(), (float) mandelbrotResult.getYCoord()}, color, color, color);
    }
}

void WindowHandler::addPixel(sf::Vector2f position, sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue) {
    sf::RectangleShape pixel;
    pixel.setSize({1.f, 1.f});
    pixel.setFillColor({red, green, blue});
    pixel.setPosition(position);
    this->window.draw(pixel);
}

void WindowHandler::drawBackground() {
    this->window.draw(this->backgroundSprite);
}

void WindowHandler::displayWindow() {
    this->window.display();
}

