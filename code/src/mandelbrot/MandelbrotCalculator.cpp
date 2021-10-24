//
// Created by christopher on 2021-10-23.
//

#include <vector>
#include "../../header/mandelbrot/MandelbrotCalculator.h"
#include "../../header/utils/ConfigUtils.h"

std::vector<MandelbrotResult> MandelbrotCalculator::getMandelbrot(int width, int height,
                                                                  double realStart, double realEnd,
                                                                  double imaginaryStart, double imaginaryEnd) {
    std::vector<MandelbrotResult> mandelbrotResults;
    MandelbrotResult mandelbrotResult = MandelbrotResult();
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            double real = MathUtils::scaleValue(x, width, realStart, realEnd);
            double imaginary = MathUtils::scaleValue(y, height, imaginaryStart, imaginaryEnd);
            std::complex<double> constant(real, imaginary);

            mandelbrotResult.setXCoord(x);
            mandelbrotResult.setYCoord(y);
            mandelbrotResult.setTotalIterations(MandelbrotCalculator::mandelbrotIterations(constant));
            mandelbrotResults.push_back(mandelbrotResult);
        }
    }
    return mandelbrotResults;
}

int MandelbrotCalculator::mandelbrotIterations(std::complex<double> constant) {
    std::complex<double> z = 0;
    int totalIterations = 0;
    while (abs(z) <= 2 and totalIterations < ConfigUtils::getMaxIterations()) {
        z = z * z + constant;
        totalIterations++;
    }

    return totalIterations;
}



