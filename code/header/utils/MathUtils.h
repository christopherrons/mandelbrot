//
// Created by christopher on 2021-10-23.
//

#ifndef MANDELBROT_MATHUTILS_H
#define MANDELBROT_MATHUTILS_H

#include <SFML/Config.hpp>

class MathUtils {
public:
    static double scaleValue(double value, double minValue, double maxValue, double scaleMin, double scaleMax);

    static double linearInterpolation(double x, double x0, double x1, double y0, double y1);
};


#endif //MANDELBROT_MATHUTILS_H
