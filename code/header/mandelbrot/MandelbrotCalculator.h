//
// Created by christopher on 2021-10-23.
//

#ifndef MANDELBROT_MANDELBROTCALCULATOR_H
#define MANDELBROT_MANDELBROTCALCULATOR_H


#include <complex>
#include <atomic>
#include "MandelbrotResult.h"

class MandelbrotCalculator {
public:
    static int mandelbrotIterations(double x, double width, double realStart, double realEnd, double y, double height,
                                    double imaginaryStart, double imaginaryEnd);
};


#endif //MANDELBROT_MANDELBROTCALCULATOR_H
