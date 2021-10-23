//
// Created by christopher on 2021-10-23.
//

#ifndef MANDELBROT_CONFIGUTILS_H
#define MANDELBROT_CONFIGUTILS_H

#include <SFML/Graphics/Color.hpp>
#include "MathUtils.h"

class ConfigUtils {
public:
    static int getGridWidth();

    static int getGridHeight();

    static int getMaxIterations();

    static double getRealStart();

    static double getRealEnd();

    static double getImaginaryStart();

    static double getImaginaryEnd();

    static double getZoomGridValue();

    static sf::Color getColorInterpolated(double iterationRatio);
};

#endif //MANDELBROT_CONFIGUTILS_H
