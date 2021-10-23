//
// Created by christopher on 2021-10-23.
//

#ifndef MANDELBROT_MANDELBROTCALCULATOR_H
#define MANDELBROT_MANDELBROTCALCULATOR_H


#include <complex>
#include "MandelbrotResult.h"

class MandelbrotCalculator {
public:
    static int mandelbrotIterations(std::complex<double> constant);

    static std::vector<MandelbrotResult>
    getMandelbrot(int width, int height, double realStart, double realEnd, double imaginaryStart, double imaginaryEnd);
};


#endif //MANDELBROT_MANDELBROTCALCULATOR_H
