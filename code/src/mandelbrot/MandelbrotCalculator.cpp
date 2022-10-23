//
// Created by christopher on 2021-10-23.
//

#include "../../header/mandelbrot/MandelbrotCalculator.h"
#include "../../header/utils/ConfigUtils.h"


int MandelbrotCalculator::mandelbrotIterations(double x, double width, double realStart, double realEnd, double y,
                                               double height, double imaginaryStart, double imaginaryEnd) {
    double real = MathUtils::scaleValue(x, 0, width, realStart, realEnd);
    double imaginary = MathUtils::scaleValue(y,0,  height, imaginaryStart, imaginaryEnd);
    std::complex<double> constant(real, imaginary);

    std::complex<double> z = 0;
    int totalIterations = 0;
    while (z.real() * z.real() + z.imag() * z.imag() <= 4 and totalIterations < ConfigUtils::getMaxIterations()) {
        z = z * z + constant;
        totalIterations++;
    }

    return totalIterations;
}



