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
#include "header/utils/MathUtils.h"
#include "header/mandelbrot/MandelbrotCalculator.h"
#include <chrono>


void runMandelbrot(WindowHandler &windowHandler, double realStart, double realEnd, double imaginaryStart,
                   double imaginaryEnd);

int main() {
    WindowHandler windowHandler;
    windowHandler.drawBackground();

    double realStart = ConfigUtils::getRealStart();
    double realEnd = ConfigUtils::getRealEnd();
    double imaginaryStart = ConfigUtils::getImaginaryStart();
    double imaginaryEnd = ConfigUtils::getImaginaryEnd();

    runMandelbrot(windowHandler, realStart, realEnd, imaginaryStart, imaginaryEnd);

    sf::Vector2i CurrentMousePosition;
    while (true) {
        sf::Event event{};
        while (windowHandler.window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                windowHandler.window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                CurrentMousePosition = sf::Mouse::getPosition(windowHandler.window);

                double xStart = CurrentMousePosition.x - ConfigUtils::getZoomGridValue();
                xStart = xStart < 0 ? 0 : xStart;

                double xEnd = CurrentMousePosition.x + ConfigUtils::getZoomGridValue();
                xEnd = xEnd > windowHandler.getWindowWidth() ? windowHandler.getWindowWidth() : xEnd;

                double yStart = CurrentMousePosition.y - ConfigUtils::getZoomGridValue();
                yStart = yStart < 0 ? 0 : yStart;

                double yEnd = CurrentMousePosition.y + ConfigUtils::getZoomGridValue();
                yEnd = yEnd > windowHandler.getWindowHeight() ? windowHandler.getWindowHeight() : yEnd;

                realStart = MathUtils::scaleValue(xStart, 0, windowHandler.getWindowWidth(), realStart, realEnd);
                realEnd = MathUtils::scaleValue(xEnd, 0, windowHandler.getWindowWidth(), realStart, realEnd);
                imaginaryStart = MathUtils::scaleValue(yStart, 0, windowHandler.getWindowHeight(), imaginaryStart,
                                                       imaginaryEnd);
                imaginaryEnd = MathUtils::scaleValue(yEnd, 0, windowHandler.getWindowHeight(), imaginaryStart,
                                                     imaginaryEnd);

                std::cout << "" << std::endl;
                std::cout << "xStart: " << xStart << " RealStart: " << realStart << std::endl;
                std::cout << "xEnd: " << xEnd << " RealEnd: " << realEnd << std::endl;
                std::cout << "yStart: " << yStart << " ImaginaryStart: " << imaginaryStart << std::endl;
                std::cout << "yEnd: " << yEnd << " ImaginaryEnd: " << imaginaryEnd << std::endl;
                std::cout << "" << std::endl;

                runMandelbrot(windowHandler, realStart, realEnd, imaginaryStart, imaginaryEnd);
            }
        }
    }
    return 0;
}

void runMandelbrot(WindowHandler &windowHandler, double realStart, double realEnd, double imaginaryStart,
                   double imaginaryEnd) {

    sf::Clock clock;
    sf::Time timeSinceLastUpdate;

    std::cout << "STARTING: Drawing Mandelbrot" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    windowHandler.drawMandelbrotPixels(realStart,
                                       realEnd,
                                       imaginaryStart,
                                       imaginaryEnd);
    windowHandler.displayWindow();
    std::cout << "DONE: Drawing Mandelbrot" << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Draw Time: " << duration.count() << std::endl;
}