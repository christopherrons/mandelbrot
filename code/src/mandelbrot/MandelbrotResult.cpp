//
// Created by christopher on 2021-10-23.
//

#include "../../header/mandelbrot/MandelbrotResult.h"

int MandelbrotResult::getXCoord() const {
    return xCoord;
}

void MandelbrotResult::setXCoord(int xCoord) {
    this->xCoord = xCoord;
}

int MandelbrotResult::getYCoord() const {
    return yCoord;
}

void MandelbrotResult::setYCoord(int yCoord) {
    this->yCoord = yCoord;
}

int MandelbrotResult::getTotalIterations() const {
    return totalIterations;
}

void MandelbrotResult::setTotalIterations(int totalIterations) {
    this->totalIterations = totalIterations;
}
