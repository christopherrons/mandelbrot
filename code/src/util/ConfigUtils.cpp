//
// Created by christopher on 2021-10-23.
//

#include <iostream>
#include "../../header/utils/ConfigUtils.h"

int ConfigUtils::getGridWidth() {
    return 1920;
}

int ConfigUtils::getGridHeight() {
    return 1080;
}

int ConfigUtils::getMaxIterations() {
    return 200;
}

double ConfigUtils::getRealStart() {
    return -2.0;
}

double ConfigUtils::getRealEnd() {
    return 1.0f;
}

double ConfigUtils::getImaginaryStart() {
    return -1.0;
}

double ConfigUtils::getImaginaryEnd() {
    return 1.0;
}

double ConfigUtils::getZoomGridValue() {
    return 40.0;
}

sf::Color ConfigUtils::getColorInterpolated(double iterationRatio) {
    sf::Uint8 alpha = 255;
    if (iterationRatio < 0.16) {
        sf::Uint8 red = MathUtils::linearInterpolation(iterationRatio, 0.0, 0.16, 0, 66);
        sf::Uint8 green = MathUtils::linearInterpolation(iterationRatio, 0.0, 0.16, 7, 107);
        sf::Uint8 blue = MathUtils::linearInterpolation(iterationRatio, 0.0, 0.16, 100, 203);
        return {red, green, blue, alpha};
    } else if (iterationRatio >= 0.16 && iterationRatio < 0.42) {
        sf::Uint8 red = MathUtils::linearInterpolation(iterationRatio, 0.16, 0.42, 66, 237);
        sf::Uint8 green = MathUtils::linearInterpolation(iterationRatio, 0.16, 0.42, 107, 255);
        sf::Uint8 blue = MathUtils::linearInterpolation(iterationRatio, 0.16, 0.42, 203, 255);
        return {red, green, blue, alpha};
    } else if (iterationRatio >= 0.42 && iterationRatio < 0.6425) {
        sf::Uint8 red = MathUtils::linearInterpolation(iterationRatio, 0.42, 0.6425, 237, 255);
        sf::Uint8 green = MathUtils::linearInterpolation(iterationRatio, 0.42, 0.6425, 255, 170);
        sf::Uint8 blue = MathUtils::linearInterpolation(iterationRatio, 0.42, 0.6425, 255, 0);
        return {red, green, blue, alpha};
    } else if (iterationRatio >= 0.6425 && iterationRatio < 0.8575) {
        sf::Uint8 red = MathUtils::linearInterpolation(iterationRatio, 0.6425, 0.8575, 255, 0);
        sf::Uint8 green = MathUtils::linearInterpolation(iterationRatio, 0.6425, 0.8575, 170, 2);
        sf::Uint8 blue = MathUtils::linearInterpolation(iterationRatio, 0.6425, 0.8575, 0, 0);
        return {red, green, blue, alpha};
    }

    return {0, 0, 0, alpha};
}