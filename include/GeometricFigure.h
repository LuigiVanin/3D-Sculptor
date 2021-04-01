#ifndef GEOMETRICFIGURE_H_INCLUDED
#define GEOMETRICFIGURE_H_INCLUDED
#include "Sculptor.h"

class GeometricFigure{
protected:
    float r, g, b;
    float alfa;

public:
    GeometricFigure(){}
    virtual ~GeometricFigure(){}

    virtual void draw(Sculptor &s)=0;
};

#endif // GEOMETRICFIGURE_H_INCLUDED
