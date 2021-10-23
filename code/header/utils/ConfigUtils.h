//
// Created by christopher on 2021-10-23.
//

#ifndef MANDELBROT_CONFIGUTILS_H
#define MANDELBROT_CONFIGUTILS_H

class ConfigUtils {
public:
    static int getGridWidth();

    static int getGridHeight();

    static int getMaxIterations();

    static int getBlackRBG();

    static int getRealStart();

    static int getRealEnd();

    static int getImaginaryStart();

    static int getImaginaryEnd();
};

#endif //MANDELBROT_CONFIGUTILS_H
