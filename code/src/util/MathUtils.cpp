//
// Created by christopher on 2021-10-23.
//


#include "../../header/utils/MathUtils.h"


double MathUtils::scaleValue(double value, double minValue, double maxValue, double scaleMin, double scaleMax) {
    return scaleMin + ((value - minValue) / (maxValue - minValue)) * (scaleMax - scaleMin);
}

double MathUtils::linearInterpolation(double x, double x0, double x1, double y0, double y1) {
    double rise = y0 * (x1 - x) + y1 * (x - x0);
    double run = x1 - x0;
    return rise / run;
}