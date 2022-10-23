//
// Created by christopher on 2021-10-23.
//

#include "../../header/gui/WindowHandler.h"
#include "../../header/utils/ConfigUtils.h"
#include "../../header/mandelbrot/MandelbrotCalculator.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <execution>

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


void WindowHandler::drawMandelbrotPixels(double realStart, double realEnd, double imaginaryStart, double imaginaryEnd) {
    std::for_each(
            std::execution::par,
            this->pixels.begin(),
            this->pixels.end(),
            [this, realStart, realEnd, imaginaryStart, imaginaryEnd](auto &&pixel) {
                double nrOfIterations = MandelbrotCalculator::mandelbrotIterations(
                        pixel.getPosition().x,
                        this->getWindowWidth(),
                        realStart,
                        realEnd,
                        pixel.getPosition().y,
                        this->getWindowHeight(),
                        imaginaryStart,
                        imaginaryEnd
                );
                sf::Color color = ConfigUtils::getColorInterpolated(nrOfIterations / ConfigUtils::getMaxIterations());
                pixel.setFillColor(color);
                this->window.draw(pixel);
            });

    //  this->drawPixels();
}

void WindowHandler::drawPixels() {
    for (int i = 0; i < this->pixels.size(); i++) {
        this->window.draw(pixels[i]);
    }
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

