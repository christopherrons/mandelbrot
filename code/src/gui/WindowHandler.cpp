//
// Created by christopher on 2021-10-23.
//

#include "../../header/gui/WindowHandler.h"
#include "../../header/utils/ConfigUtils.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


WindowHandler::WindowHandler()
        : window(sf::VideoMode(ConfigUtils::getGridWidth(), ConfigUtils::getGridHeight()), "Mandelbrot Set",
                 sf::Style::Default),
          backgroundSprite(sf::Sprite()) {

    this->initPixels();
}

void WindowHandler::initPixels() {
    for (int x = 0; x < this->getWindowWidth(); x++) {
        for (int y = 0; y < this->getWindowHeight(); y++) {
            sf::RectangleShape pixel;
            pixel.setSize({1.f, 1.f});
            pixel.setPosition({(float) x, (float) y});
            this->pixels.push_back(pixel);
        }
    }
}

void WindowHandler::drawMandelbrotPixel(std::vector<MandelbrotResult> mandelbrotResults) {
    this->window.clear();
    for (int i = 0; i < mandelbrotResults.size(); i++) {
        drawPixel(this->pixels[i],
                  {(float) mandelbrotResults[i].getXCoord(),
                   (float) mandelbrotResults[i].getYCoord()},
                  ConfigUtils::getColorInterpolated(
                          (double) mandelbrotResults[i].getTotalIterations() / ConfigUtils::getMaxIterations()));
    }
}

void WindowHandler::drawPixel(sf::RectangleShape pixel, sf::Vector2f position, sf::Color color) {
    pixel.setFillColor(color);
    pixel.setPosition(position);
    this->window.draw(pixel);
}

void WindowHandler::drawBackground() {
    this->window.draw(this->backgroundSprite);
}

void WindowHandler::displayWindow() {
    this->window.display();
}

double WindowHandler::getWindowHeight() {
    return this->window.getSize().y;
}

double WindowHandler::getWindowWidth() {
    return this->window.getSize().x;
}

