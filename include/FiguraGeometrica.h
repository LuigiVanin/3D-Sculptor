#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include "Sculptor.h"

class FiguraGeometrica{
public:
    float r, g, b;
    float alfa;

    FiguraGeometrica();
    virtual ~FiguraGeometrica();

    virtual void draw(&Sculptor);
};

#endif // FIGURAGEOMETRICA_H_INCLUDED
