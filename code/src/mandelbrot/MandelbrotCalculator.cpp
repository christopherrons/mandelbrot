//
// Created by christopher on 2021-10-23.
//

#include <vector>
#include "../../header/mandelbrot/MandelbrotCalculator.h"
#include "../../header/utils/ConfigUtils.h"

std::vector<MandelbrotResult> MandelbrotCalculator::getMandelbrot(int xMax, int yMax) {
    std::vector<MandelbrotResult> mandelbrotResults;
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            float real = ConfigUtils::getRealStart() +
                         ((float) x / xMax) * (ConfigUtils::getRealEnd() - ConfigUtils::getRealStart());
            float imaginary = ConfigUtils::getImaginaryStart() +
                              ((float) y / yMax) * (ConfigUtils::getImaginaryEnd() - ConfigUtils::getImaginaryStart());
            std::complex<double> constant(real, imaginary);
            MandelbrotResult mandelbrotResult = MandelbrotResult();
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



