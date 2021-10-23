//
// Created by christopher on 2021-10-23.
//

#ifndef MANDELBROT_MANDELBROTRESULT_H
#define MANDELBROT_MANDELBROTRESULT_H


#include <vector>

class MandelbrotResult {
public:
    int getXCoord() const;

    void setXCoord(int xCoord);

    int getYCoord() const;

    void setYCoord(int yCoord);

    int getTotalIterations() const;

    void setTotalIterations(int totalIterations);

private:
    int xCoord;
    int yCoord;
    int totalIterations;
};


#endif //MANDELBROT_MANDELBROTRESULT_H
