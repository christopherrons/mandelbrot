cmake_minimum_required(VERSION 3.20)
project(mandelbrot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/..bin)

add_executable(mandelbrot
        code/main.cpp
        code/src/gui/WindowHandler.cpp
        code/header/gui/WindowHandler.h
        code/src/util/ConfigUtils.cpp
        code/header/utils/ConfigUtils.h
        code/src/util/MathUtils.cpp
        code/header/utils/MathUtils.h
        code/src/mandelbrot/MandelbrotCalculator.cpp
        code/header/mandelbrot/MandelbrotCalculator.h
        code/src/mandelbrot/MandelbrotResult.cpp
        code/header/mandelbrot/MandelbrotResult.h)

target_link_libraries(mandelbrot
        -lsfml-graphics
        -lsfml-window
        -lsfml-system)
