#ifndef CUTDISC_H
#define CUTDISC_H
#include "GeometricFigure.h"
#include "Sculptor.h"

class CutDisc : public GeometricFigure
{
private:
    int xc, yc, zc, radius, h, axis;

public:
    CutDisc(int xc, int yc, int zc, int radius, int h, int axis);

    ~CutDisc(){}

    void draw(Sculptor &s);

};

#endif // CUTDISC_H
