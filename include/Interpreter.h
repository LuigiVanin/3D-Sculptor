#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <vector>
#include "GeometricFigure.h"
#include <string>

class Interpreter
{
private:
    float r, g, b, alfa;
    int dimx = 50, dimy = 50, dimz = 50;

public:
    Interpreter();

    ~Interpreter(){}

    std::vector<GeometricFigure*> compile(std::string filename);

    int getDimX();

    int getDimY();

    int getDimZ();
};

#endif // INTERPRETER_H
