// ------------------------------------------------------------------------------
// Mondelbrot
//
// (C) 2021 Christopher Herron
// email: christopherherron09@gmail.com
//
// ------------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/gui/WindowHandler.h"
#include "header/utils/ConfigUtils.h"
#include "header/mandelbrot/MandelbrotCalculator.h"

int main() {
    WindowHandler windowHandler;
    windowHandler.drawBackground();

    std::cout << "STARTING: Calculating Mandelbrot" << std::endl;
    std::vector<MandelbrotResult> mandelbrotResults = MandelbrotCalculator::getMandelbrot(ConfigUtils::getGridWidth(),
                                                                                          ConfigUtils::getGridHeight());
    std::cout << "DONE: Calculating Mandelbrot" << std::endl;

    windowHandler.drawMandelbrotPixel(mandelbrotResults);
    windowHandler.displayWindow();

    while (true) {
        sf::Event event{};
        while (windowHandler.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                windowHandler.window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
        }
    }
    return 0;
}